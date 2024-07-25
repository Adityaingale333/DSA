class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int maj1 = INT_MIN;
        int maj2 = INT_MIN;

        for(int i=0; i<n; i++){
            if(count1==0 && nums[i]!=maj2){  // if its new number and count1 is zero
                maj1 = nums[i];           // assign maj1 to number and count1 = 1
                count1 = 1;
            }
            else if(count2==0 && nums[i]!=maj1){// if its new number and count2 is zero
                maj2 = nums[i];         //assign maj2 to number and count2 = 1
                count2 = 1;
            }
            else if(nums[i] == maj1){  // if its equal to maj1, increase count1
                count1++;
            }
            else if(nums[i] == maj2){  // if its equal to maj2, increase count2
                count2++;
            }
            else{                      // else decrease both the counts
                count1--;
                count2--;
            }
        }

        // verification
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maj1) count1++;
            else if(nums[i] == maj2) count2++;
        }

        vector<int> result;
        if(count1 > n/3) result.push_back(maj1);
        if(count2 > n/3) result.push_back(maj2);

        return result;
    }
};