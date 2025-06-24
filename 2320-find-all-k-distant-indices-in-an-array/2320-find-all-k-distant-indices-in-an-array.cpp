class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;

        for(int j=0; j<n; j++){
            if(nums[j] == key){
                int start = max(0, j-k); // to handle case of j-k becoming negative
                int end = min(n-1, j+k); // to handle case of j+k going beyond nums.size()
                if(!ans.empty() &&  ans.back() >= start){ // to handle case of duplicates
                    start = ans.back() + 1;
                }

                for(int i=start; i<=end; i++){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};