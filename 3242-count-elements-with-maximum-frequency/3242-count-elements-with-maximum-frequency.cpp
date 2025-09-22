class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();

        int maxFreq = 0;
        vector<int> freq(101, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }

        int count = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i] == maxFreq){
                count++;
            }
        }

        return count*maxFreq;
    }
};