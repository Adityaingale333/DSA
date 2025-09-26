class Solution {
public:
    int bs(int low, int high, vector<int>& nums, int sum){
        int idx = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < sum){
                idx = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return idx;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();

        if(n < 3){
            return 0;
        }

        sort(nums.begin(), nums.end());

        int ans = 0;

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                int sum = nums[i] + nums[j];

                int idx = bs(j+1, n-1, nums, sum);

                if(idx != -1) ans = ans + (idx-j);
            }
        }

        return ans;
    }
};