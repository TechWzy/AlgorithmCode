#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

int cnt;	//	ͳ��mod�ĸ���
const int N = 102;
long long element[N];
map<long long, int>m;

int main() {
	int n;
	cin >> n;

	//	����һ�����԰�����ʱ�临�Ӷ�Ϊ(nlogn)
	while (n--) {
		int t;
		cin >> t;

		for (int i = 1;i <= t;i++) {
			scanf("%lld", &element[i]);
		}

		//	����ʼ��
		long long k = 1;
		cnt = 0;

		while (cnt != 2) {
			m.clear();	//	��ʼ��
			k *= 2;
			cnt = 0;
			for (int i = 1;i <= t;i++) {
				//	������modδ�����ֹ�
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