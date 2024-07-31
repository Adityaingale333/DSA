class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        while (low <= high) {
            int mid = low + ((high - low) / 2);
            if (mid > 0 && mid < n - 1) {
                if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid] > nums[mid - 1]) {
                    low =
                        mid +
                        1; // bada element jis side hai uss side hi peak milega
                           // slope upward hai isliye low ko right side le gaye
                } else {
                    high = mid - 1; // slope downward hai isilye high ko left
                                    // side le gaye
                }
            } else if (mid == 0) {
                return mid + 1;
            } else {
                return mid - 1;
            }
        }
        return -1;
    }
};