class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<int,int>> vec; // index, element

        for(int i=0; i<n; i++){
            vec.push_back({i, nums[i]});        
        }

        auto lambda = [](auto& p1, auto& p2){
            return p1.second > p2.second; // descending order of element value
        };

        sort(vec.begin(), vec.end(), lambda);

        sort(vec.begin(), vec.begin() + k); // sort in ascending index

        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};