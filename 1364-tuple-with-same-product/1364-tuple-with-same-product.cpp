class Solution {
public:
    // if a*b == c*d then either a or b has to be smaller or bigger than c and d
    // it is not possible that both a and b are smaller or larger than c and d
    // so we sort the array and then put i at start ang j at end and then take,
    // k=i+1 and then find the value of d and check in set if we can find the pair 
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                int product = nums[i] * nums[j];
                unordered_set<int> st;
                for(int k=i+1; k<j; k++){
                    if(product % nums[k] == 0){
                        int dvalue = product/nums[k];
                        if(st.count(dvalue)){
                            tuple++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return tuple*8 ;
    }
};