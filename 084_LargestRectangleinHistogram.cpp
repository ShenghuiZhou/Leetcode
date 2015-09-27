#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int largestRectangleArea(vector<int>& height) {
	int ret = 0;
	if(height.empty()) return ret;
	height.push_back(0);
	stack<pair<int,int>> stk;
	for(int i=0; i!=height.size(); ++i) {
		if(stk.empty() || height[stk.top().first]<=height[i]) stk.push({i,0});
		else {
			int cnt = 0;
			while(!stk.empty() && height[stk.top().first]>height[i]) {
				cnt+=stk.top().second+1;
				int tmp = height[stk.top().first]*(i-stk.top().first+stk.top().second);
				ret = max(tmp,ret);
				stk.pop();
			}
			stk.push({i,cnt});
		}
	}
	return ret;
}


int main(){
	vector<int> test = {1};
	cout << largestRectangleArea(test) << endl;
}
