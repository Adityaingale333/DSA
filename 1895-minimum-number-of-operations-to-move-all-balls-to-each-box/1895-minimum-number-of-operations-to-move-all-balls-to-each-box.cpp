class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        vector<int> ball_index;

        for(int i=0; i<n; i++){
            if(boxes[i] == '1')ball_index.push_back(i);
        }

        for(int i=0; i<n; i++){
            int steps = 0;
            for(int j=0; j<ball_index.size(); j++){
                steps = steps + abs(i - ball_index[j]);
            }
            ans.push_back(steps);
        }
        return ans;
    }
};