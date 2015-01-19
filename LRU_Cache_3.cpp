#include <iostream>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;
// code from  https://oj.leetcode.com/discuss/20619/c-11-code-74ms-hash-table-list

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(it);
        return it->second.first;
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) touch(it);
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = { value, used.begin() };
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> PII;
    typedef unordered_map<int, PII> HIPII;

    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }

    HIPII cache;
    LI used;
    int _capacity;
};


int main()
{
    LRUCache lr(2);
    lr.set( 2, 1);
    lr.set( 1, 1);
    // lr.testget(2);
    cout << lr.get(2)<<endl;
    lr.set( 4, 1);
    // lr.testget(1);
    cout << lr.get(1)<<endl;
    // lr.testget(2);
    cout << lr.get(2)<<endl;
    // cout << lr.get(1) << endl;
    cout << "hello world" << endl;
    return 0;
}