// T37785 worries

#include <stdio.h>

#define MAX_CHAR 1000
const char game[] = "started playing games!\n";
const char come[] = "came!\n";
const char left[] = "left!\n";

int N;
bool stu[5] = {0}, tea[3] = {0}, fx[5] = {0};
char T[3][MAX_CHAR], S[5][MAX_CHAR];
char mas[MAX_CHAR];

bool com();
void cheak();

int main(int argc, char const *argv[])
{

	freopen("worries.in", "r", stdin);
	scanf("%d", &N);
	scanf("%s %s %s", T[0], T[1], T[2]);
	scanf("%s %s %s %s %s", S[0], S[1], S[2], S[3], S[4]);
	for (int i = 1; i <= N; i++) {
		scanf("%s", mas);
		cheak();
	}
	if(fx[0]==0&&fx[1]==0&&fx[2]==0&&fx[3]==0&&fx[4]==0){
		printf("How Good Oiers Are!");
	}
	if(fx[0]==1&&fx[1]==1&&fx[2]==1&&fx[3]==1&&fx[4]==1){
		printf("How Bad Oiers Are!", );
	}
	return 0;
}

bool com() {
	bool CkStu[5] = {0}, CkTea[3] = {0};
	int br = 8;
	for (int i = 0; mas[i] != ' ' && br > 0; i++) {
		for (int j = 0; j < 3; j++) {
			if (mas[i] != T[j][i] && CkTea[j] == 0) {
				br--;
				CkTea[j] = 1;
			}
		}
		for (int j = 0; j < 5; j++) {
			if (mas[i] != S[j][i] && CkStu[j] == 0) {
				br--;
				CkStu[j] = 1;
			}
		}
	}

	return 0;
}

void cheak() {

}
