class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> cumXor(arr.size(), 0);
        cumXor[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            cumXor[i] = cumXor[i-1] ^ arr[i];
        }

        vector<int> result;

        for(int i=0; i<queries.size(); i++){
            int L = queries[i][0];
            int R = queries[i][1] ;
            
            if(L == 0){
                result.push_back(cumXor[R]);
            }
            else{
                result.push_back(cumXor[L-1] ^ cumXor[R]);
            }
        }
        return result;
    }
};