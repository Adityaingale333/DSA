class Solution {
public:
    long long solve(int i, vector<long long>& nums, unordered_map<long long, long long>& mp, vector<int>& t){
        if(i >= nums.size()){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        long long notTake = solve(i+1, nums, mp, t);


        int j = lower_bound(nums.begin()+i+1, nums.end(), nums[i]+3) - nums.begin();

        long long take = nums[i] * mp[nums[i]] + solve(j, nums, mp, t);

        return t[i] = max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> mp;
        for(int i=0; i<power.size(); i++){
            mp[power[i]]++;
        }

        vector<long long> nums(mp.size());
        for(auto& it : mp){
            nums.push_back(it.first);
        }

        sort(nums.begin(), nums.end());

        vector<int> t(nums.size(), -1);

        return solve(0, nums, mp, t);
    }
};