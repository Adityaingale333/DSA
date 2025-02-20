class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string ans;

        // we are discarding element one by one, we check for the 0th bit of 0th element
        // and flip it so that it is discarded and then similarly for others  
        for(int i=0; i<n; i++){
            char ch = nums[i][i];

            ans.push_back( ch == '0' ? '1' : '0' );
        }

        return ans;
    }
};