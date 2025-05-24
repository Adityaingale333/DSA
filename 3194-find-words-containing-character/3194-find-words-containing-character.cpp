class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            string temp = words[i];
            if(temp.contains(x)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};