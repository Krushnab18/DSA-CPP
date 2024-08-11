#include <iostream>

using namespace std;

bool isValid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }

bool ispalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


bool isPalindrome(string s) {
    string temp = "";
    char ch;
    for(int i = 0; i < s.length(); i++) {
        ch = s[i];
		cout<<" "<<ch;
        if(isValid(ch)) {
            temp.push_back(ch);
        }
	}
    return ispalindrome(temp);
}

int main() {
	string str;
	cin.getline(str);
	cout<<isPalindrome(str)<<endl;
	return 0;
	}
