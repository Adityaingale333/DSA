class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();

        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);

        for(int i=1; i<n; i++){
            string currFolder = folder[i];
            string lastFolder = ans.back();
            lastFolder += '/';

            if(currFolder.find(lastFolder) != 0){
                ans.push_back(currFolder);
            }
        }

        return ans;
    }
};