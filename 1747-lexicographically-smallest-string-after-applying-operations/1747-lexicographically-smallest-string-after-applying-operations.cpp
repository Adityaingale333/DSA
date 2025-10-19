class Solution {
public:
    void rotate(string& s, int k){
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
    }

    string findLexSmallestString(string s, int a, int b) {
        string smallest = s;

        queue<string> q;
        q.push(s);

        unordered_set<string> visited;
        visited.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < smallest){
                smallest = curr;
            }

            string temp = curr;
            for(int i=1; i<curr.size(); i+=2){
                temp[i] = ((temp[i]-'0' + a) % 10 ) + '0';
            }
            if(!visited.count(temp)){
                q.push(temp);
                visited.insert(temp);
            }

            rotate(curr, b);
            if(!visited.count(curr)){
                q.push(curr);
                visited.insert(curr);
            }
        }

        return smallest;
    }
};