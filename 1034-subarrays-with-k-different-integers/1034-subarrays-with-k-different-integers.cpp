class Solution {
public:
    // CODE FOR <= K
    int code_for_k(vector<int>& nums, int k){
        int n = nums.size();
        int l=0, r=0;
        unordered_map<int, int> mp;
        int count = 0;

        while(r<n){
            mp[nums[r]]++;

            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    //  CODE FOR <= K-1 (j = k-1)
    int code_for_j(vector<int>& nums, int j){
        int n = nums.size();
        int l=0, r=0;
        unordered_map<int, int> mp;
        int count = 0;

        while(r<n){
            mp[nums[r]]++;

            while(mp.size() > j){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    // CODE FOR == K    -->   (CODE FOR <= K) - (CODE FOR <= K-1) 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return ( code_for_k(nums, k) ) - ( code_for_j(nums, k-1) );
    }
};