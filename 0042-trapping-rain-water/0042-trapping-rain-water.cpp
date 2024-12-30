class Solution {
public:
//                       EASY FORMULA
//  at point i, rainwater collected will be  min(l_max[i],r_max[i]) - height[i]
    vector<int> getLeftMax(vector<int>& height, int n){
        vector<int> l_max(n);
        l_max[0] = height[0];
        for(int i=1; i<n; i++){
            l_max[i] = max(l_max[i-1], height[i]);
        }
        return l_max;
    } 
    vector<int> getRightMax(vector<int>& height, int n){
        vector<int> r_max(n);
        r_max[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            r_max[i] = max(r_max[i+1], height[i]);
        }
        return r_max;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l_max = getLeftMax(height,n);
        vector<int> r_max = getRightMax(height,n);
        int total = 0;

        for(int i=0; i<n; i++){
            total = total + min(l_max[i],r_max[i]) - height[i];
        }
        return total;
    }
};