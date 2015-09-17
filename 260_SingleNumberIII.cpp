#include <vector>

using namespace std;

vector<int> singleNumber(vector<int>& nums) {
	int xor_all = 0;
	for(auto i:nums) xor_all^=i;
	int key = 0;
	while(!((xor_all>>key)&0x1)) ++key;
	vector<int> ret = {0,0};
	for(auto i:nums) {
		if((i>>key)&0x1) ret[0]^=i;
		else ret[1]^=i;
	}
	return ret;
}
