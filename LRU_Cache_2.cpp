#include <iostream>
#include <list>
#include <map>
// #include <unordered_map>

using namespace std;
// https://oj.leetcode.com/problems/lru-cache/
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.


//map to record the key and idx
// list to record the LRU list
struct Node {
	int key;
	int value;
	/* data */
	Node(int kk, int vv): key(kk), value(vv) {}
};


class LRUCache
{
private:
	std::map<int, list<Node>::iterator> keyMap;
	// std::unordered_map <int, list<Node>::iterator> keyMap;
	list<Node> nodeList;
	int listSize;

public:
	LRUCache(int capacity)
	{
		listSize = capacity;
	}

	int get(int key)
	{
		if ( keyMap.find(key) == keyMap.end())
			return -1;
		Node nd = *(keyMap[key]);
		nodeList.erase(keyMap[key]);
		nodeList.push_front(nd);
		// list<Node>::iterator itr = nodeList.end();
		// itr--;
		keyMap[key] = nodeList.begin();
		return nd.value;
	}

	void set(int key, int value)
	{
		//find node, we change value, change position
		if (keyMap.find(key) != keyMap.end()) {// && keyMap[key] != NULL
			nodeList.erase ( keyMap[key]);			
		} else if (nodeList.size() >= listSize) {
			//not find node, check listsize, if not enough, remove_old, then, add new
			remove_old();
		}

		Node nd(key, value);

		nodeList.push_front(nd);
		keyMap[key] = nodeList.begin();
		// cout << nodeList.back().value << endl;
		// cout << (int)nodeList.end() <<endl;
	}

	void remove_old(void)
	{
		int key = (nodeList.back()).key;
		// int key=0;
		keyMap.erase(key);
		// keyMap[key] = nodeList.end();
		nodeList.pop_back();
	}

	void testget(int key){
		cout << get(key)<<endl;
	}
};

int main()
{
	LRUCache lr(2);
	lr.set( 2, 1);
	lr.set( 1, 1);
	lr.testget(2);
	lr.set( 4, 1);
	lr.testget(1);
	lr.testget(2);
	// cout << lr.get(1) << endl;
	cout << "hello world" << endl;
	return 0;
}