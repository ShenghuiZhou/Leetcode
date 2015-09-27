#include <string> 

using namespace std;


bool isMatch(const char *s, const char *p) {
	if(*p=='\0') return *s=='\0';
	if(*(p+1)!='*') {
		if(*s==*p || *p=='.') return isMatch(s+1,p+1);
		else return false;
	}
	else {
		while(*s!='\0') {
			if(isMatch(s,p+2)) return true;
			else if(*s!=*p && *p!='.') return false;
			++s;
		}
		while(*p=='*') ++p;
		return *p=='\0';
	}
}

bool isMatch(string s, string p) {
	return isMatch(s.c_str(), p.c_str());
}
