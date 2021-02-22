#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	int count = 0;
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str.at(0) == 'O') {
			result++;
			count++;
		}

		for (int j = 1; j < str.size(); j++) {
			if (str.at(j) == 'O') {
				if (str.at(j) == str.at(j - 1)) {
					count++;
					result += count;
				}
				else {
					result++;
					count++;
				}
			}
			else {
				count = 0;
			}
		}
		cout << result << endl;
		result = 0;
		count = 0;
	}
}