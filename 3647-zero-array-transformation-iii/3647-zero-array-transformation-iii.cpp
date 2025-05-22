class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        sort(queries.begin(), queries.end());

        priority_queue<int> maxh; // to store farthest ending
        priority_queue<int, vector<int>, greater<int>> past; // to store past endings of queries

        int j=0; // pointing to queries
        int usedCount = 0; // number of queries we have used 

        for(int i=0; i<n; i++){
            while(j<q && queries[j][0] == i){
                maxh.push(queries[j][1]); // ending of the queries -> (0,2) -> maxh{2}
                j++;
            }

            //first check if we can impact current nums[i] from past queries endings 
            nums[i] = nums[i] - past.size();

            while(nums[i]>0 && !maxh.empty() && maxh.top() >= i){
                int ending = maxh.top();
                maxh.pop();
                past.push(ending);
                nums[i]--;
                usedCount++;
            }

            if(nums[i] > 0){
                return -1;
            }

            // clear out past indices which are outdated
            while(!past.empty() && past.top() <= i){
                past.pop();
            }
        }
        return q - usedCount;
    }
};