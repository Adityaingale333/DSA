class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end()); // sorting is necessary so to check divisibility

        vector<int> t(n, 1);
        vector<int> prevIdx(n, -1);

        int maxLenIdx = 0;
        int maxLen = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){

                    if(t[j]+1 > t[i]){
                        t[i] = t[j]+1;
                        prevIdx[i] = j; // thi is required to print LIS, bcz we will have to go back to back
                    }

                    if(t[i] > maxLen){
                        maxLen = t[i];
                        maxLenIdx = i;
                    }
                }
            }
        }
        vector<int> ans;
        while(maxLenIdx != -1){
            ans.push_back(nums[maxLenIdx]);
            maxLenIdx = prevIdx[maxLenIdx];
        }
        return ans;
    }
};