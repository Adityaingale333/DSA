class Solution {
public:
    // most optimal solutin O(n)
    // we can use nth_element function in C++, which return us the nth largest element
    // it returns array such that, we get kth largest and to its left will be smaller and to its right all greater
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> temp = nums;

        nth_element(temp.begin(), temp.begin() + k - 1,  temp.end(), greater<int>());

        int kth_largest = temp[k-1];
        int count_K_largest = count(temp.begin(), temp.begin() + k, kth_largest);

        vector<int> ans;
        
        for(int& num : nums){
            if(num > kth_largest){
                ans.push_back(num);
            }
            else if(num == kth_largest && count_K_largest > 0){
                ans.push_back(num);
                count_K_largest--;
            }

            if(ans.size() == k){
                break;
            }
        }
        return ans;
    }
};