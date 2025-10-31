class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int& num : nums){
            mp[num]++;
            if(mp[num] > 1){
                ans.push_back(num);
            }
        }

        return ans;
    }
};