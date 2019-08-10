#include<stdio.h>
#include<math.h>
const int maxn = 10000;

int pre[maxn] = {0}, tree[4*maxn] = {0}, ans[maxn] = {0};

void BuildTree(int n, int last_left) { //����ȫ��������һ���߶���
	for(int i=last_left; i<last_left+n; i++) //�������������һ�и�ֵ�����n���ڵ�Ϊnͷţ
		tree[i] = 1; 
	while(last_left != 1) { //�Ӷ����������һ�е��Ƶ����ڵ㣬���ڵ��ֵ��nͷţ
		for(int i=last_left/2; i<last_left; i++)
			tree[i] = tree[i*2] + tree[i*2+1];
		last_left = last_left/2; 
	}
} 

int query(int u, int num, int last_left) {
	tree[u]--;
	if(tree[u] == 0 && u >= last_left) //**u>=last_left
		return u;
	if(tree[u<<1] < num) 
		return query((u<<1)+1, num-tree[u<<1], last_left);
	if(tree[u<<1] >= num)
		return query(u<<1, num, last_left);
}

int main() {
	int n, last_left;
	scanf("%d", &n);
	last_left = 1<<(int(log(n)/log(2)) + 1);
	pre[1] = 0;
	for(int i=2; i<=n; i++)
		scanf("%d", &pre[i]);
	BuildTree(n, last_left);
	for(int i=n; i>=1; i--)
		ans[i] = query(1, pre[i]+1, last_left) - last_left + 1;
	for(int i=1; i<=n; i++)
		printf("%d\n", ans[i]);
	return 0;
}


