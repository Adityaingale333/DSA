class Solution {
public:
    /*Let's see this with an example : 
    nums = {2, 1}, k = 1
    we have two subarrays having oddCount --> {2, 1}, {1}
    COUNT_NICE_SUBARRAY = 2

    Now, suppose we have one more integer 2 . our array looks like --> {2, 1, 2}, k = 1
    If you see, addition of this extra 2 will not impact the oddCount because this 2 is even.
    So, we again get two more subarrays by including this 2 with previous two nice subarrays {2, 1} and {1}
    so we get {2, 1, 2}, {1, 2}
    So, over all Nice subarrays becomes - {2, 1}, {1}, {2, 1, 2}, {1, 2}
    Now, COUNT_NICE_SUBARRAY = 4


    Now, let's take one more example : Let's say the one more integer after {2, 1} is 1
    So, our array becomes -> {2, 1, 1}
    Let's break it again -> from {2, 1} we had {2, 1}, {1} i.e. COUNT_NICE_SUBARRAY = 2

    Now, when 1 comes, this is another Odd number so oddCount is affacted and hence we can't add previousCount = 2 to our result because {2, 1, 1} doesn't have k = 1 odd numbers. It has 2 odd numbers.
    So, we need to start from fresh and hence prevCount is made 0.
    Now, the new subarray having k = 1 oddCount is the {1} 
    so we got one nice subarray now.
    COUNT_NICE_SUBARRAY = 2 + 1 = 3 */

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int prevCount = 0;
        int ans = 0;

        int l=0, r=0;

        while(r < n){
            if(nums[r] % 2 == 1){
                oddCount++;
                prevCount = 0;
            }

            while(oddCount == k){
                prevCount++;

                if(r < n && nums[l] % 2 == 1){
                    oddCount--;
                }
                l++;
            }

            ans = ans + prevCount;
            r++;
        }

        return ans;
    }
};