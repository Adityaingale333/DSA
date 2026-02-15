class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length())+1;
        string ans(n, '0');

        int i = a.length()-1;
        int j = b.length()-1;
        int k = n - 1;
        bool carry = false;

        while(i>=0 && j>=0){
            if(a[i] == '1' && b[j] == '1'){
                if(carry){
                    ans[k] = '1';
                    carry = true;
                }
                else{
                    ans[k] = '0';
                    carry = true;
                }
            }
            else if(a[i] == '1' && b[j] == '0' || a[i] == '0' && b[j] == '1'){
                if(carry){
                    ans[k] = '0';
                    carry = true;
                }
                else{
                    ans[k] = '1';
                    carry = false;
                }
            }
            else{
                if(carry){
                    ans[k] = '1';
                    carry = false;
                }
                else{
                    ans[k] = '0';
                }
            }
            i--, j--, k--;
        }

        while(i >= 0){
            if(carry){
                if(a[i] == '1'){
                    ans[k] = '0';
                    carry = true;
                }
                else{
                    ans[k] = '1';
                    carry = false;
                } 
            }
            else{
                ans[k] = a[i];
            }
            i--, k--;
        }

        while(j >= 0){
            if(carry){
                if(b[j] == '1'){
                    ans[k] = '0';
                    carry = true;
                }
                else{
                    ans[k] = '1';
                    carry = false;
                } 
            }
            else{
                ans[k] = b[j];
            }
            j--, k--;
        }

        if(carry){
            ans[k] = '1';
            k--;
        }

        return ans[0] == '1' ? ans : ans.substr(1);
    }
};