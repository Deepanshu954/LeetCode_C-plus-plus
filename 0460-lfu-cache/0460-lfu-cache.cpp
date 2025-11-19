class LFUCache {
public:
    unordered_map<int, pair<int, int>> cache;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
    int cap, minFreq;
    
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        updateFreq(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            updateFreq(key);
        } else {
            if (cache.size() >= cap) {
                int evict = freq[minFreq].back();
                freq[minFreq].pop_back();
                iter.erase(evict);
                cache.erase(evict);
            }
            cache[key] = {value, 1};
            freq[1].push_front(key);
            iter[key] = freq[1].begin();
            minFreq = 1;
        }
    }
    
    void updateFreq(int key) {
        int f = cache[key].second;
        freq[f].erase(iter[key]);
        if (freq[f].empty() && f == minFreq) minFreq++;
        cache[key].second++;
        freq[f + 1].push_front(key);
        iter[key] = freq[f + 1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */