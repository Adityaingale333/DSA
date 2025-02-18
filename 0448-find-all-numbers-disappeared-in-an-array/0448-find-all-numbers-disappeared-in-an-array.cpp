class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n+1, 0);
        vector<int> result;

        for(int i=0; i<n; i++){
            ans[nums[i]] = 1;
        }

        for(int i=1; i<=n; i++){
            if(ans[i] != 1){
                result.push_back(i);
            }
        }
        return result;
    }
};