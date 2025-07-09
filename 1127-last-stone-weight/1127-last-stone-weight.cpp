class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> maxh;

        for(int i=0; i<n; i++){
            maxh.push(stones[i]);
        }

        while(maxh.size() > 1){
            int y = maxh.top();
            maxh.pop();

            int x = maxh.top();
            maxh.pop();

            if(x != y) maxh.push(y - x);
        }

        return maxh.empty() ? 0 : maxh.top();
    }
};