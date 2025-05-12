class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        int map[10] = {0};
        vector<int> ans;

        for(int i=0 ;i<n; i++){
            map[digits[i]]++;
        }

        for(int i=1; i<=9; i++){
            if(map[i] == 0){
                continue;
            }
            map[i]--;
            for(int j=0; j<=9; j++){
                if(map[j] == 0){
                    continue;
                }
                map[j]--;
                for(int k=0; k<9; k+=2){
                    if(map[k] == 0){
                        continue;
                    }
                    map[k]--;
                    int num = (i*100) + (j*10) + k;
                    ans.push_back(num);
                    map[k]++;
                }
                map[j]++;
            }
            map[i]++;
        }
        return ans;
    }
};