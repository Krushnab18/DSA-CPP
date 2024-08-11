#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isSubstr(string str, string substr) {
	for(int i = 0; i < str.length(); i++) {
		int count = 0;
		int k = 0;
		for(int j = i; k < substr.length() && j < str.length(); j++) {
			if(str[j] == substr[k++]) {
				count++;
			}
		}
		if(count == substr.length()) {
			return true;
		}
	}
	return false;
}

string longestCommonPrefix(vector<string>& str){
	//your code goes here
	for(int j = 0; j < str.size(); j++) {
		for(int i = str[j].length() - 1; i >= 0; i--) {
			string str1 = str[j].substr(0 , i + 1);
			int count = 0;
			for(int k = 0; k < str.size(); k++) {
				if(isSubstr(str[k], str1)) {
					count++;
				}
			}
			if(count == str.size()) {
				return str1;
			}
		}
	}
	return "";
}

int main() {
	string strr;
	int n;
	cin >> n;
	vector<string> str;

	for(int i = 0; i < n; i++) {
		cin>>strr;
		str.push_back(strr);
	}

	for(int i = 0; i < n; i++) {
		cout<<str[i]<<endl;
	}
	
	cout<<longestCommonPrefix(str)<<endl;

	for(int i = 0; i < n; i++) {
		cout<<str[i]<<endl;
	}
	
	string temp;
	cin>>temp;
	cout<<isSubstr("krushna", temp)<<endl;

	return 0;
}
