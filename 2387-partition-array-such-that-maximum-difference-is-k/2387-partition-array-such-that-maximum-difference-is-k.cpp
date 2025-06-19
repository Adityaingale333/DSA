class Solution {
public:
    // sirf subsequences ke min or max ka kaam hai mtlb order ki importance nahi hai, sort kr skrte
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int minN = nums[0]; // first subsequence ka first element
        int count = 1; // first subsequence
        for(int i=1; i<n; i++){
            if(nums[i] - minN <= k){
                continue;
            }
            else{
                count++; // ek subsequence complete ho gaya
                minN = nums[i];
            }
        }

        return count;
    }
};