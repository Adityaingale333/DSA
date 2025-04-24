class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mp; // sum, total numbers of that sum
        int maxSize = INT_MIN;
        int count = 0;

        for(int i=1; i<=n; i++){
            int sum = 0;
            int x = i;
            while(x > 0){
                sum = sum + x%10 ;
                x = x/10;
            }
            mp[sum]++;
            maxSize = max(maxSize, mp[sum]);
        } 

        for(auto& it:mp){
            if(it.second == maxSize){
                count++;
            }
        }
        return count;
    }
};