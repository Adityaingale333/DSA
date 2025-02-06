class Solution {
public:
    // Use a HashMap. The key stores the product of two numbers. 
    // The value stores how many times that product appears.
    // If a product appears freq times, then we can pick any two pairs having that product in
    // (freq) * (freq-1) / 2 ways. nC2, n times appearing we want combinatio of 2.
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;

        unordered_map<int,int> map; // product, frequency
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int product = nums[i] * nums[j];
                map[product]++;
            }
        }

        for(auto& it:map){
            int prod = it.first;
            int freq = it.second;
            tuple = tuple + ( (freq)*(freq-1) )/ 2;
        }

        return tuple*8 ;
    }
};