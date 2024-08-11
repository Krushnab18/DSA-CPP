#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrong(int n) {
       int sum = 0;
       int num = 0;
       int tempn = n;
       while(tempn) {
        num++;
        tempn /= 10;
       }
		
		cout<<num<<endl;
		
		int nk = n;
       while(n) {
        int lastDigit = n % 10;
            sum += pow(lastDigit, num);
            n /= 10;
       }

        if(sum == nk) {
            return true;
        }
		cout<<sum<<endl;
        return false;
    }

int main() {
	int n;
	cin >> n;
	cout<<isArmstrong(n);
	return 0;
}
