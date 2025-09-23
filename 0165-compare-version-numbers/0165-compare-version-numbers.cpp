class Solution {
public:
    vector<int> getRevision(string version, int n){
        vector<int> revision;

        int i=0;
        int j=0;

        while(j<n){
            if(version[j] == '.'){
                int val = stoi(version.substr(i, j-i));
                revision.push_back(val);
                j++;
                i = j;
                continue;
            }
            
            j++;
        }

        revision.push_back(stoi(version.substr(i, j-i)));

        return revision;
    }
    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();

        vector<int> revision1 = getRevision(version1, n);
        vector<int> revision2 = getRevision(version2, m);

        int i=0;
        int size1 = revision1.size();
        int size2 = revision2.size();

        int maxLen = max(size1, size2);

        while(i<maxLen){
            int val1 = i < size1 ? revision1[i] : 0;
            int val2 = i < size2 ? revision2[i] : 0;

            if(val1 > val2){
                return 1; 
            }
            else if(val1 < val2){
                return -1;
            }

            i++;
        }

        return 0;
    }
};