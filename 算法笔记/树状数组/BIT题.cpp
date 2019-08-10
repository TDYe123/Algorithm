/*ͳ����������Ԫ����߱ȸ�Ԫ��С��Ԫ�ظ��� 
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
#define lowbit(i) ((i) & (-i))
int c[maxn]; //��״����
//update��������x����������v 
void update(int x, int v) {
	for(int i=x; i<maxn; i+=lowbit(i)) {  //i<maxn����i<=n������ 
		c[i] += v;  //��c[i]����c��Ȼ����c[i+lowbit(i)]����v 
	}
} 
//getSum��������ǰx������֮��
int getSum(int x) {
	int sum = 0;
	for(int i=x; i>0; i-=lowbit(i)) {  //ע����i>0������i>=0 
		sum += c[i];
	}  //�ۼ�c[i],Ȼ���������СΪSUM(1, i-lowbit(i)) 
	return sum;  //���غ� 
} 
int main() {
	int n, x;
	scanf("%d", &n);
	memset(c, 0, sizeof(c)); //��״�����ֵΪ0
	for(int i=0; i<n; i++) {
		scanf("%d", &x); //��������Ԫ��
		update(x, 1);  //x�ĳ��ִ�����1
		printf("%d\n", getSum(x-1)); 
	} 
	return 0;
} 
