class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxh;

        for(auto& it : piles){
            maxh.push(it);
        }

        while(k--){
            int stones_removed = maxh.top()/2;
            int stones_remaining = maxh.top() - stones_removed;
            maxh.pop();
            maxh.push(stones_remaining);
        }

        int ans;
        while(!maxh.empty()){
            ans = ans + maxh.top();
            maxh.pop();
        }
        return ans;
    }
};