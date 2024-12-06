class LFUCache {
public:
    
    int cap;
    int size;
    
    unordered_map<int, list<vector<int>>::iterator> mp; // key -> address
    map<int, list<vector<int>>> freq; // counter -> key, value, count

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeFrequentlyUsed(int key){
        auto &vec = *(mp[key]);

        int value = vec[1];
        int count = vec[2];

        freq[count].erase(mp[key]);

        if(freq[count].empty()){
            freq.erase(count);
        }

        count++;
        freq[count].push_front({key, value, count});

        mp[key] = freq[count].begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        auto vec = (*(mp[key]));  // vec = {key, value, count}
        int value = vec[1];

        makeFrequentlyUsed(key);

        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(mp.find(key) != mp.end()){
            auto &vec = *(mp[key]);
            vec[1] = value;
            makeFrequentlyUsed(key);
        }
        else if(size < cap){
            size++;
            //new entry, hamesha 1 me jayega
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else{   // remove LFU or LRU

            auto &kaun_sa_list = freq.begin()->second; // freq.begin = first of map  ->  .second = dll 

            int key_to_del = (kaun_sa_list.back())[0]; 

            kaun_sa_list.pop_back();

            if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first); // // freq.begin = first of map  ->  .first = counter
            }

            freq[1].push_front(vector<int>({key, value, 1}));
            mp.erase(key_to_del);
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */