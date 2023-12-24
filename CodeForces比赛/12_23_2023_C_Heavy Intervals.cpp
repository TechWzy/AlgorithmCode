#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//	ע����������...

//	����ջ
const int N = 1e5 + 5;
long long linterval[N], rinterval[N], cinterval[N];
vector<long long>vec;
int num;

long long Process() {
	long long* que = new long long[N];
	int tt = 0;
	int j = 0;	//	����rinterval

	//	����ջ
	for (int i = 0;i < num;i++) {
		if (linterval[i] > rinterval[j]) {
			//	ȡ��ջ��Ԫ��
			vec.push_back(rinterval[j] - que[tt]);
			j++, tt--, i--;
		}
		else {
			que[++tt] = linterval[i];
		}
	}

	//	��С�������que
	j = num - 1;
	for (int i = 1;i <= tt;i++) {
		vec.push_back(rinterval[j] - que[i]);
		j--;
	}

	//	��vec����
	sort(vec.begin(), vec.end());

	long long sum = 0;
	for (int i = 0;i < num;i++) {
		sum += cinterval[i] * vec[num - i - 1];
	}
	delete []que;
	return sum;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> num;
		vec.clear();
		vec.resize(0);
		for (int i = 0;i < num;i++) {
			scanf("%d", &linterval[i]);
		}
		for (int i = 0;i < num;i++) {
			scanf("%d", &rinterval[i]);
		}
		for (int i = 0;i < num;i++) {
			scanf("%d", &cinterval[i]);
		}

		//	����
		sort(linterval, linterval + num);
		sort(rinterval, rinterval + num);
		sort(cinterval, cinterval + num);
		cout << Process() << endl;
	}
	return 0;
}