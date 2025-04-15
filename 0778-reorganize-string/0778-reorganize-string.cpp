class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        vector<int> freq(26,0); // store the frequency of all char
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
// *** if any char appears more than half the size then it's not possible to construct the result
            if(freq[s[i]-'a'] > (n+1)/2){ 
                return "";
            }
        }

// to get the freq in required order we are using pq 
        priority_queue<pair<int, char>> maxh;
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                maxh.push({freq[i], i+'a'});
            }
        }

        string result = "";
        while(maxh.size() >= 2){  // doing this bcz if the size is 1, then we do not need to visit pq while loop
                                // we can directly pop it using the below if statement 
            auto temp1 = maxh.top();
            maxh.pop();             // since we are checking the size >= 2, means it safer and faster
                                    // to pop 2 elements each time
            auto temp2 = maxh.top();
            maxh.pop();

            result.push_back(temp1.second);
            temp1.first--;
            result.push_back(temp2.second);
            temp2.first--;

            if(temp1.first > 0){
                maxh.push(temp1);
            }
            if(temp2.first > 0){
                maxh.push(temp2);
            }
        }
        if(!maxh.empty()){ // if it contains only single element, then we can simply use it to save time
            result.push_back(maxh.top().second);
            maxh.pop();
        }
        return result;
    }
};