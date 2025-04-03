class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp; // cummSum -> index

        mp[0] = -1;

        int length = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                sum += -1;
            }
            else{
                sum += 1;
            }

            if(mp.find(sum) != mp.end() || mp.empty()){
                length = max(length, i - mp[sum]);
            }
            else{ // we are using else bcz we want the leftmost index to get the longest subarray
                  // if we update it every time then we will get latest index we ssaw the sum
                mp[sum] = i;
            }
        }
        return length;
    }
};