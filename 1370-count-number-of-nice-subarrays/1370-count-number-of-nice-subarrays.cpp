class Solution {
public:
    int subarrayK(vector<int>&nums, int k){      // all subarray <= k

        if(k<0)return 0;   // edge case, if ask for 0, then return 0, bcz (0-1) = -1 

        int l=0, r=0, sum=0, count=0;

        while(r<nums.size()){
            sum += nums[r]%2;       // add up all elments till less than k
                                    // mod by 2, so that if even add 0, or else 1

            while(sum>k){         // if sum exceeds k then subtract element from l
                sum -= nums[l]%2;   // mod by 2, so that if even subtract 0 or else 1  
                l++;
            }

            count += (r-l+1);   // add count of all possible subarray
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // improved the time complexity by removing this loop and using %2 in 
        // function itself while adding or subtracting

        /*for(int i=0; i<n; i++){   // convert everything to 1, 0
            if(nums[i]%2 == 0){   // after that this question is similar to binary sum  
                nums[i] = 0;      // subarray question
            }
            else{
                nums[i] = 1;
            }
        }*/

        int subarrayk = subarrayK(nums, k);  // all subarray less than equal to k
        int subarraykLessOne = subarrayK(nums, k-1);//all subarray less than equal to k-1
        int ans = subarrayk - subarraykLessOne ;
        
        return ans;
    }
};