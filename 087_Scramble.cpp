#include <string>
#include <vector>

using namespace std;

template<typename T>
bool solution(const string &s1, int beg1, int end1, const string &s2, int beg2, T &f) {
	int dist = end1 - beg1;
	if(dist==1) return s1[beg1] == s2[beg2];
	if(f[beg1][end1][beg2]!=0) return f[beg1][end1][beg2]==1;
	f[beg1][end1][beg2] = -1;
	int end2 = beg2 + dist;
	for(int i=1; i!=dist; ++i) {
		if((solution(s1,beg1,beg1+i,s2,beg2,f)   && solution(s1,beg1+i,end1,s2,beg2+i,f)) ||
		   (solution(s1,beg1,beg1+i,s2,end2-i,f) && solution(s1,beg1+i,end1,s2,beg2,f))) {
			f[beg1][end1][beg2] = 1;
			break;
		}
	}
	return f[beg1][end1][beg2] ==1;
}

bool isScramble(string s1, string s2) {
	const int N = s1.size() + 1;
	vector<vector<vector<int>>> f (N,vector<vector<int>>(N,vector<int>(N,0)));
	return solution(s1,0,s1.size(),s2,0,f);
}
