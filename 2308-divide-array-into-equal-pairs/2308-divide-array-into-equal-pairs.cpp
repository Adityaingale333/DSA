class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto& it : nums){
            mp[it]++;
        }

        for(int i=0; i<mp.size(); i++){
            if(mp[i]%2 != 0){
                return false;
            }
        }
        return true;
    }
};