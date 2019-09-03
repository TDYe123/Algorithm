#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
/*
*dp[j]��ʾ��������<=jʱ����ֵ(����ÿ����������=��ֵ)������δװ������ʼ��ʱdp[0-n] = 0(ǡ��װ��dp[0-n] = INF) 
*/ 
int dp[10010], w[10010];
bool choice[10010][110];
bool cmp(int a, int b) {
	return a>b;
}


int main() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++) 
		cin >> w[i];
	sort(w+1, w+1+n, cmp);
	for(int i=1; i<=n; i++) {
		for(int j=m; j>=w[i]; j--) {
			if(dp[j] <= dp[j-w[i]] + w[i]) {
				choice[i][j] = true;
				dp[j] = dp[j-w[i]] + w[i];
			}
		}
		
		
	}
	if(dp[m] != m)
		cout <<"No Solution" << endl;
	else {
		vector<int> arr;
		int v = m, index = n;
		while(v > 0) {
			if(choice[index][v] == true) {
				arr.push_back(w[index]);
				v -= w[index];
			}
			index--;
		}
		for(int i = 0; i < arr.size(); i++) {
			if(i != 0) 
				printf(" ");
			printf("%d", arr[i]);
		}
	}
	return 0;
}
