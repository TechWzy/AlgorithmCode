#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//	����Ŀֻ����ʹ�ñ����㷨

const int N = 2005;
const int M = 1e5 + 5;
int a[N], K[M];

int main() {
	int t;
	cin >> t;

	int res = 0;
	while (t--) {
		int result = 0;	//	��¼���ֵ
		int n, k, d;
		res = scanf("%d%d%d", &n, &k, &d);

		for (int i = 1;i <= n;i++) {
			res = scanf("%d", &a[i]);
		}

		for (int i = 0;i < k;i++) {
			res = scanf("%d", &K[i]);
		}

		int cnt = 0;
		//	������һ�α�ִ�еڶ��β���
		for (int i = 1;i <= n;i++) {
			if (a[i] == i) {
				cnt++;
			}
		}

		result = max(result, cnt + (d - 1) / 2);

		for (int day = 0;day < d;day++) {
			//	�ڵ�day+1�����result
			result = max(result, cnt + (d - day - 1) / 2);

			//	��������
			if (day + 1>= 2*n) {
				break;
			}

			cnt = 0;
			//	���½ڵ�
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