class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> freeTime;

        freeTime.push_back(startTime[0]); // free time before first meeting

        for(int i=1; i<n; i++){ // free time during meetings
            freeTime.push_back( startTime[i] - endTime[i-1]);
        }

        freeTime.push_back(eventTime - endTime[n-1]); // free time after last meeting

        int l = 0;
        int r = 0;
        int ans = INT_MIN;
        int sum = 0;

        while(r < freeTime.size()){
            sum = sum + freeTime[r];

            if(r-l+1 > k+1){
                sum = sum - freeTime[l];
                l++;
            }

            ans = max(ans, sum);
            r++;
        }

        return ans;
    }
};