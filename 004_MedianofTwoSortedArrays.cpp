#include <vector>
#include <algorithm>

using namespace std;

template<typename I>
int findKth(I b1, I e1, I b2, I e2, int k) {
	int d1 = distance(b1,e1), d2 = distance(b2,e2);
	
	if(d1>d2) return findKth(b2,e2,b1,e1,k);
	if(d1==0) return *next(b2,k-1);
	if(k==1) return min(*b1,*b2);

	int i1 = min(k/2,d1);
	int i2 = k-i1;

	auto iter1 = next(b1,i1-1);
	auto iter2 = next(b2,i2-1);

	if(*iter1==*iter2) return *iter1;
	else if(*iter1>*iter2) return findKth(b1,e1,next(iter2),e2,k-i2);
	else return findKth(next(iter1),e1,b2,e2,k-i1);
}

template<typename I>
int findKth_II(I a, int m, I b, int n, int k) {
	if(m>n) return findKth_II(b,n,a,m,k);
	if(m==0) return *(b+k-1);
	if(k==1) return min(*a,*b);

	int ia = min(k/2,m);
	int ib = k - ia;
	int va = *(a+ia-1);
	int vb = *(b+ib-1);

	if(va==vb) return va;
	else if(va<vb) return findKth_II(a+ia,m-ia,b,n,k-ia);
	else return findKth_II(a,m,b+ib,n-ib,k-ib);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	const auto N = nums1.size() + nums2.size();
	if (N & 1) //odd
		return static_cast<double>(findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), N/2+1));
	else {
			int l = findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), N / 2);
			int r = findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), N/2+1);
			return static_cast<double>(l + r) / 2.0;
		}
}

