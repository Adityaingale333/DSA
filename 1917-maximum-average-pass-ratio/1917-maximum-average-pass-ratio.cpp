class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double, int>> maxh; // delts, idx

        for(int i=0; i<n; i++){
            double PR = (double)(classes[i][0])/(classes[i][1]);
            double newPR = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
            double delta = newPR - PR;
            maxh.push({delta, i});
        }

        while(extraStudents--){
            auto curr = maxh.top();
            maxh.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double PR = (double)(classes[idx][0])/(classes[idx][1]);
            double newPR = (double)(classes[idx][0] + 1)/(classes[idx][1] + 1);
            delta = newPR - PR;
            maxh.push({delta, idx}); 
        }

        double result = 0.0;
        for(int i=0; i<n; i++){
            result = result + (double)(classes[i][0])/(classes[i][1]);
        }

        return result / n;
    }
};