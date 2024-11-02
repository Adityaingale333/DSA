class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();

        int lMax = 0;
        int rMax = 0;
        int total = 0;

        int l=0, r = n-1;

        while(l<r){
            if(arr[l] <= arr[r]){
                if(lMax > arr[l]){
                    total = total + lMax - arr[l];
                }
                else lMax = arr[l];
                l++;
            }
            else{
                if(rMax > arr[r]){
                    total = total + rMax - arr[r];
                }
                else rMax = arr[r];
                r--;
            }
        }
        return total;
    }
};