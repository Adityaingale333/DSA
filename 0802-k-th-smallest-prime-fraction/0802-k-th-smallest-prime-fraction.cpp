class Solution {
public:
    typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<V, vector<V>, greater<V>> minh;

        // Initialize the heap with the smallest fraction from each row (i.e., arr[i]/arr[n-1])
        for(int i=0; i<n; i++){
            minh.push({1.0*arr[i]/arr[n-1], (double)i, (double)n-1}); // 1.0* to convert to double 
        }

        int smallest = 1;
        while(smallest < k){
            V vec = minh.top(); // Get the smallest fraction from the heap
            minh.pop(); // Remove the smallest fraction

            int i = vec[1]; // Numerator index
            int j = vec[2] - 1; // Move to the next smaller denominator index

            // Push the next fraction from the same row into the heap
            minh.push({1.0*arr[i]/arr[j], (double)i, (double)j});
            smallest++;
        }

        // The k-th smallest fraction is now at the top of the heap
        V vec = minh.top();
        int i = vec[1];
        int j = vec[2];

        return {arr[i],arr[j]};

    }
};