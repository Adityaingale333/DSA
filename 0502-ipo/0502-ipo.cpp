class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {capital[i], profits[i]};
        }

        sort(vec.begin(), vec.end());

        int i = 0;
        priority_queue<int> maxh;
        while(k--){
            while(i<n && vec[i].first <= w){
                maxh.push(vec[i].second);
                i++;
            }
            if(maxh.empty()) break;
            w = w + maxh.top();
            maxh.pop();
        }

        return w;
    }
};