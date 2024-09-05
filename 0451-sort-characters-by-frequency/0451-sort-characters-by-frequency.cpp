class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        unordered_map<char, int> freq;

        for(auto ch : s){
            freq[ch]++;
        }

        vector<pair<int, char>> freqVec;

        for(auto num : freq){
            freqVec.push_back({num.second, num.first});
        }

        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>() );

        string result;
        for(auto ch : freqVec){
            result.append(ch.first, ch.second);
        }

        return result;
    }
};