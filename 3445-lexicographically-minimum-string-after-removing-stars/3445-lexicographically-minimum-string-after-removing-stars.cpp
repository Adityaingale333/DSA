class Solution {
public:
    typedef pair<char,int> P; 
    struct comp{
        bool operator()(P &p1, P &p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        int n = s.size();
        priority_queue<P, vector<P>, comp> minh;

        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                minh.push({s[i], i});
            }
            else{
                int idx = minh.top().second;
                minh.pop();
                s[idx] = '*';
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(s[i] != '*'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};