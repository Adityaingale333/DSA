class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long n = nums.size();
        long long idealSum = 0; // This will store the maximum value sum we can achieve
        long long count = 0; // Count of elements where XOR with k gives a greater value
        long long minNuksan = INT_MAX;  // Minimum "loss" if we need to undo one XOR operation to make count even
        
        for(long long i=0; i<n; i++){
            long long afterXor = nums[i] ^ k; // Calculate the value after XOR with k
            if(afterXor > nums[i]){
                idealSum += afterXor; // Add the better value to idealSum
                count++; // Count how many such beneficial XORs we did
            }
            else{
                // XOR is not beneficial, so stick with original value
                idealSum = idealSum + nums[i];
            }
            // Track the "loss" if we were to forcibly take this XOR (used later if count is odd)
            minNuksan = min(minNuksan, abs(nums[i]-afterXor));
        }
        
        // If we have an odd count of XORs, means we have to take another number which will give less loss
        // require even number of XORs, we undo one of the XORs with the minimum possible reduction to idealSum
        
        if(count%2 == 1){
            idealSum = idealSum - minNuksan;
        }
        return idealSum;
    }
};