#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//	Date:2023-12-23


int px, py, cx, cy, pd, cd;	//	pd,cd代表人与牛的方向

//	定义状态：人的位置和方向与牛的位置和方向组合为某一个状态数
//	st = 

const int N = 11;
bool st[160005];	//	定义状态
bool isObstacal[N][N];

//	返回st
int getST() {
	return px + 10 * py + 100 * cx + 1000 * cy + 10000 * pd + 40000 * cd;
}

//	判断状态是否合法
bool judge() {
	int res = getST();
	return !st[res];
}

void changeState(int& x,int& y,int& d) {
	//	0代表向北
	int nx = x, ny = y;
	if (d == 0) {
		nx = x - 1;
	}
	else if (d == 1) {
		ny = y + 1;
	}
	else if (d == 2) {
		nx = x + 1;
	}
	else {
		ny = y - 1;
	}

	if (!isObstacal[nx][ny] && nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
		x = nx, y = ny;
	}
	else {
		d = (d + 1) % 4;		
	}
}

int main() {
	int res = 0;
	pd = 0, cd = 0;
	for(int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			char a;
			cin >> a;	//	scanf会读取到'\n'
			if (a == '.') {
				continue;
			}
			else if (a == '*') {
				isObstacal[i][j] = true;
			}
			else if (a == 'F') {
				px = i;
				py = j;
			}
			else if (a == 'C') {
				cx = i;
				cy = j;
			}
		}
	}

	int step = 0;
	bool unsuccess = true;
	//	每次修改方向前先判断状态是否合法

	while (judge()) {
		st[getST()] = true;	//	判断结束后才标记状态
		step++;
		//	改变位置或者状态
		changeState(px, py, pd);
		changeState(cx, cy, cd);
		
		if (px == cx && py == cy) {
			unsuccess = false;
			break;
		}
	}
	
	if (unsuccess) {
		cout << 0;
	}
	else {
		cout << step;
	}

	return 0;
}


