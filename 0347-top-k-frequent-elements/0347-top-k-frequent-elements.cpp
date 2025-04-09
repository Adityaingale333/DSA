class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        using pi = pair<int,int>;

        unordered_map<int, int> mp; // element -> freq
        priority_queue<pi, vector<pi>, greater<pi>> minh;

        for(auto& it:nums){
            mp[it]++;
        }

        for(auto& it:mp){
            minh.push({it.second, it.first}); //we want the heap to sort acc to freq, so freq is pushed first 
                                              // minh -> (freq, element)
            if(minh.size() > k){
                minh.pop();
            }
        }

        vector<int> ans;
        while(!minh.empty()){
            ans.push_back(minh.top().second); // element is stored in second in minh, so we push it in ans
            minh.pop();
        } 
        return ans;
    }
};