class NumberContainers {
public:
    unordered_map<int,int> idxToNum; // index -> number   1, 10 
    unordered_map<int, priority_queue<int, vector<int>, greater<int>> > numToIndices;  
    NumberContainers() { 
        
    }
    
    void change(int index, int number) {
        idxToNum[index] = number;

        numToIndices[number].push(index);
    }
    
    int find(int number) {
        if(!numToIndices.count(number)){ // If the number is not present
            return -1;
        }

        auto& minh = numToIndices[number]; // Reference to min-heap

        while(!minh.empty()){
            int idx = minh.top();

            // If the index is still valid (i.e., idxToNum[idx] is still `number`), return it
            if(idxToNum[idx] == number){
                return idx;
            }

            minh.pop(); // Remove outdated indices
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