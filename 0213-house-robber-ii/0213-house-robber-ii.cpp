class Solution {
public:
    int solve(int start, int end, vector<int>& nums,  vector<int>& t){
        int len = end - start + 1; // total houses we are considering, n houses
        t[0] = 0; // after robbing 0 house
        t[1] = nums[start]; // after robbing only startting house

        for(int i=2; i<=len; i++){ // end+1 -> if n elements then total n+1 index, n-2 elements -> end+1 -> n-1 index
            int pick = nums[start + i - 1] + t[i-2]; // start is added to take account of correct house
            int skip = t[i-1];
            t[i] = max(pick, skip);
        }
        return t[len];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> t1(n+1, 0);
        vector<int> t2(n+1, 0);

        int takeZero = solve(0, n-2, nums, t1); // we rob house no.(0) means we can not rob last(n-1) house, rob (n-2) house
        int skipZero = solve(1, n-1, nums, t2); // we skip house no.(0) means we can rob the last house 

        return max(takeZero, skipZero);
    }
};