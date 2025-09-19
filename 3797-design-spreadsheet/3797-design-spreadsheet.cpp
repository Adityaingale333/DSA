class Spreadsheet {
public:
    Spreadsheet(int rows) {
       sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        cell = cell.substr(1);
        int row = stoi(cell) - 1;
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        cell = cell.substr(1);
        int row = stoi(cell) - 1;
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);

        stringstream ss(formula);
        string part1, part2;
        getline(ss, part1, '+');
        getline(ss, part2);

        return evaluate(part1) + evaluate(part2);
    }

    private:
    vector<vector<int>> sheet;

    int evaluate(string part){
        if(isalpha(part[0])){
            int col = part[0] - 'A';
            int row = stoi(part.substr(1)) - 1;

            return sheet[row][col];
        }
        else{
            return stoi(part);
        }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */