class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        int smallest = INT_MAX;
        int largest = INT_MIN;
        vector<bool> temp(101, 0);

        for(int i=0; i<n; i++){
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
            temp[nums[i]] = 1;
        }

        vector<int> ans;
        for(int i=smallest; i<=largest; i++){
            if(!temp[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};