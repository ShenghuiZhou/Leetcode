/*
 * KMP:
 * ABCDABCDABD
 * ABCDABD
 *     ABCDABD
 */
#include <vector>
#include <string>

using namespace std;

vector<int> getLongestTable(const string &str) {
	const int N = str.size();
	vector<int> ret(N,0);
	
	int i=0, j=1;
	while(j!=N) {
		if(str[i]==str[j]) ret[j++] = ++i;
		else {
			if(i==0) ret[j++] = 0;
			else i = ret[i-1];
		}
	}

	return ret;
}

int strStr(const string &s, const string &p) {
	if(s.size()<p.size()) return -1;
	if(p.empty() || p==s) return 0;

	auto f = getLongestTable(p);

	int i=0, j=0;
	while(i!=s.size()) {
		if(s[i]==p[j]) {
			++i;
			++j;
			if(j==p.size())
				return i-j;
		}
		else {
			if(j==0) ++i;
			else j=f[j-1];
		}
	}

	return -1;
}


