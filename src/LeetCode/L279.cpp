/*����������n���ҵ����ɸ���ȫƽ����������1, 4, 9, 16, ...��
ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�
ʾ��1:
����: n = 12
���: 3 
����: 12 = 4 + 4 + 4.

ʾ�� 2:
����: n = 13
���: 2
����: 13 = 4 + 9.
*/
#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {
	int dp[10010];
	fill(dp, dp+10010, 10e8);
	dp[0] = 0;
	dp[1] = 1;	
	for(int i=2; i<=n; i++) {
		for(int j=1; i-j*j>=0; j++)
			dp[i] = min(dp[i], dp[i-j*j]+1);
	}
	return dp[n];   
}

int main() {
	printf("%d", numSquares(12));
	return 0;
}
 
