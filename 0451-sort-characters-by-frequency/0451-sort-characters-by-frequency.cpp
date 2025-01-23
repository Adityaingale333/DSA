class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        priority_queue<pair<int,int>> maxh;
        unordered_map<char, int> freq;

        for(auto& it : s){
            freq[it]++; //  char, freq
        } 

        for(auto& it : freq){
            maxh.push({it.second, it.first});  // freq, char
        }

        string result;
        while(!maxh.empty()){
            result.append(maxh.top().first, maxh.top().second);     // freq, char
            maxh.pop();
        }

        return result;
    }
};