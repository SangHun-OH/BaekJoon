#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int N;
	double arr[1000];
	double max = 0;
	double sum = 0;
	double avg = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for(int i = 0; i<N;i++){
		
		if (max < arr[i]) {
			max = arr[i];
		}
		
	}
	for (int i = 0; i < N; i++) {
		arr[i] = (arr[i] / max * 100.0);
		sum += arr[i];
	}
	cout << fixed;
	cout.precision(2);
	cout << sum / N << endl;
	
	return 0;

}