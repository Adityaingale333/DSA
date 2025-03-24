class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        int end = 0;
        int count = 0;
        for(int i=0; i<n; i++){
            if(meetings[i][0] > end){
                count = count + (meetings[i][0]-end-1);
            }
            end = max(end, meetings[i][1]);
        }

        if(days > end){
            count += days - end;
        }
        return count;
    }
};