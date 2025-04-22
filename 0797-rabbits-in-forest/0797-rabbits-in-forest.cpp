class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp; // answer -> kitne rabbit ne diya

        for(int &x: answers){
            mp[x]++;
        }

        int total = 0;

        for(auto &it: mp){
            int x = it.first; // answer
            int count = it.second; // kitne logo ne diya

            int groupSize = x+1;
            int group = ceil((double)count/groupSize);

            total = total + (group*groupSize);
        }
        return total;
    }
};