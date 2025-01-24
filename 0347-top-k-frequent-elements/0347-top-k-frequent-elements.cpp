class Solution {
public:
    //               BUCKET SORT
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        for(auto& it : nums){
            mp[it]++;
        }

        vector<vector<int>> bucket(n+1);
        // index = frequency
        // value = elements
        // bucket[i] = elements having (i) frequency
        for(auto& it : mp){
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        // result
        vector<int> ans;
        // pick element from right to left
        for(int i=n; i>=0; i--){
            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};