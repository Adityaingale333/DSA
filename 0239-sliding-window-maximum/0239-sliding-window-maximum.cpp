class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i=0; i<n; i++){
            // Remove indices that are out of bounds for the current window
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            // Remove indices whose corresponding values are less than nums[i]
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            // Add the current index to the deque
            dq.push_back(i);
            // Add the maximum value of the current window to the result
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};