class Solution {
public:
    int M = 1e9 + 7;

    typedef pair<int,int> P; // {subarray sum, end index of this subarray}
    
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> minh;

        for(int i=0; i<n; i++){
            minh.push({nums[i], i});
        }

        int result = 0;

        for(int i=1; i<=right; i++){
            auto top = minh.top();
            minh.pop();

            int sum = top.first;
            int idx = top.second;

            if(i >= left){
                result = (result + sum) % M;
            }

            int new_idx = idx + 1;
            P new_pair;
            if(new_idx < n){
                new_pair.first = sum + nums[new_idx];
                new_pair.second = new_idx;
                minh.push(new_pair);
            }
        }
        return result;
    }
};