class Solution {
public:
    // O(2^n) recursion, generate all subsequences
   /* void solve(int i, int m, vector<long long>& temp, vector<int>& nums){
        if(m == 0){
            maxAns = max(maxAns, temp[0]*temp[temp.size()-1]);
            return;
        }
        if(i<0 && m>0){
            return ;
        }

        temp.push_back(nums[i]);
        solve(i-1, m-1, temp, nums);
        temp.pop_back();

        solve(i-1, m, temp, nums);
    }*/

    // O(n^2) sliding window to generate subsequences of window m
     /*int n = nums.size();
        long long maxAns = LLONG_MIN;

        if(m == 1){
            for(int i=0; i<n; i++){
                maxAns = max(maxAns, (long long)nums[i]*nums[i]);
            }  
            return maxAns;
        }
        
        
        for(int i=0; i<=n-m; i++){
            maxAns = max(maxAns, (long long)nums[i]*nums[j]);
        }
        
        return maxAns;*/

    // O(n) solution, here we only want to keep track of first and last element
    // our ans will we product of 1st and last, so we only need to keep track of those
    // we need to maintain a subsequence of size m, so for that we will start our loop from the 1st possible ending index
    // j = m-1, bcz we need at lest m size, and then we keep track of min and max (i), bcz we have both +ve and -ve numbers
    // so they both can yeild max product, and then we go to next j and calculate ans
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long minI = LLONG_MAX;
        long long maxI = LLONG_MIN;
        long long ans = LLONG_MIN;

        for(int j=m-1; j<n; j++){
            int i = j-m+1; // using length formula, j-i+1 = m --> i = j-m+1
            minI = min(minI, (long long)nums[i]);
            maxI = max(maxI, (long long)nums[i]);
            ans = max(ans, minI*(long long)nums[j]);
            ans = max(ans, maxI*(long long)nums[j]);
        }
        return ans;
    }
};