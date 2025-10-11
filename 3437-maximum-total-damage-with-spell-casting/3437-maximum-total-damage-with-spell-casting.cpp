class Solution {
public:
    // long long solve(int i, vector<long long>& nums, unordered_map<long long, long long>& mp, vector<long long>& t){
    //     if(i >= nums.size()){
    //         return 0;
    //     }

    //     if(t[i] != -1){
    //         return t[i];
    //     }

    //     long long notTake = solve(i+1, nums, mp, t);


    //     int j = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

    //     long long take = nums[i] * mp[nums[i]] + solve(j, nums, mp, t);

    //     return t[i] = max(take, notTake);
    // }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> mp;
        for(int i=0; i<power.size(); i++){
            mp[power[i]]++;
        }

        vector<long long> nums;
        for(auto& it : mp){
            nums.push_back(it.first);
        }

        sort(nums.begin(), nums.end());

        vector<long long> t(nums.size(), 0);
        long long ans = 0;

        for(int i=nums.size()-1; i>=0; i--){
            long long notTake = 0;
            if(i+1 < nums.size()) notTake = t[i+1];

            int j = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

            long long take = nums[i] * mp[nums[i]] + (j<nums.size() ? t[j] : 0);

            t[i] = max(take, notTake);

            ans = max(ans, t[i]);
        }

        return ans;
    }
};