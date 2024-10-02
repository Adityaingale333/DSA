class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       int n = nums.size();
       int subset = 1<<n;      // Total number of subsets = 2^n 

       // Iterate over all possible subsets (from 0 to 2^n - 1)
       for(int i=0; i<=subset-1; i++){
            vector<int> result;   // Current subset

             // Check which elements are included in the current subset
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    result.push_back(nums[j]);    // If j-th bit in i is set, include nums[j] in the subset
                }
            } 
            ans.push_back(result);
        }
        return ans; 
    }
};