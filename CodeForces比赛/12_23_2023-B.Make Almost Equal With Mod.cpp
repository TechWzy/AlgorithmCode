#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

int cnt;	//	统计mod的个数
const int N = 102;
long long element[N];
map<long long, int>m;

int main() {
	int n;
	cin >> n;

	//	单独一个测试案例的时间复杂度为(nlogn)
	while (n--) {
		int t;
		cin >> t;

		for (int i = 1;i <= t;i++) {
			scanf("%lld", &element[i]);
		}

		//	外层初始化
		long long k = 1;
		cnt = 0;

		while (cnt != 2) {
			m.clear();	//	初始化
			k *= 2;
			cnt = 0;
			for (int i = 1;i <= t;i++) {
				//	该余数mod未曾出现过
				if (!m[element[i] % k]) {
					m[element[i] % k] = true;
					cnt++;
					if (cnt > 2) {
						break;
					}
				}
			}
		}
		cout << k << endl;
	}

	return 0;
} 