#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

const int N = 1e5 + 5;
char str[N];

int Backchar[28];	//	上一个字符出现的位置
int Back[N];

int main() {
	int t;
	cin >> t;

	int res = 0;
	while (t--) {
		int n;
		res = scanf("%d", &n);
		res = scanf("%s", str + 1);

		//	初始化PreChar
		for (int i = 0;i <= 27;i++) {
			Backchar[i] = n + 1;
		}

		for (int i = n;i >= 1;i--) {
			Back[i] = Backchar[str[i] - 'a'];
			Backchar[str[i] - 'a'] = i;
		}
		int cnt = 1;	//	统计次数
		for (int i = 2;i <= n;i++) {
			//	存在两种情况
			if (str[1] == str[i]) {
				cnt++;	//	随其操作不影响
			}
			else {
				cnt += 1 + Back[i] - i;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}