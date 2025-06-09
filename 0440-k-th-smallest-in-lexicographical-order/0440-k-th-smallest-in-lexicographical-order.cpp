class Solution {
public:
    int getCount(long long curr, long long next, int n){
        int countNum = 0;

        while(curr <= n){
            countNum += next - curr;

            curr = curr*10;
            next = next*10;

            next = min(next, (long long)n+1); // ho skta hai vo out of range wale number ko bhi count krle, isliye min value
        }
        return countNum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k = k-1; // 1 ko include kr liya, isliye k-1 aur chahiye

        while(k > 0){
            int count = getCount(curr, curr+1, n);

            if(count <= k){
                curr++;
                k = k - count; // skipping the elements of curr tree
            }
            else{
                curr *= 10;
                k= k -1; // tree ke aur depth me jaa rahe hai, isliye root ka 1 minus kiya hai, example 10 ko minus kiya
            }
        }
        return curr;
    }
};