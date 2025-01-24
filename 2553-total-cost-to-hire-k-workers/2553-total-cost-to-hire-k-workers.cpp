class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int i = 0, j = n-1;

        priority_queue<int, vector<int>, greater<int>> left_minh;
        priority_queue<int, vector<int>, greater<int>> right_minh;

        int hired = 0;
        long long totalCost = 0;
        while(hired < k){
            while(left_minh.size() < candidates && i<=j ){
                left_minh.push(costs[i]);
                i++;
            }

            while(right_minh.size() < candidates && j>=i ){
                right_minh.push(costs[j]);
                j--;
            }

            int a = left_minh.size()>0 ? left_minh.top() : INT_MAX ;
            int b = right_minh.size()>0 ? right_minh.top() : INT_MAX ;

            if(a <= b){
                totalCost = totalCost + a;
                left_minh.pop();
            }
            else{
                totalCost = totalCost + b;
                right_minh.pop();
            }
            hired++;
        }
        return totalCost;
    }
};