class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        long long sum1 = 0;
        long long sum2 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i=0; i<m; i++){
            sum1 += nums1[i];
            if(nums1[i] == 0){
                count1++;
                sum1 += 1;
            }
        }

        for(int i=0; i<n; i++){
            sum2 += nums2[i];
            if(nums2[i] == 0){
                count2++;
                sum2 += 1;
            }
        }
        if(sum1 < sum2 && count1==0){
            return -1;
        }
        if(sum2 < sum1 && count2==0){
            return -1;
        }

        return max(sum1, sum2);
    }
};