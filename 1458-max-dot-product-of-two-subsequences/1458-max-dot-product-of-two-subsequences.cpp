class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& t){
        if(i == nums1.size() || j == nums2.size()){
            return -1e9;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        int val = nums1[i] * nums2[j];
        int both = (nums1[i] * nums2[j]) + solve(nums1, nums2, i+1, j+1, t);
        int takei = solve(nums1, nums2, i, j+1, t);
        int takej = solve(nums1, nums2, i+1, j, t);

        return t[i][j] = max({val, both, takei, takej});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> t(m, vector<int>(n, -1));

        return solve(nums1, nums2, 0, 0, t);
    }
};