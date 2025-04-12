class Solution {
public:
// Initialize a min-heap (priority queue) to always get the next pair((i+1,j) (i,j+1)) with the smallest sum.
// Create a set to track visited index pairs (i, j) to avoid duplicates.
// Start by pushing the smallest pair (0, 0) → nums1[0] + nums2[0] into the heap.
// While k > 0 and the heap is not empty:
// Pop the top of the heap (current smallest sum).
// Add the corresponding pair (nums1[i], nums2[j]) to the result.
// Push the next two possible pairs:
// (i+1, j) → move in nums1
// (i, j+1) → move in nums2
// For each, ensure you haven’t already pushed it (check the set).
// Decrease k after each added pair.
// Return the result vector of pairs.


    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        using p = pair<int, pair<int,int>>; // {sum, {i,j}}
        priority_queue<p, vector<p>, greater<p>> minh;

        int sum = nums1[0] + nums2[0];
        set<pair<int, int>> st;   //{i,j}, to avoid pushing same pair again

        minh.push({sum, {0,0}}); // Initialize with the smallest possible pair (0, 0)
        st.insert({0,0});

        vector<vector<int>> ans;

        while(k-- && !minh.empty()){
            auto temp = minh.top();
            minh.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});

            // Try pushing the next pair (i+1, j)
            if(i+1 < n && st.find({i+1,j}) == st.end()){
                st.insert({i+1,j});
                minh.push({nums1[i+1]+nums2[j], {i+1,j}});
            }

            // Try pushing the next pair (i, j+1)
            if(j+1 < m && st.find({i,j+1}) == st.end()){
                st.insert({i,j+1});
                minh.push({nums1[i]+nums2[j+1], {i,j+1}});
            }
        }
        return ans;
    }
};