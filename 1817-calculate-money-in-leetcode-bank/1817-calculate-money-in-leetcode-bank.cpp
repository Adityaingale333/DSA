class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7;

        int first = 28;
        int last = 28 + (terms-1) * 7;

        int ans = terms * (first + last)/2;

        int rem = n % 7;

        int first_term = terms + 1;
        int last_term = first_term + rem - 1;

        ans = ans + rem * (first_term + last_term)/2;

        return ans;
    }
};