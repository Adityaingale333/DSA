class NumberContainers {
public:
    unordered_map<int,int> idxToNum; // index -> number   1, 10
    unordered_map<int,set<int>> numToIndices; // num -> indices 10, {1,2,3,5} 
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        // If the index already has a number, remove it from numToIndices
        if(idxToNum.count(index)){
            int prevNum = idxToNum[index];
            numToIndices[prevNum].erase(index);

            // If there are no indices left for this number, erase it from the map
            if(numToIndices[prevNum].empty()){
                numToIndices.erase(prevNum);
            }
        }

        // Update the new number at this index
        idxToNum[index] = number;
        numToIndices[number].insert(index);
    }
    
    int find(int number) {
        if(numToIndices.count(number)){
            return *numToIndices[number].begin(); // Get smallest index
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */