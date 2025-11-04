class Solution {
public:
    int findXSum(int l, int r, vector<int>& nums, int x){
        unordered_map<int, int> freq;

        for(int i=l; i<=r; i++){
            freq[nums[i]]++;
        }

        if(freq.size() < x){
            int sum = 0;
            for(int i=l; i<=r; i++){
                sum += nums[i];
            }
            return sum;
        }

        vector<pair<int,int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(), 
             [](const pair<int, int> &a, pair<int,int> &b){
                if(a.second == b.second){
                    return a.first > b.first;
                }
                return a.second > b.second;
            });

        int sum = 0;

        for(int i=0; i<x; i++){
            sum = sum + freqVec[i].first * freqVec[i].second;
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        int l=0, r = k-1;
        vector<int> ans;

        while(r < n){
            int val = findXSum(l, r, nums, x);
            ans.push_back(val);
            l++, r++;
        }

        return ans;
    }
};