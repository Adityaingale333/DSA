class Solution {
public:
    vector<int> get_NGEER(vector<int>& nums){
        int n = nums.size();

        stack<int> st;

        vector<int> ngee(n, -1); // iterate from right, decreasing stack
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty()){
                ngee[i] = i;
            }
            else{
                ngee[i] = st.top();
            }

            st.push(i);
        }

        return ngee;
    }

    vector<int> get_PGEEL(vector<int>& nums){
        int n = nums.size();

        stack<int> st;

        vector<int> pgee(n, -1); // iterate from left, decreasing stack
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty()){
                pgee[i] = i;
            }
            else{
                pgee[i] = st.top();
            }

            st.push(i);
        }

        return pgee;
    }
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ngee = get_NGEER(nums);
        vector<int> pgee = get_PGEEL(nums);

        long long ans = 0;
        for(int i=0; i<n; i++){
            if(ngee[i] != -1 && ngee[i] > i+1){
                ans++;
            }

            if(pgee[i] != -1 && nums[pgee[i]] != nums[i] && pgee[i] < i-1){
                ans++;
            }
        }

        return ans;
    }
};