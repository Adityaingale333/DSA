class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> rowMap; // row -> {minCol, maxCol}
        unordered_map<int, pair<int, int>> colMap; // col -> {minRow, maxRow}

        for(auto& it : buildings){
            int row = it[0], col = it[1];

            if (!rowMap.count(row))
                rowMap[row] = {col, col};
            else {
                rowMap[row].first  = min(rowMap[row].first, col);
                rowMap[row].second = max(rowMap[row].second, col);
            }

            if (!colMap.count(col))
                colMap[col] = {row, row};
            else {
                colMap[col].first  = min(colMap[col].first, row);
                colMap[col].second = max(colMap[col].second, row);
            }
        }

        int ans = 0;

        for(auto& it : buildings){
            int row = it[0], col = it[1];

            int minCol = rowMap[row].first;
            int maxCol = rowMap[row].second;
            int minRow = colMap[col].first;
            int maxRow = colMap[col].second;

            if(col > minCol && col < maxCol && row > minRow && row < maxRow){
                ans++;
            }
        }

        return ans;
    }
};