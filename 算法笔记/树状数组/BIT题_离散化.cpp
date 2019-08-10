#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i)&(-i)) 
struct Node {
	int val; //����Ԫ�ص�ֵ 
	int pos; //ԭʼ��� 
} temp[maxn]; //temp������ʱ�����������

int A[maxn]; //��ɢ���ԭʼ����
int c[maxn]; //��״����

void update(int x, int v) {
	for(int i=x; i<maxn; i+=lowbit(i)) {
		c[i] += v;
	}
} 

void getSum(int x) {
	for(int i=x; i>0; i-=lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

bool cmp(Node a, Node b) {
	return a.val < b.val;
}

int main() {
	int n;
	scanf("%d", &n);
	memset(c, 0, sizeof(c));  //��״�����ֵΪ0 
	
	for(int i=0; i<n; i++) {
		scanf("%d", &temp[i].val);  //��������Ԫ�� 
		temp[i].pos = i; //ԭʼ��� 
	}
	
	//��ɢ��
	sort(temp, temp+n, cmp);
	
	for(int i=0; i<n; i++) { 
		if(i == 0 || temp[i].val != temp[i-1].val) { //����һ��Ԫ��ֵ��ͬʱ����ֵΪԪ�ظ��� 
			A[temp[i].pos] = i+1;
		} else {  //����һ��ֵ��ͬʱ��ֱ�Ӽ̳� 
			A[temp[i].pos] = A[temp[i-1].pos];
		}
	} 
	
	//��ʽ���������Ͳ��� 
	for(int i=0; i<n; i++) {
		update(A[i], 1);
		printf("%d\n", getSum(A[i]-1));
	} 
	
	return 0;
	
}

