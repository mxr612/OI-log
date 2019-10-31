#include <iostream>
using namespace std;

int now = 0, ans = 0;

/**
 * 变量说明
 * now记录当前好感度
 * ans记录答案总数
 */

void dfs_common(int c) {//递归普通场景c记录当前层数
	if (c == 6) {//递归结束条件(进了五次)
		if (now >= 5) {//检查好感度是否大于等于5
			ans++;
			// cout<<now<<endl;//输出当前好感值
			
		}
		return ;
	}
	now+=1;//记录
	dfs_common(c+1);//递归进入下一层
	now-=1;//回溯now
	now-=1;//记录
	dfs_common(c+1);//递归进入下一层
	now+=1;//回溯now
}

void dfs_good(int c) {//递归浪漫场景c记录当前层数
	if (c == 5) {//递归结束条件（进了四次）
		dfs_common(1);//结束浪漫场景后进入普通场景
		return ;
	}
	now+=2;//记录
	dfs_good(c+1);//递归进入下一层
	now-=2;//回溯now
	dfs_good(c+1);//递归进入下一层
}



int main(int argc, char const *argv[])
{
	dfs_good(1);//进入递归
	cout<<ans;//输出答案
	return 0;
}