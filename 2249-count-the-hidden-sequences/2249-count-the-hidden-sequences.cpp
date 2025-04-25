class Solution {
public:
// To make all values stay in [lower, upper], we must choose x such that:
// lower ≤ x + min(prefixSums)     →     x ≥ lower - minVal
// upper ≥ x + max(prefixSums)     →     x ≤ upper - maxVal

// This gives the range of valid values for x:
// x ∈ [lower - minVal, upper - maxVal]

// The number of integers in this range is:
// (upper - maxVal) - (lower - minVal) + 1

    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;
        int minVal = 0;
        int maxVal = 0;

        for(int &it : differences){
            curr = curr + it;

            minVal = min(minVal, curr);
            maxVal = max(maxVal, curr);

            if((upper-maxVal) - (lower-minVal) + 1 <= 0){
                return 0;
            }
        }
        return (upper-maxVal) - (lower-minVal) + 1 ;
    }
};