#include <iostream>

using namespace std;

char tolower(char ch) {
   cout<<"ch befor tolower: "<<ch<<endl;
   if(ch >= 'A') {
        ch = ch - 'A' + 'a';
    }
	cout<<ch<<" In the function:"<< endl;
    return ch;
}

 bool isPalindrome(string s) {
       int n = s.size();
       string temp = "";
       for(int i = 0; i < n; i++) {
            if(isalpha(s[i])) {
                temp.push_back(s[i]);
            }
       }
	  // cout<<temp<<endl;
       for(int i = 0;i < temp.length(); i++) {
        //cout<<temp[i]<<endl;
			char ch = temp[i];
			temp[i] = tolower(ch);
		//cout<<tolower(ch)<<endl;
       }
       cout<<temp<<endl;
       int start = 0, end = n - 1;
       while(start < end) {
            if(temp[start] != temp[end]) {
                return false;
            }
            start++;
            end--;
       }
       return true;
}

int main() {
	
	string str;
	cin >> str;
	
/*	while(ch) {
		ch = tolower(ch);
		cout << ch << endl;
		cin >> ch;
	}
*/
	return isPalindrome(str);
}


