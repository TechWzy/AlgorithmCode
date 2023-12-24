#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

//	易错点：缺乏分类讨论

//	点只能落在x轴上或者x轴下面或者y轴的左面或右面，四选一

//	本题目需要判断全部点才能输出结果!

bool hexagram[4];	//	分别表示第1，2，3，4卦象
int hexagramnum;	//	卦象的数量
bool specialPoint[4];	//	存在点在坐标轴上面

void init() {
	memset(hexagram, false, sizeof hexagram);
	hexagramnum = 0;
	memset(specialPoint, false, sizeof specialPoint);
}

//	判断三个键能够成功操作
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

//	当出现两个卦象时，需要特判一下
bool specialJudge() {
	//	分四种情况特判
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
		//	判断卦象的个数
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
			scanf("%d%d", &x,&y);	//	等待输入完成
			if (!judge(x, y)) {
				success = false;
			}
		}
		//	特判一下
		if (!success) {
			cout << "No" << endl;
			continue;
		}

		//	点占用了两个卦象
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