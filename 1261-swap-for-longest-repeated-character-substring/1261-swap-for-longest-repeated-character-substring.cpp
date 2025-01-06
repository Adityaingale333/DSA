class Solution {
public:
    int maxRepOpt1(string s) {
         int n = s.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> freq(26, 0);
        int max_len = 0;

         // Step 1: Compute frequency of each character
         for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
         }

        // Step 2: Compute left[] array
        for(int i=0; i<n; i++){
            if(i>0 && s[i]==s[i-1]){
                left[i] = left[i-1] + 1;
            }
            else{
                left[i] = 1;
            }
            max_len = max(max_len, left[i]);
        }


        // Step 3: Compute right[] array
        for(int i=n-1; i>=0; i--){
            if(i<n-1 && s[i]==s[i+1]){
                right[i] = right[i+1] + 1;
            }
            else{
                right[i] = 1;
            }
        }

        // Step 4: Check for swaps and calculate max length
        for(int i=1; i<n-1; i++){

            // Case 1: Possible swap in the middle
            if(s[i-1]==s[i+1] && s[i-1]!=s[i]){
                int combined_length = left[i-1] + right[i+1];
                if(freq[s[i-1]-'a'] > combined_length){
                    combined_length++;;
                }
                max_len = max(max_len, combined_length);
            }

            // Case 2: Extend the current character's length, (aaaaa)
            max_len = max(max_len, left[i] + (freq[s[i]-'a'] > left[i] ? 1 : 0));
        }

         // Final check for last index
        max_len = max(max_len, left[n - 1] + (freq[s[n - 1] - 'a'] > left[n - 1] ? 1 : 0));

        return max_len;
    }
};

// left = [1, 2, 3, 1, 1, 2, 3]
// right = [3, 2, 1, 1, 1, 2, 3]

// At i = 3: Case 1 applies since s[2] == s[4] (a == a) and s[3] != s[2] (b != a).
// combinedLength = left[2] + right[4] = 3 + 3 = 6.
// No additional 'a' outside the window, so max_len = max(0, 6) = 6.
// Final Output for "aaabaaa":

// max_len = 6