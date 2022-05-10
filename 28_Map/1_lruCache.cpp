// https://leetcode.com/problems/lru-cache

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    int capacity;
    list<int> lru;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, int> kv;
    void update(int key) {
        if (mp.find(key) != mp.end()) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    void remove() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) 
            return -1;
        update(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if (mp.size() == capacity && mp.find(key) == mp.end()) {
            remove();
        }
        update(key);
        kv[key] = value;
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << '\n';
    cache.put(3, 3);
    cout << cache.get(2) << '\n';
    cache.put(4, 4);
    cout << cache.get(1) << '\n';
    cout << cache.get(3) << '\n';
    cout << cache.get(4) << '\n';
    return 0;
}