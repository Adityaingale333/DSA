class Solution {
public:
    bool check(string& s){
        for(auto& ch : s){
            if(!isalnum(ch) && ch != '_'){
                return false;
            }
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        vector<tuple<string, string, int>> isValid; // code, business line, index

        for(int i=0; i<n; i++){
            
            if(!code[i].empty() && check(code[i]) && 
               (businessLine[i] == "electronics" || businessLine[i] == "grocery" || 
                businessLine[i] == "pharmacy" || businessLine[i] == "restaurant") && isActive[i] ){
                
                isValid.push_back(make_tuple(code[i], businessLine[i], i));
            }
            
        }

        sort(isValid.begin(), isValid.end(), [&](const tuple<string, string, int>& a, tuple<string, string, int>& b){

            vector<string> order = {"electronics", "grocery", "pharmacy", "restaurant"};

            int businessA = find(order.begin(), order.end(), get<1>(a)) - order.begin();
            int businessB = find(order.begin(), order.end(), get<1>(b)) - order.begin();

            if(businessA != businessB){
                return businessA < businessB;
            }
            return get<0>(a) < get<0>(b);
        });

        vector<string> ans;
        for(auto& coupon : isValid){
            ans.push_back(get<0>(coupon));
        }
        
        return ans;
    }
};