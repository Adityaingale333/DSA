class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();

        set<int> st;

        int j = 0;
        
        while(j < n){

            if(nums[j] != key){
                j++;
                continue;
            }

            for(int i=max(0, j-k); i<=min(n-1, j+k); i++){
                    st.insert(i);
            }
            
            j++;
        }

        vector<int> ans;
        for(const int& it : st){
            ans.push_back(it);
        }
        return ans;
    }
};