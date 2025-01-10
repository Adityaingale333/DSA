class Solution {
public:
    bool is_Subset(vector<int>& freq2, vector<int>& temp){
        for(int i=0; i<freq2.size(); i++){
            if(freq2[i] > temp[i]) return false;
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();

        vector<int> freq2(26);

        for(string &word: words2){
            int temp[26] = {0};
            for(char &ch: word){
                temp[ch-'a']++;
                freq2[ch-'a'] = max(freq2[ch-'a'], temp[ch-'a']);
            }
        }

        vector<string> ans;
        for(string &word: words1){
            vector<int> temp(26,0);

            for(char &ch: word){
                temp[ch-'a']++;
            }

            if(is_Subset(freq2, temp) == true){
                ans.push_back(word);
            }
        }
        return ans;
    }
};