class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> ans;
        unordered_set<string> st;

        for(int i=0; i<n; i++){
            st.insert(folder[i]);
        }

        for(auto& currFolder : folder){

            bool isSubFolder = false;
            string tempFolder = currFolder;

            while(!currFolder.empty()){
                size_t last_slash_idx = currFolder.find_last_of('/');
                
                currFolder = currFolder.substr(0, last_slash_idx);

                if(st.count(currFolder)){
                    isSubFolder = true;
                    break;
                }
            }

            if(isSubFolder == false){
                ans.push_back(tempFolder);
            }
        }   

        return ans;
    }
};