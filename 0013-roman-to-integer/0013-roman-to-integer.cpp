class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int result = map[s[n-1]];

        for(int i=n-2; i>=0; i--){
            if(map[s[i]] < map[s[i+1]]){
                result = result - map[s[i]];
            }
            else{
                result = result + map[s[i]];
            }
        }
        return result;
    }
};