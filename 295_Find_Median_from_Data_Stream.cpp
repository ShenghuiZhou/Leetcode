#include <map>
#include <vector>
#include <iostream>

using namespace std;

class MedianFinder {
	private:
		map<int,int> nums;
		pair<int,int> m1, m2;
		bool empty = true;;
	public:
		void addNum(int num) {
			nums[num] += 1; // log(n)
			
			if(empty) {
				m1 = m2 = {num,1};
				empty = false;
				return;
			}
			
			if(m1==m2) {
				if(num>=m1.first) {
					auto iter = nums.find(m2.first); //log(n)
					m2.second += 1;
					if(m2.second>iter->second)
						m2 = {next(iter)->first,1};
				}
				else {
					auto iter = nums.find(m1.first); //log(n)
					m1.second -= 1;
					if(m1.second==0) 
						m1 = *prev(iter);
				}
			}
			else {
				if(num>=m1.first && num<m2.first) {
					auto iter = nums.find(m1.first); //log(n)
					m1.second += 1;
					if(m1.second>iter->second) 
						m1 = {next(iter)->first,1};
					m2 = m1;
				}
				else if(num<m1.first) 
					m2 = m1;
				else 
					m1 = m2;
			}
		}
		
		double findMedian() const {
			return (double(m1.first) + double(m2.first))/2;
		}

		void print_all() const {
			for(const auto p:nums) 
				cout << p.first << " " << p.second << endl;
			cout << "M1: " << m1.first << " " << m1.second << endl;
			cout << "M2: " << m2.first << " " << m2.second << endl;
		}
};


int main() {
	MedianFinder test;
	vector<int> nums = {1,2,3,4,5,6};
	for(auto n:nums) {
		test.addNum(n);
		test.print_all();
		cout << test.findMedian() << endl;
		cout << "----------------------\n";
	}
	

}
