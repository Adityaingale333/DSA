class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0;
        double maxDiag = 0;

        for(int i=0; i<n; i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            double diag = sqrt((length*length) + (width*width));
            int area = length * width ;

            if(diag > maxDiag){
                maxDiag = diag;
                maxArea = area;
            }
            else if(diag == maxDiag){
                maxArea = max(area, maxArea);
            }
        }

        return maxArea;
    }
};