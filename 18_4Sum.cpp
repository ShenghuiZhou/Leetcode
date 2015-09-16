#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ret;
	if(nums.size()<4) return ret;
	
	sort(nums.begin(),nums.end());
	int cur_min, cur_max;

	for(auto a=nums.begin(); a!=prev(nums.end(),3); ++a) {
		if(a!=nums.begin()&&*a==*prev(a)) continue;
		cur_min = *a+*next(a,1)+*next(a,2)+*next(a,3);
		cur_max = *a+*prev(nums.end())+*prev(nums.end(),2)+*prev(nums.end(),3);
		if(cur_min>target) break;
		if(cur_max<target) continue;

		for(auto b=next(a); b!=prev(nums.end(),2); ++b) {
			if(b!=next(a) && *b==*prev(b)) continue;
			cur_min = *a+*b+*next(b)+*next(b,2);
			cur_max = *a+*b+*prev(nums.end())+*prev(nums.end(),2);
			if(cur_min>target) break;
			if(cur_max<target) continue;

			auto c = next(b), d=prev(nums.end());
			while(c<d) {
				if(c!=next(b)&&*c==*prev(c)) {
					++c;
					continue;
				}
				if(d!=prev(nums.end())&&*d==*next(d)) {
					--d;
					continue;
				}

				int tmp = *a+*b+*c+*d;
				if(tmp==target) {
					ret.push_back({*a,*b,*c,*d});
					++c;
					--d;
				}
				else if(tmp>target) --d;
				else ++c;
			}
		
		}
	}

	return ret;
}
