class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int p){
        int n = nums.size();

        int i = 0;
        int countPairs = 0;

        while(i < n-1){
            if(nums[i+1] - nums[i] <= mid){ // we want 'p' pair to be less than mid, so that we can return it as ans 
                countPairs++; // we found a pair
                i = i+2; // we found a pair, so we are skipping these two elements
            }
            else{
                i = i+1; // we could not find a pair, so we skip only this number and try pair with next number
            }
        }
        return countPairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums[n-1] - nums[0];

        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(isValid(mid, nums, p)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};