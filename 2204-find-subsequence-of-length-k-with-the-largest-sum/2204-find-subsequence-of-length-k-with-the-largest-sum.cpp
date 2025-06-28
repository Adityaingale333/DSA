class Solution {
public:
    typedef pair<int,int> P;
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> minh; // element, index

        for(int i=0; i<n; i++){
            minh.push({nums[i], i});

            if(minh.size() > k){
                minh.pop();
            }
        } 

        // store index of top k largest element
        vector<int> ans;
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        
        // now we can sort those k indices and then store our elements
        sort(ans.begin(), ans.end());

        for(int i=0; i<k; i++){
            ans[i] = nums[ans[i]];
        }
        
    return ans;
    }
};