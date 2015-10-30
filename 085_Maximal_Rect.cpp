#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &height) {
	int result = 0;
	if (height.empty()) return 0;
	height.push_back(0);
	stack<pair<int, int>> stk;
	for (int index = 0; index != height.size(); ++index) {
		if (stk.empty() || height[stk.top().first] <= height[index])
			stk.push({ index,0 });
		else {
			int pop_count = 0;
			while (!stk.empty() && height[stk.top().first]>height[index]) {
				pop_count = pop_count + 1 + stk.top().second;
				int tmp = (index - stk.top().first + stk.top().second)*height[stk.top().first];
				result = max(result, tmp);
				stk.pop();
			}
			stk.push({ index,pop_count });
		}
	}
	height.pop_back();
	return result;
}

int maximalRectangle(vector<vector<char>> &matrix) {
	const int M = matrix.size();
	if (M == 0) return 0;
	const int N = matrix[0].size();
	vector<int> f(N);
	for (int i = 0; i != N; ++i) f[i] = matrix[0][i] - '0';
	int ret = largestRectangleArea(f);
	for (int i = 1; i != M; ++i) {
		for (int j = 0; j != N; ++j) {
			f[j] = matrix[i][j] == '0' ? 0 : f[j] + 1;
		}
		ret = max(ret, largestRectangleArea(f));
	}
	return ret;
} 
