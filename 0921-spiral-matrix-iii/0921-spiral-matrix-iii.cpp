class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
                                        //  east  south   west    north
        vector<vector<int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} }; 

        vector<vector<int>> result;

        int steps = 0;    // steps to inc in one row or coloumn
        int dir = 0;  // dir to go in 

        result.push_back({rStart, cStart});

        while(result.size() < rows*cols){   // loop goes till result matrix is not full
            if(dir==0 || dir==2){
                steps++;            // only inc steps when it is east or west, observation 
            }

            for(int count=0; count<steps; count++){   // use count for no of steps to go with
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    result.push_back({rStart, cStart});    // only push when valid
                }
            }
            dir = (dir+1)%4;    
        }
        return result;
    }
};