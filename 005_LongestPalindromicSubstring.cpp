#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestPalindrome(string s) {
	string str = "#";
	for(auto c:s) {
		str.push_back(c);
		str.push_back('#');
	}

	const int N = str.size();
	vector<int> f(N);
	int center = 0, reach = 0, i = 0;
	
	// 8ms
	/*
	while(i!=N) {
		if(i>=center+reach) {
			int tmp = 0;
			while(i-tmp>=0 && i+tmp<N && str[i-tmp]==str[i+tmp]) ++tmp;
			f[i] = tmp-1;
		}
		else {
			int ii = 2*center - i;
			if(ii-(center-reach)>f[ii]) f[i] = f[ii];
			else {
				int tmp = ii-(center-reach);
				while(i-tmp>=0 && i+tmp<N && str[i-tmp]==str[i+tmp]) ++tmp;
				f[i] = tmp-1;
			}
		}
		
		if(i+f[i]>center+reach) {
			center = i;
			reach = f[i];
		}
		
		++i;
	}
	*/

	// 100+ms
	while(i!=N) {
		int tmp = 0;
		while(i-tmp>=0 && i+tmp<N && str[i-tmp]==str[i+tmp]) ++tmp;
		f[i] = tmp-1;
		++i;
	}

	center = 0, reach = 0, i=0;
	while(i!=N) {
		if(f[i]>reach) {
			center = i;
			reach = f[i];
		}
		++i;
	}

	string ret;
	for(i=center-reach; i<=center+reach; ++i) {
		if(str[i]!='#')
			ret.push_back(str[i]);
	}
	return ret;
}

int main() {
	string test = "abcbb";
	cout << longestPalindrome(test);
}
