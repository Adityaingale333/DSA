class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            string s = to_string(nums[i]);
            if(s.length()%2 == 0){
                count++;
            }
        }
        return count;
    }
};