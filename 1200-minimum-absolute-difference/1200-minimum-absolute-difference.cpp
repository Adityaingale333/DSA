class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for(int i=0; i<n-1; i++){
            minDiff = min(minDiff, abs(arr[i+1] - arr[i]));
        }

        vector<vector<int>> ans;
        
        for(int i=0; i<n-1; i++){
            if(abs(arr[i+1] - arr[i]) == minDiff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};