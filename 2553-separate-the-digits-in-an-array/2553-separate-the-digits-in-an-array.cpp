class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        for(int i=0; i<n; i++){
            int temp = nums[i];
            vector<int> rev;
            while(temp){
                rev.push_back(temp % 10);
                temp = temp / 10;
            }

            for(int j=rev.size()-1; j>=0; j--){
                ans.push_back(rev[j]);
            }
        }

        return ans;
    }
};