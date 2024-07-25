class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pindex = 0;
        int nindex = 1;
        vector <int> result(n,0);
        
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                result[pindex] = nums[i];
                pindex += 2;
            }
            else{
                result[nindex] = nums[i];
                nindex += 2;
            }
        }
        return result;
    }
};