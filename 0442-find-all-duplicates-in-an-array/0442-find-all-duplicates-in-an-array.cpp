class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();

        vector<int> result;

        for(int i=0; i<n; i++){
            int num = abs(nums[i]);// Get the absolute value of the current element.
            int index = num-1;// Determine the index corresponding to the value.

            if(nums[index] < 0){// If the value at this index is negative, it's a duplicate.
                result.push_back(num);
            }

            else{
                nums[index] *= -1; // Otherwise, negate the value at this index.
            }
        }
        return result;
        // agar koi value pehle se hi negative hai to mtlb vo no. pehle bhi aa chuka hai
    }   // isiliye uss index pr vapas gaye
};