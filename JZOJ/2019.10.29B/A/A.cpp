// A

#include <math.h>

#include <iostream>
using namespace std;

struct __line {
	double xa, ya, xb, yb;
	int a, k;
};

struct __node {
	double x, y;
	double operator-(__node a) {
		return sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
	}
} node[10];

bool _rectangle(int get[4]) {
	__node m;
	m.x = (node[get[0]].x + node[get[1]].x + node[get[2]].x + node[get[3]].x) / 4;
	m.y = (node[get[0]].y + node[get[1]].y + node[get[2]].y + node[get[3]].y) / 4;
	if (node[get[0]] - m == node[get[1]] - m && node[get[1]] - m == node[get[2]] - m && node[get[2]] - m == node[get[3]] - m)
		return true;
	else
		return false;
}

bool _square(int get[4]) {
	if (_rectangle(get)) {
		__node m;
		m.x = (node[get[0]].x + node[get[1]].x + node[get[2]].x + node[get[3]].x) / 4;
		m.y = (node[get[0]].y + node[get[1]].y + node[get[2]].y + node[get[3]].y) / 4;
		for (int i = 1; i < 4; ++i) {
			for (int j = i + 1, o; j <= 4; ++j) {
				for (o = 1; o <= 4 && (o == i || o == j); ++o);
				if ((node[get[i]].y - m.y) / (node[get[i]].x - m.x) == (node[get[j]].y - m.y) / (node[get[j]].x - m.x)) {
					cout << (node[get[i]].y - m.y) / (node[get[i]].x - m.x) << ' ' << (node[get[j]].y - m.y) / (node[get[j]].x - m.x) << ' ';
					cout << (node[get[j]] - node[get[o]]) << ' ' << (node[get[j]] - node[get[o]]) << endl;
				}
			}
		}
	}
	return false;
}



int ch[4], ex[4];

int main() {
	freopen("A.in", "r", stdin);
	for (int i = 1; i <= 8; ++i)
		cin >> node[i].x >> node[i].y;
	for (ch[0] = 1; ch[0] <= 5; ++ch[0]) {
		for (ch[1] = ch[0] + 1; ch[1] <= 6; ++ch[1]) {
			for (ch[2] = ch[1] + 1; ch[2] <= 7; ++ch[2]) {
				for (ch[3] = ch[2] + 1; ch[3] <= 8; ++ch[3]) {
					for (int i = 1, p = 0, t = 0; i <= 8; ++i) {
						if (i == ch[p])++p;
						else if (i != ch[p])ex[t++] = i;
					}
					if (_rectangle(ex) && _square(ch)) {
						cout << "YES" << endl;
						for (int i = 0; i < 4; ++i)
							cout << ch[i] << ' ';
						cout << endl;
						for (int i = 0; i < 4; ++i)
							cout << ex[i] << ' ';
						cout << endl;
						cout << endl;
						// return 0;
					}
				}
			}
		}
	}
	cout << "NO";
	return 0;
}