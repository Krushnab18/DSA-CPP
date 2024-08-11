#include <iostream>

using namespace std;

int main() {
	char ch[6] = {'a', 'b', '\0', 'c', 'd', '\0'};
	string str = "ab\0cd\0";
	cout<<"CH is: "<<ch<<endl;
	cout<<"STR is: "<<str<<endl;
	cout<<str[3]<<endl;

	return 0;
}
