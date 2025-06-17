class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int> odd;
        priority_queue<int, vector<int>, greater<int>> even;

        for(int i=0; i<n; i++){
            if(i % 2 == 1){
                odd.push(nums[i]);
            }
            else{
                even.push(nums[i]);
            }
        }

        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(i % 2 == 1){
                ans[i] = odd.top();
                odd.pop();
            }
            else{
                ans[i] = even.top();
                even.pop();
            }
        }
        return ans;
    }
};