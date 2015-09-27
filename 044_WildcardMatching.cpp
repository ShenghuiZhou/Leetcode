#include <string>
using namespace std;

bool isMatch(const char *s, const char *p) {
	bool flag = false;
	auto ss = s, pp = p;
	while(*s!='\0') {
		if(*p!='*') {
			if(*s==*p || *p=='?') {
				++s;
				++p;
			}
			else {
				if(!flag) return false;
				else {
					ss = ss+1;
					s = ss;
					p = pp;
				}
			}
		}

		else {
			flag = true;
			ss = s;
			pp = p+1;
			s = ss;
			p = pp;
		}
	}
	while(*p=='*') ++p;
	return *p == '\0';
}

bool isMatch(string s, string p) {
	return isMatch(s.c_str(),p.c_str());
}
