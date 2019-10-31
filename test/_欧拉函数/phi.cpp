#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_INT 100000

//直接求解欧拉函数
int _PhiS(int n) {
    //返回euler(n)
    int res = n, a = n;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            res = res / i * (i - 1); //先进行除法是为了防止中间数据的溢出
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res = res / a * (a - 1);//若n是质数
    return res;
}

int euler[MAX_INT];
void Init(int Max) {//O(NlgN)
    for (int i = 1; i <= Max; i++)
        euler[i] = i;
    for (int i = 2; i <= Max; i++)
        if (euler[i] == i)//若是素数
            for (int j = i; j <= Max; j += i)//更改所有phi[i]
                euler[j] = euler[j] / i * (i - 1); //先进行除法是为了防止中间数据的溢出
}

int phi[MAX_INT], prime[MAX_INT] , mark[MAX_INT] = {0}, tot = 0;//答案phi 存放质数 标记质数 当前质数个数
void _PhiF(int N) {//O(NlgN) <N的素数只有lgN个
    int i, j;
    phi[1] = 1;
    for (i = 2; i <= N; i++) { //相当于分解质因式的逆过程
        if (!mark[i]) {//若i为素数
            prime[++tot] = i; //筛素数的时候首先会判断i是否是素数。
            phi[i] = i - 1; //当 i 是素数时 phi[i]=i-1
        }
        for (j = 1; j <= tot && i * prime[j] <= N; j++) {
            mark[i * prime[j]] = 1; //标记非素数
            if (i % prime[j] == 0) {//接着我们会看prime[j]是否是i的约数
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            //其实这里prime[j]-1就是phi[prime[j]]，利用了欧拉函数的积性
        }
    }
}

int main() {
    _PhiF(12345);
    Init(12345);
    printf("%10d%10d\n", euler[12345], phi[12345]);

    return 0;
}

