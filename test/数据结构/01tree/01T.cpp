// 01Tree

#include <iostream>
using namespace std;

#define MAX 1000

#define lowbit(n) ((n)&(-n))
int tree_sum(int tree[],int end);
void tree_update(int arr[],int tree[],int size,int node,int val);
void build_tree(int arr[],int tree[],int size);
#define between(arr,tree,L,R) (tree_sum(arr,tree,R)-tree_sum(arr,tree,L-1))



int main() {
	freopen("01T.in", "r", stdin);

	int size;
	int arr[MAX]={0}, tree[MAX]={0};

	cin>>size;
	for(int i=1;i<=size;i++){
		cin>>arr[i];
	}
	build_tree(arr,tree,size);
	tree_update(arr,tree,size,2,-1);
	cout<<tree_sum(tree,3);
	return 0;
}

int tree_sum(int tree[],int end){//01分解，1101->1100->1000
	int ans=0;
	for(;end>0;end-=lowbit(end)){
		ans+=tree[end];
	}
	return ans;
}

void tree_update(int arr[],int tree[],int size,int node,int val){//自下而上加差值
	int temp=val-arr[node];
	arr[node]=val;
	for(;node<=size;node+=lowbit(node)){
		tree[node]+=temp;
	}
}

void build_tree(int arr[],int tree[],int size){//初始化0，自下而上加arr
	for(int i=1;i<=size;i++){
		for(int n=i;n<=size;n+=lowbit(n)){
			tree[n]+=arr[i];
		}
	}
}
