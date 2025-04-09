class Solution {
public:

// Use a map (which is always sorted) to always start grouping from the smallest available card.
// For each group of size groupSize, check that all consecutive numbers curr, curr+1, ..., curr+groupSize-1 exist.
// If any card is missing during a group build, return false.
// Remove cards as you use them. If all can be grouped, return true.

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        
        if(n % groupSize != 0) return false;

        map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[hand[i]]++;
        }

        while(!freq.empty()){
            int curr = freq.begin() -> first;

            for(int i=0; i<groupSize; i++){
                if(freq[curr + i] == 0){
                    return false;
                }

                freq[curr + i]--;
                if(freq[curr + i] == 0){
                    freq.erase(curr + i);
                }
            }
        }
        return true;
    }
};