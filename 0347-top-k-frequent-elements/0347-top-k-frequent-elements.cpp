class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        using pi = pair<int,int> ;

        priority_queue<pi, vector<pi>, greater<pi>> minh;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto& it : mp){
            minh.push({it.second, it.first});

            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<int> ans;

        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }

        return ans;
    }
};