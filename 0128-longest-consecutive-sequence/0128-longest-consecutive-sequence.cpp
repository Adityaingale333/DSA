class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;

        unordered_set<int> st; 

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int ans = INT_MIN;
        for(auto& it : st){
            if(st.find(it-1) == st.end()){
                int first = it;
                int count = 1;
                while(st.find(first + 1) != st.end()){
                    first = first + 1;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};