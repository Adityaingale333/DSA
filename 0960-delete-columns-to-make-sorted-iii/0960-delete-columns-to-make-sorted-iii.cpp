class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].length();

        vector<int> t(cols, 1);

        int lis = 1;

        for(int i=0; i<cols; i++){
            for(int j=0; j<i; j++){
                bool valid = true;
                for(int k=0; k<rows; k++){
                    if(strs[k][j] > strs[k][i]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    t[i] = max(t[i], t[j] + 1);
                }
            }
            lis = max(lis, t[i]);
        }
        
        return cols - lis;
    }
};