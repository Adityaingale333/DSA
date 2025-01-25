class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        using pi = pair<int,int>;
        priority_queue<pair<int, pair<int,int>>> maxh;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                long long sum = nums1[i]+nums2[j];
                if(maxh.size() < k){
                    maxh.push({sum, {nums1[i], nums2[j]}});
                }
                else if(maxh.top().first > sum){
                    maxh.pop();
                    maxh.push({sum, {nums1[i], nums2[j]}});
                }
                else{
                    break; //  maxh.top().first < sum hai to matlab j ke aage ke saare elements jyada hi honge
                }
            }
        }

        vector<vector<int>> ans;
        while(!maxh.empty()){
            ans.push_back({maxh.top().second.first, maxh.top().second.second});
            maxh.pop();
        }
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};