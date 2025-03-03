class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        // nums variable
        int i = 0;
        int j = n-1;

        // result variable
        int i_ = 0;
        int j_ = n-1;

        vector<int> ans(n);

        while(i<n && j>=0){
            if(nums[i] < pivot){
                ans[i_] = nums[i];
                i_++;
            }
            if(nums[j] > pivot){
                ans[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        while(i_ <= j_){
            ans[i_] = pivot;
            i_++;
        }
        return ans;
    }
};