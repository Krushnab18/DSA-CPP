#include <iostream>
#include <string>
using namespace std;

bool isSubstring(string s, string sub) {
	for(int i = 0; i <= (s.length() - sub.length()); i++) {
		int j = 0, k = i;
		int count = 0;
		while(j < sub.length()) {
			if(s[k] == sub[j]) {
				count++;
			}
			j++;
			k++;
		}
		if(count == sub.length()) {
			return true;
		}
	}
	return false;
}

string removeOccurrences(string s, string part) {
	while(isSubstring(s, part)) {
		for(int i = 0; i <= (s.length() - part.length()); i++) {
			int j = 0, k = i;
			int count = 0;
			while(j < part.length()) {
				if(s[k] == part[j]) {
					count++;
				}
				j++;
				k++;
			}
			if(count == part.length()) {
				if(i + part.length() > s.length()){
					return s;
				}
				s.erase(i, part.length());
			}
		}
	}
	return s;
}

int main() {
	string ch;
	cin>>ch;
	string part;
	cin>>part;

	cout<<removeOccurrences(ch, part);
	return 0;
}
	
