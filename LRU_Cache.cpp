#include <list>
#include <unordered_map>
#include <utility>

using namespace std;

class LRUCache {
	private:
		int cap;
		list<pair<int,int>> l;
		unordered_map<int,list<pair<int,int>>::iterator> m;

	public:
		LRUCache(int capacity) 
			:cap(capacity) { }

		int get(int key) {
			auto iter = m.find(key);
			if(iter==m.end()) return -1;
			l.splice(l.begin(),l,iter->second);
			return l.front().second;
		}

		void set(int key, int val) {
			auto iter = m.find(key);
			if(iter!=m.end()) {
				l.splice(l.begin(),l,iter->second);
				l.begin()->second = val;
			}
			else {
				if(m.size()==cap) {
					m.erase(m.find(l.back().first));
					l.pop_back();
				}
				l.push_front({key,val});
				m.insert({key,l.begin()});
			}
		}
};


