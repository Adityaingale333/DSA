class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        int maxFreq = 0;
        int count = 0;
        vector<int> freq(101, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > maxFreq){
                count = 1;
                maxFreq = freq[nums[i]];
            }
            else if(freq[nums[i]] == maxFreq){
                count++;
            }
        }

        return count*maxFreq;
    }
};