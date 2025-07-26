class Solution {
public:
    // we can make it into two questions, sum of subarray maximum - sum of subarray minimum

    // to get subarray maximum, we must know the next max value, and the prev max value
    // once we know the next greater and prev greater value, then we can get the number of subarrays in which the curr element is max
    // then we can count its contribution -> suppose left = i - pge and right = nge - i, then (left * right) * val 
    long long sumOfSubarrayMaximum(vector<int>& nums){
        int n = nums.size();

        stack<int> st; // decreasing stack, iterating from right
        vector<int> NGE(n); // next greater element

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }

            if(st.empty()){
                NGE[i] = n;
            }
            else{
                NGE[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> PGEE(n); // previous greater and equal element 

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                PGEE[i] = -1;
            }
            else{
                PGEE[i] = st.top();
            }

            st.push(i);
        }

        long long sum = 0;
        for(int i=0; i<n; i++){
            long long left = i - PGEE[i];
            long long right = NGE[i] - i;

            long long totalSubarray = left * right ;

            long long totalSum = totalSubarray * nums[i];

            sum = sum + totalSum;
        }

        return sum;
    }

    long long sumOfSubarrayMinimum(vector<int>& nums){
        int n = nums.size();

        stack<int> st; // increasing stack, iterating from right
        vector<int> NSE(n); // next smaller element

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }

            if(st.empty()){
                NSE[i] = n;
            }
            else{
                NSE[i] = st.top();
            }

            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> PSEE(n); // previous smaller and equal element 

        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }

            if(st.empty()){
                PSEE[i] = -1;
            }
            else{
                PSEE[i] = st.top();
            }

            st.push(i);
        }

        long long sum = 0;
        for(int i=0; i<n; i++){
            long long left = i - PSEE[i];
            long long right = NSE[i] - i;

            long long totalSubarray = left * right ;

            long long totalSum = totalSubarray * nums[i];

            sum = sum + totalSum;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        return sumOfSubarrayMaximum(nums) - sumOfSubarrayMinimum(nums) ;
    }
};