class Solution {
public:
    string solve(string& word){
        string temp = "";
        for(int i=0; i<word.size(); i++){
            int chidx = word[i] - 'a';
            if(chidx == 25){
                temp.push_back('a');
            }
            else{
                temp.push_back((chidx + 1) + 'a');
            }
        }

        return word + temp;
    }
    char kthCharacter(int k) {
        string word = "a";

        while(word.size() < k){
            word = solve(word);
        }

        return word[k-1];
    }
};