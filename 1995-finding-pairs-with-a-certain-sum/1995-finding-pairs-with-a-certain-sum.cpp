class FindSumPairs {
public:
    vector<int> vec1;
    vector<int> vec2;
    unordered_map<int, int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;
        for(int& it : nums2){ // nums2 ko map me isliye store kiya kyuki iska 10^5 hai, toh agar iterate krte toh jyada time lagta  
            freq[it]++;
        }
    }
    // O(1), kuyki unordered_map use kiya
    void add(int index, int val) {
        freq[vec2[index]]--;
        vec2[index] = vec2[index] + val;
        freq[vec2[index]]++;
    }
    
    int count(int tot) {
        int count = 0;

        for(int i=0; i<vec1.size(); i++){
            if(freq.find(tot - vec1[i]) != freq.end()){
                count = count + freq[tot - vec1[i]];
            }
        }

        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */