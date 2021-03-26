#include <iostream>
using namespace std;

int main() {	
	int a;
	cin >> a;
	if (a >= 90)
		cout << 'A';
	else if (90 > a && a >= 80)
		cout << 'B';
	else if (80 > a && a>= 70)
		cout << 'C';
	else if (70 > a && a >= 60)
		cout << 'D';
	else
		cout << 'F';
}
