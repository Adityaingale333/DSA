class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>> sortedTasks;

        // Add start_time, processing_time, and index
        for(int i=0; i<n; i++){
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];

            sortedTasks.push_back({start_time, processing_time, i});
        }

        // Sort by start_time
        sort(sortedTasks.begin(), sortedTasks.end());

        vector<int> ans;
        long long curr_time = 0;
        int idx = 0;

        // Min-heap: {processing_time, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

        while(idx < n || !minh.empty()){
            // If the heap is empty, move current time to the next available task
            if(minh.empty() && curr_time < sortedTasks[idx][0]){
                curr_time = sortedTasks[idx][0];
            }

            // Push all tasks whose start_time <= current time into the heap
            while(idx < n && sortedTasks[idx][0] <= curr_time){
                minh.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int,int> curr_task = minh.top();
            minh.pop();

            // Increment current time by processing_time
            curr_time = curr_time + curr_task.first ; // .first = processing time
            ans.push_back(curr_task.second);
        }
        return ans;
    }
};