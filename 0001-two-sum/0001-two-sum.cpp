class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            int sum = nums[i];
            int req_sum = target - sum;

            if(mp.find(req_sum) != mp.end()){
                return {i,mp[req_sum]} ;
            }
            else{
                mp[sum] = i;
            }
        }
        return {-1,-1};
    }
};