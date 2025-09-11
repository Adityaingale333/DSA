class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        int maxVal = -1;

        vector<int> prefixGreater(n, 0);
        for(int i=0; i<n; i++){
            if(maxVal > nums[i]){
                prefixGreater[i] = 1;
            }
            maxVal = max(nums[i], maxVal);
        }

        maxVal = -1;

        vector<int> suffixGreater(n, 0);
        for(int i=n-1; i>=0; i--){
            if(maxVal > nums[i]){
                suffixGreater[i] = 1;
            }
            maxVal = max(nums[i], maxVal);
        }
        
        long long count = 0;

        for(int i=0; i<n; i++){
            if(prefixGreater[i] && suffixGreater[i]){
                count++;
            }
        }

        return count;
    }
};