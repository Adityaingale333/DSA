class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;

        for(int i=0; i<n; i++){
            if(i % 2){
                odd.push_back(nums[i]);
            }
            else{
                even.push_back(nums[i]);
            }
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());

        vector<int> ans(n);
        int oddIdx  = 0, evenIdx  = 0;
        for(int i=0; i<n; i++){
            if(i % 2){
                ans[i] = odd[oddIdx ];
                oddIdx ++;
            }
            else{
                ans[i] = even[evenIdx ];
                evenIdx ++;
            }
        }
        return ans;
    }
};