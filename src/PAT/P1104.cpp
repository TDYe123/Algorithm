#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
int main() {
	double data;
	double ans = 0.0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) { //�ڼ�����������ʱ������ 
		scanf("%lf", &data);
		ans += data*i*(N+1-i); //ans += i*(N+1-i)*data;����������Ե����ԭ��i*(N+1-i)Խ�� 
	} 
	printf("%.2lf\n", ans);
	return 0;
}
