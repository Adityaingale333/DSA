class Solution {
public:
    // we will have to find the contributions a element makes 
    // a element will make contributions if it is smaller in the subarray
    // to get the number of subarray it is smaller in, we will have to find NSER and NSEL
    // to calculate number of subarrays it will be smaller in, we can do NSER[i] - i ans i - NSEL[i]

    // EDGE CASE -> there can be duplicate subarrays, so to avoid it we will have to consider either N-SE-ER or N-SE-EL, any one of them 
    // here in this code we will consider N-SE-R and N-SE-EL
    vector<int> getNSER(vector<int>& arr){
        int n = arr.size();

        stack<int> st; // increasing stack, iterating from right

        vector<int> NSER(n);

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            if(st.empty()){
                NSER[i] = n; // if there is no NSER, store n
            }
            else{
                NSER[i] = st.top();
            }

            st.push(i);
        }

        return NSER;
    }
    vector<int> getN_SE_EL(vector<int>& arr){
        int n = arr.size();

        stack<int> st; // increasing stack, iterating from left

        vector<int> N_SE_EL(n);

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){ // to also consider next equal element to left
                st.pop();
            }

            if(st.empty()){
                N_SE_EL[i] = -1; // if there is no NSER, store n
            }
            else{
                N_SE_EL[i] = st.top();
            }

            st.push(i);
        }

        return N_SE_EL;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSER = getNSER(arr);
        vector<int> N_SE_EL = getN_SE_EL(arr);

        long long ans = 0;
        int M = 1e9 + 7;

        for(int i=0; i<n; i++){
            long long left = N_SE_EL[i] - i;
            long long right = i - NSER[i];

            long long totalSubarray = left * right;

            long long totalSum = (totalSubarray * arr[i]) % M;

            ans = (ans + totalSum) %  M;
        }

        return (int)ans;
    }
};