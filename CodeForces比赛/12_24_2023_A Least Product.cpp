#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//	��һ��ò�ƺܼ�

//	��ĺܼ򵥣�����
const int N = 105;
int arr[N];

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		scanf("%d", &n);

		int negative = 0;
		bool isZero = false;
		for (int i = 1;i <= n;i++) {
			scanf("%d", &arr[i]);
			if (arr[i] < 0) {
				negative++;
			}
			else if (arr[i] == 0) {
				isZero = true;
			}
		}
		if (isZero || negative % 2 == 1) {
			printf("%d\n", 0);
		}
		else {
			printf("1\n");
			printf("1 0\n");
		}
	}
	return 0;
}