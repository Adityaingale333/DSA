class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        unordered_map<char, int> freq; // char -> freq of that char, (count freq of characters int the string)

        for(char& ch : s){
            freq[ch]++;
        }

        vector<pair<char, int>> freqVec; // store them in a vector, to be able to sort them by values

        for(auto& it : freq){
            freqVec.push_back({it.first, it.second});
        }

        sort(freqVec.begin(), freqVec.end(), [](auto& a, auto& b){
            return a.second > b.second; // sort in decreasing order of freq of characters
        });

        string ans; // build ans string

        for(auto& it : freqVec){
            for(int i=0; i<it.second; i++){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};