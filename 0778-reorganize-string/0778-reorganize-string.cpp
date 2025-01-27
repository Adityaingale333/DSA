class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26,0);

        for(int i=0; i<n; i++){
            count[s[i]-'a']++;

            if(count[s[i]-'a'] > (n+1)/2){
                return "";
            }
        }

        priority_queue<pair<int,char>> maxh;

        for(int i=0; i<26; i++){
            if(count[i] > 0){
                maxh.push({count[i], i+'a'});
            }
        }

        string ans = "";
        while(maxh.size() >= 2){
            auto ch1 = maxh.top();
            maxh.pop();
            auto ch2 = maxh.top();
            maxh.pop();

            ans.push_back(ch1.second); ch1.first--; 
            ans.push_back(ch2.second); ch2.first--;

            if(ch1.first > 0){
                maxh.push(ch1);
            }
            if(ch2.first > 0){
                maxh.push(ch2);
            }
        }
        if(!maxh.empty()){
            ans.push_back(maxh.top().second);
        }
        return ans;
    }
};