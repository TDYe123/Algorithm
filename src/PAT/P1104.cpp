#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
	float data;
	float ans = 0;
	int cnt = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) { //�ڼ�����������ʱ������ 
		scanf("%f", &data);
		for(int j=1; j<=N; j++) { //���䳤�� 
			if(i>=j) 
				cnt = min(N-i+1, j);
			else 
				cnt = min(N-j+1, i);
			ans += data*cnt;
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
