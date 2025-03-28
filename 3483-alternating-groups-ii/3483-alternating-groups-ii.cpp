class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();

        int ans = 0;
        int length = 1;
        int last = colors[0];

        for(int i=0; i<n; i++){
            if(colors[i] == last){
                length = 1;
                last = colors[i];
                continue;
            }

            length++;

            if(length >= k){
                ans++;
            }

            last = colors[i];
        }

        for(int i=0; i<k-1; i++){
            if(colors[i] == last){
                length = 1;
                last = colors[i];
                break;
            }

            length++;

            if(length >= k){
                ans++;
            }

            last = colors[i];
        }
        return ans;
    }
};