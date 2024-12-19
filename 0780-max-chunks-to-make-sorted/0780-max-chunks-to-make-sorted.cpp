class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int n = arr.size();
       vector<int> prefixMax(begin(arr), end(arr));
       vector<int> suffixMin(begin(arr), end(arr));

       for(int i=1; i<n; i++){
        prefixMax[i] = max(prefixMax[i-1], prefixMax[i]);
       }

       for(int i=n-2; i>=0; i--){
        suffixMin[i] = min(suffixMin[i], suffixMin[i+1]);
       }

        int count = 0;
       for(int i=0; i<n; i++){
         int pehlekamax = i>0?prefixMax[i-1]:-1 ;
         int baadkamin = suffixMin[i];

         if(pehlekamax < baadkamin) count++;
        }
        return count;
    }
};