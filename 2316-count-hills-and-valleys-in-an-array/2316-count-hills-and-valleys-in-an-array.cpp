class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int j = 0;

        int countHill = 0;
        int countValley = 0;
        
        for(int i=1; i<n-1; i++){
            if(nums[j] < nums[i] && nums[i] > nums[i+1]){
                countHill++;
                j = i;
            }
            else if(nums[j] > nums[i] && nums[i] < nums[i+1]){
                countValley++;
                j = i;
            }
        }

        return countHill + countValley;
    }
};