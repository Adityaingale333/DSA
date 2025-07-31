class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp; // integers -> frequency

        int i=0, j=0;
        int i_bada = 0;

        int ans = 0;

        while(j < n){
            mp[nums[j]]++;

            // handle invalid subarray cases, shrink the window, and also reset i_bada to i
            while(mp.size() > k){
                mp[nums[i]]--;
                
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                
                i++;
                i_bada = i;
            }

            // handle valid subarray cases, look for how many more subaray are valid
            while(mp[nums[i]] > 1){
                mp[nums[i]]--;
                i++;
            }

            if(mp.size() == k){
                ans = ans + (1 + (i - i_bada));
            }

            j++;
        }

        return ans;
    }
};