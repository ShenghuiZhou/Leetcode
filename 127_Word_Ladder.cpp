#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int ladderLength(string beginWord, string endWord, const unordered_set<string>& wordList) {
	unordered_map<string,bool> check;
	for(const auto &w:wordList) check[w] = true; 
	check[beginWord] = check[endWord] = false;
	unordered_set<string> f = {beginWord}, b = {endWord};
	auto p = &f, q = &b;
	int ret = 1;
	while(!f.empty() && !b.empty()) {
		++ret;
		if(p->size()>q->size()) swap(p,q);
		unordered_set<string> next;
		for(auto w:*p) {
			for(int i=0; i!=w.size(); ++i) {
				for(int j=0; j!=26; ++j) {
					char tmp = 'a' + j;
					if(tmp!=w[i]) {
						swap(tmp,w[i]);
						if(q->find(w)!=q->end()) return ret;
						if(wordList.find(w)!=wordList.end() && check[w]) {
							next.insert(w);
							check[w] = false;
						}
						swap(tmp,w[i]);
					}
				}	
			}
		}
		swap(next,*p);
	}
	return 0;
}
