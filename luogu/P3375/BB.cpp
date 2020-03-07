#include<iostream>
#include<cstring>
#define MAXN 1000010
using namespace std;
int kmp[MAXN];
int la, lb, j;
char a[MAXN], b[MAXN];
int main()
{
  freopen("P3375_11.in", "r", stdin);
  cin >> a + 1;
  cin >> b + 1;
  la = strlen(a + 1);
  lb = strlen(b + 1);
  for (int i = 2; i <= lb; i++)
  {
    while (j && b[i] != b[j + 1]) j = kmp[j];
    if (b[j + 1] == b[i])j++;
    kmp[i] = j;
  }
  j = 0;
  for (int i = 1; i <= la; i++)
  {
    while (j > 0 && b[j + 1] != a[i])j = kmp[j];
    if (b[j + 1] == a[i])j++;
    if (j == lb) {cout << i - lb + 1 << endl; j = kmp[j];}
  }

  for (int i = 1; i <= lb; i++)
    cout << kmp[i] << " ";
  return 0;
}