class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int m = nums1.size(); // m rows in nums1
        int n = nums2.size(); // n rows in nums2

        int i=0; int j=0;

        vector<vector<int>> ans;

        while(i<m && j<n){
            if(nums1[i][0] == nums2[j][0]){
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++, j++;
            }
            else if(nums1[i][0] < nums2[j][0]){
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else{
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

// only one of these two loops written below will run, when there is case of one array containing more ids
        while(i<m){
            ans.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        while(j<n){
            ans.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return ans;
    }
};