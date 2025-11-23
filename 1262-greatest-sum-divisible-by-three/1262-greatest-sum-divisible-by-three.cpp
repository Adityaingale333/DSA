class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        vector<int> r1;
        vector<int> r2;

        for(int i=0; i<n; i++){
            total += nums[i];
            if(nums[i] % 3 == 1){
                r1.push_back(nums[i]);
            }
            else if(nums[i] % 3 == 2){
                r2.push_back(nums[i]);
            }
        }

        if(total % 3 == 0){
            return total;
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        int remove1 = INT_MAX;
        int remove2 = INT_MAX;

        if(total % 3 == 1){
            if(!r1.empty()){
                remove1 = r1[0];
            }
            if(r2.size() >= 2){
                remove2 = r2[0] + r2[1];
            }
        }
        else{
            if(!r2.empty()){
                remove1 = r2[0];
            }
            if(r1.size() >= 2){
                remove2 = r1[0] + r1[1];
            }
        }

        if(min(remove1, remove2) == INT_MAX) return 0;

        return total - min(remove1, remove2);
    }
};