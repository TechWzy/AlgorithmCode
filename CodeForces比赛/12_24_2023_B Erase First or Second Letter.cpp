#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int N = 1e5 + 5;
char str[N];

int Backchar[28];	//	��һ���ַ����ֵ�λ��
int Back[N];

int main() {
	int t;
	cin >> t;

	int res = 0;
	while (t--) {
		int n;
		res = scanf("%d", &n);
		res = scanf("%s", str + 1);

		//	��ʼ��PreChar
		for (int i = 0;i <= 27;i++) {
			Backchar[i] = n + 1;
		}

		for (int i = n;i >= 1;i--) {
			Back[i] = Backchar[str[i] - 'a'];
			Backchar[str[i] - 'a'] = i;
		}
		int cnt = 1;	//	ͳ�ƴ���
		for (int i = 2;i <= n;i++) {
			//	�����������
			if (str[1] == str[i]) {
				cnt++;	//	���������Ӱ��
			}
			else {
				cnt += 1 + Back[i] - i;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}