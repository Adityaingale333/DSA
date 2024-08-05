class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        // Count frequencies
        unordered_map<char, int> freq;

        for (auto c : s) {
            freq[c]++;
        }

        //tranfer frequency to vector pair, because we need to sort frequency in descending order

        vector<pair<int, char>> freqVec; // int ko char ke pehle isliye liya kyuki descending me krna tha
                                         // using first element easy hai, compared to second element

        for (auto num : freq) {
            freqVec.push_back({num.second, num.first});
        }

        //***NEW FUNCTION GREATER IS USED TO SORT IN DESCENDING ORDER***
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

        // construct result
        string result;

        for (auto c : freqVec) {
            result.append(c.first, c.second);// pehla paramter frequency hai, dusra character
                                             // ex : (3,a) "aaa" 
        }
        return result;
    }
};