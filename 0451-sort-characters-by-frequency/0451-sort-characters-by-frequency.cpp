class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        priority_queue<pair<int, char>> maxh; // {freq, char}
        unordered_map<char, int> freq; // char -> freq

        for(auto& it:s){
            freq[it]++;
        }

        for(auto& it:freq){
            maxh.push({it.second, it.first});
        }

        string result;
        while(!maxh.empty()){
            result.append(maxh.top().first, maxh.top().second); // result.append(no of times, char)
            maxh.pop();
        }
        return result;
    }
};