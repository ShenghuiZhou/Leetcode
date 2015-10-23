#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int findDuplicate(const vector<int>& nums) {
	int b=1, e=nums.size();
	while(b!=e) {
		auto mid = (b+e)>>1;
		int left=0,right=0,cnt=0;
		for(auto i:nums) {
			if(i==mid) {
				++cnt;
				if(cnt==2) return mid;
			}
			else if(i<e&&i>mid) ++right;
			else if(i>=b&&i<mid) ++left;
		}

		if(left>right) e=mid;
		else b=mid+1;
	}
	return -1;
}

int main() {
	vector<int> nums = {1,2,3,3,4};
	cout << findDuplicate(nums);
}
