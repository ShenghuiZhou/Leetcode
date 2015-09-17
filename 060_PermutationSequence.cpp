#include <string>
#include <vector>
#include <iostream>
using namespace std;

string getPermutation(int n, int k) {
	string ret;
	vector<int> nums(n,1), cnts(n,1);
	for(int i=1; i!=n; ++i) {
		nums[i] = i+1;
		cnts[i] = nums[i] * cnts[i-1];
	}
	cnts.pop_back();

	while(nums.size()>1) {
		int ind = (k-1)/cnts.back();
		ret.push_back('0'+nums[ind]);
		nums.erase(next(nums.begin(),ind));
		k = k%cnts.back() == 0? cnts.back() : k%cnts.back();
		cnts.pop_back();
	}
	ret.push_back(nums.front() + '0');
	return ret;
}


int main() {
	cout << getPermutation(4,6);
}
