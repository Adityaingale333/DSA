class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }

        int left = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            left += nums[i];
            if(nums[i] == 0 && left == total - left){
                ans = ans + 2;
            }
            else if(nums[i] == 0 && (left+1 == total-left || left-1 == total-left)){
                ans++;
            }
        }

        return ans;
    }
};