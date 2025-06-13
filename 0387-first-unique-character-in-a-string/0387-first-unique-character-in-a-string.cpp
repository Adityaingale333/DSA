class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        queue<int> uniqueIdx;

        for(int i=0; i<n; i++){
            if(freq.find(s[i]) == freq.end()){
                uniqueIdx.push(i);
            }

            freq[s[i]]++;

            while(!uniqueIdx.empty() && freq[s[uniqueIdx.front()]] > 1){
                uniqueIdx.pop();
            }
        }
        return uniqueIdx.empty() ? -1 : uniqueIdx.front();
    }
};