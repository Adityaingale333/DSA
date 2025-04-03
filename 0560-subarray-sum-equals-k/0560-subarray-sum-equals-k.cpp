class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; // cummSum -> count(how many times i have seen that sum)
        int sum = 0;
        int count = 0;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];

            int rem_sum = sum - k;
            if(mp.find(rem_sum) != mp.end()){
                count += mp[rem_sum];
            }

            mp[sum]++;
        }
        return count;
    }
};