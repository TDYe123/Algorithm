#include<bits/stdc++.h>

const int N = 110;
int father[N]; //��Ÿ��׽ڵ� 
bool isRoot[N]; //��¼ÿ���ڵ��Ƿ���Ϊÿ�����ϵĸ��ڵ� 

int findFather(int x) {
	int a = x;
	while(x !=father[x]) {
		x = father[x];
	}
	
	//·��ѹ��
	while(a != father[a]) {
		father[a] = x;
		a = father[a];
	} 
	
	return x;
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	
	if(faA != faB) {
		father[faA] = faB;
	}
}

void init(int n) {
	for(int i=1; i<=n; i++) {
		father[i] = i;
		isRoot[i] = false;
	}
}

int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	init(n);
	for(int i=0; i<m; i++) {
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	
	for(int i=1; i<=n; i++) {
		isRoot[findFather(i)] = true; //i�ĸ��ڵ���findFahter(i) 
	}
	
	int ans = 0; //��¼������Ŀ
	
	for(int i=1; i<=n; i++) {
		ans += isRoot[i];
	} 
	
	printf("%d\n", ans);
	return 0;
} 
