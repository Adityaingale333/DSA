class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <int, vector<int>, greater<int>> minh(nums.begin(), nums.begin()+k);

        for(int i=k; i<n; i++){
            if(minh.top() < nums[i]){
                minh.pop();
                minh.push(nums[i]);
            }
        }

        return minh.top();
    }
};