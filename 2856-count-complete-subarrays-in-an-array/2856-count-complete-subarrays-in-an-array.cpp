class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        //Find the total number of distinct elements in the entire array
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int c = st.size();
        unordered_map<int,int> mp; // nums[i] -> frequency
        int i = 0;
        int j = 0;
        int count = 0;
        
        //Use sliding window to find all subarrays that contain all distinct elements
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() == c){
            // All subarrays starting from i and ending anywhere from j to n-1 are valid
            // Because extending the subarray beyond j won’t lose any of the distinct elements
                count = count + n-j;
            //Shrink window from the left
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]); // Remove element if frequency becomes 0
                }
                i++;
            }
            j++;
        }
        return count;
    }
};