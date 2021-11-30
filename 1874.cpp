#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main() {
	stack<int> s;
	int n;
	string ans;

	cin >> n; //처음에 들어온 입력값
	int m = 0; //스택에 들어간 마지막 값
	while (n--) {
		int x;
		cin >> x; //수열에 들어가는 입력값
		if (x > m) { 
			while(x > m) {
				s.push(++m);
				ans += '+'; //push해준 횟수만큼 pop
			}
			s.pop();
			ans += '-'; //pop
		}
		else { //x가 m보다 크지않으면
			bool found = false;
			if (!s.empty()) {
				if (x == s.top()) { //x가 m과 같아야 스택에서 올바르게 pop될 수 있음(오름차순을 지켜야 하기 때문에)
					found = true; //x과 m(s.top())과 같으면 true
				}
				s.pop();
				ans += '-';
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0; 
			}
		}
	}
	for (auto x : ans) { //ans에서 하나씩 꺼내오자
		cout << x << '\n';
	}
	return 0;
}