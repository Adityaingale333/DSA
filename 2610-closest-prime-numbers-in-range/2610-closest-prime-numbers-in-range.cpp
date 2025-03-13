class Solution {
public:
    // helper function to get list of prime numbers between the range {left, right}
    vector<bool> sieveHelper(int right){
        vector<bool> isPrime(right+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2; i*i<=right; i++){
            if(isPrime[i] == true){
                for(int j=2; i*j<=right; j++){
                    isPrime[i*j] = false; 
                }
            }
        }
        return isPrime;
    }

    // we iterate in prime number's list and check the diff between the two numbers, if 
    // it is less than minDiff then we update the ans the minDiff
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime = sieveHelper(right);

        vector<int> prime;
        for(int i=left; i<=right; i++){
            if(isPrime[i] == true){
                prime.push_back(i);
            }
        }

        int minDiff = INT_MAX;
        vector<int> ans = {-1,-1};
        for(int i=1; i<prime.size(); i++){
            int diff = prime[i] - prime[i-1];
            if(diff < minDiff){
                minDiff = diff;
                ans = {prime[i-1], prime[i]};
            }
        }
        return ans;
    }
};