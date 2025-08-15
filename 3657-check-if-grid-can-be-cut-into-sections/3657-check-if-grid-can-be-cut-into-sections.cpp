class Solution {
public:
    vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& cordinates){
        int n = cordinates.size();

        sort(cordinates.begin(), cordinates.end());

        vector<pair<int, int>> ans;

        for(int i=0; i<n; i++){
            if(ans.empty() || ans.back().second <= cordinates[i].first){
                ans.push_back({cordinates[i].first, cordinates[i].second});
            }
            else{
                ans.back().second = max(ans.back().second, cordinates[i].second);
            }
        }

        return ans;

    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int size = rectangles.size();

        vector<pair<int, int>> Xaxis;
        for(int i=0; i<size; i++){
            Xaxis.push_back({rectangles[i][0], rectangles[i][2]});
        }

        vector<pair<int, int>> Yaxis;
        for(int i=0; i<size; i++){
            Yaxis.push_back({rectangles[i][1], rectangles[i][3]});
        }

        vector<pair<int, int>> X = mergeIntervals(Xaxis);
        vector<pair<int, int>> Y = mergeIntervals(Yaxis);

        if(X.size() > 2 || Y.size() > 2) return true;

        return false;
    }
};