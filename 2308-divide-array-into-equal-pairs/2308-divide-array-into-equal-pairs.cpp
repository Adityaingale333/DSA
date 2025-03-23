class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();

        vector<bool> paired(501, true);
        for(auto& it : nums){
            paired[it] = !paired[it];
        }

        for(int i=0; i<501; i++){
            if(paired[i] == false){
                return false;
            }
        }
        return true;
    }
};