class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(directions[i] == 'R' && directions[i+1] == 'L'){
                ans += 2;
                directions[i] = 'S';
                directions[i+1] = 'S';
            }
            else if(directions[i] == 'S' && directions[i+1] == 'L'
                    || directions[i] == 'R' && directions[i+1] == 'S'){
                ans += 1;
                directions[i] = 'S';
                directions[i+1] = 'S';
            }
        }

        for(int i=n-1; i>0; i--){
            if(directions[i] == 'L' && directions[i-1] == 'R'){
                ans += 2;
                directions[i] = 'S';
                directions[i-1] = 'S';
            }
            else if(directions[i] == 'S' && directions[i-1] == 'R'
                    || directions[i] == 'L' && directions[i-1] == 'S'){
                ans += 1;
                directions[i] = 'S';
                directions[i-1] = 'S';
            }
        } 
        return ans;
    }
};