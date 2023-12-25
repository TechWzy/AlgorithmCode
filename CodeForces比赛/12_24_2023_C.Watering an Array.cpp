#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//	本题目只允许使用暴力算法

const int N = 2005;
const int M = 1e5 + 5;
int a[N], K[M];

int main() {
	int t;
	cin >> t;

	int res = 0;
	while (t--) {
		int result = 0;	//	记录最大值
		int n, k, d;
		res = scanf("%d%d%d", &n, &k, &d);

		for (int i = 1;i <= n;i++) {
			res = scanf("%d", &a[i]);
		}

		for (int i = 0;i < k;i++) {
			res = scanf("%d", &K[i]);
		}

		int cnt = 0;
		//	假设下一次便执行第二次操作
		for (int i = 1;i <= n;i++) {
			if (a[i] == i) {
				cnt++;
			}
		}

		result = max(result, cnt + (d - 1) / 2);

		for (int day = 0;day < d;day++) {
			//	在第day+1天更新result
			result = max(result, cnt + (d - day - 1) / 2);

			//	保险做法
			if (day + 1>= 2*n) {
				break;
			}

			cnt = 0;
			//	更新节点
			int node = K[day % k];
			for (int i = 1;i <= node;i++) {
				a[i] += 1;
				if (i == a[i]) {
					cnt++;
				}
			}

			for (int i = node + 1;i <= n;i++) {
				if (i == a[i]) {
					cnt++;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}