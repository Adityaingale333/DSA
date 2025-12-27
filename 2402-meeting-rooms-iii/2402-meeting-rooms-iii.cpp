class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());

        vector<long long> lastAvailableAt(n, 0);

        vector<int> roomsUsedCount(n, 0);

        for(auto& it : meetings){
            int start = it[0];
            int end = it[1];
            int duration = end - start;

            bool found = false;

            long long earliestRoomTime = LLONG_MAX;
            int earliestRoom = 0;

            for(int room=0; room<n; room++){
                if(lastAvailableAt[room] <= start){
                    lastAvailableAt[room] = end;
                    roomsUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earliestRoomTime){
                    earliestRoomTime = lastAvailableAt[room];
                    earliestRoom = room;
                }
            }

            if(!found){
                lastAvailableAt[earliestRoom] = lastAvailableAt[earliestRoom] + duration;
                roomsUsedCount[earliestRoom]++;
            }
        }

        int ans = -1;
        int maxUsed = 0;

        for(int room=0; room<n; room++){
            if(roomsUsedCount[room] > maxUsed){
                maxUsed = roomsUsedCount[room];
                ans = room;
            }
        }

        return ans;
    }
};