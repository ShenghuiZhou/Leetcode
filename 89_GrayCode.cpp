#include <vector>
#include <cmath>
using namespace std;
vector<int> grayCode(int n) {
	vector<int> ret;
	ret.reserve(pow(2,n));
	ret.push_back(0);
	int i = 0;
	while(i!=n) {
		for(auto riter = ret.rbegin(); riter!=ret.rend(); ++riter) {
			ret.push_back(*riter|(1<<i));
		}
		++i;
	}
	return ret;
}
