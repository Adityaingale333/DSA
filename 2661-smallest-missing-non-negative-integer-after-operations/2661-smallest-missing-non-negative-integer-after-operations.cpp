class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        unordered_map<int, int> mp; // nums[i] % value -> freq

        for(int i=0; i<n; i++){
            int temp = ((nums[i] % value) + value) % value;
            mp[temp]++;
        }

        int i=0;
        while(mp[i % value] > 0){
            mp[i % value]--;
            i++;
        }

        return i;
    }
};