#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

//	�״�㣺ȱ����������

//	��ֻ������x���ϻ���x���������y�����������棬��ѡһ

//	����Ŀ��Ҫ�ж�ȫ�������������!

bool hexagram[4];	//	�ֱ��ʾ��1��2��3��4����
int hexagramnum;	//	���������
bool specialPoint[4];	//	���ڵ�������������

void init() {
	memset(hexagram, false, sizeof hexagram);
	hexagramnum = 0;
	memset(specialPoint, false, sizeof specialPoint);
}

//	�ж��������ܹ��ɹ�����
bool judge(int x,int y) {
	if (x != 0 && y != 0) {
		if (x > 0 && y > 0) {
			if (hexagram[0]) {
				return true;
			}
			else {
				hexagram[0] = true;
				hexagramnum++;
			}
		}
		else if (x < 0&& y > 0) {
			if (hexagram[1]) {
				return true;
			}
			else {
				hexagram[1] = true;
				hexagramnum++;
			}
		}
		else if (x < 0 && y < 0) {
			if (hexagram[2]) {
				return true;
			}
			else {
				hexagram[2] = true;
				hexagramnum++;
			}
		}
		else if(x>0 && y<0){
			if (hexagram[3]) {
				return true;
			}
			else {
				hexagram[3] = true;
				hexagramnum++;
			}
		}
	}
	else if (x || y) {
		if (x > 0) {
			specialPoint[0] = true;
		}
		else if (x < 0) {
			specialPoint[1] = true;
		}
		else if (y > 0) {
			specialPoint[2] = true;
		}
		else {
			specialPoint[3] = true;
		}
	}

	if (hexagram[0] && hexagram[2]) {
		return false;
	}
	else if (hexagram[1] && hexagram[3]) {
		return false;
	}

	return hexagramnum <= 2;
}

//	��������������ʱ����Ҫ����һ��
bool specialJudge() {
	//	�������������
	if (hexagram[0] && hexagram[1] && !specialPoint[3]) {
		return true;
	}
	else if (hexagram[0] && hexagram[3] && !specialPoint[1]) {
		return true;
	}
	else if (hexagram[1] && hexagram[2] && !specialPoint[0]) {
		return true;
	}
	else if (hexagram[2] && hexagram[3] && !specialPoint[2]) {
		return true;
	}
	else {
		//	�ж�����ĸ���
		return false;
	}
}

bool specialJudges() {
	if (hexagram[0] && specialPoint[1] && specialPoint[3]) {
		return false;
	}
	else if (hexagram[1] && specialPoint[0] && specialPoint[3]) {
		return false;
	}
	else if (hexagram[2] && specialPoint[0] && specialPoint[2]) {
		return false;
	}
	else if (hexagram[3] && specialPoint[1] && specialPoint[2]) {
		return false;
	}
	else {
		return true;
	}
}

bool specialJudegess() {
	bool res = specialPoint[0] && specialPoint[1] && specialPoint[2] && specialPoint[3];
	return !res;
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		init();
		int num;
		bool success = true;
		scanf("%d", &num);
		int x, y;
		for (int i = 0;i < num;i++) {
			scanf("%d%d", &x,&y);	//	�ȴ��������
			if (!judge(x, y)) {
				success = false;
			}
		}
		//	����һ��
		if (!success) {
			cout << "No" << endl;
			continue;
		}

		//	��ռ������������
		if (hexagramnum == 2) {
			if (specialJudge()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else if (hexagramnum == 1) {
			if (specialJudges()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			if (specialJudegess()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}