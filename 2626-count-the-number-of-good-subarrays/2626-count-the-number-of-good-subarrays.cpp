class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int l = 0;
        int r = 0;
        long long count = 0;
        long long ans = 0;

        while(r < n){
            count = count + freq[nums[r]];
            freq[nums[r]]++;
                            // *** IMPORTANT POINT ***
// Ek good subarray milne ke baad jitne bhi elements bache hai unn sabko add krne pr aur good 
// subarray milenge, isliye ans me (n - r) add kr rhe hai
// [3,1,4,3,2,2,4,7,1,3] -> 1st good subarray [3,1,4,3,2,2], ab iske baad ke elements ko add krne pr
// aur subarray milenge. -> [3,1,4,3,2,2,4] -> [3,1,4,3,2,2,4,7] -> [3,1,4,3,2,2,4,7,1] -> [3,1,4,3,2,2,4,7,1,3]
            while(count >= k){
                ans = ans + n - r; 
                freq[nums[l]]--;
                count = count - freq[nums[l]];
                l++;
            } 
            r++;
        }
        return ans;
    }
};