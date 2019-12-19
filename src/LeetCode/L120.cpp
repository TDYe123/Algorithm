/*
*����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
���磬���������Σ�
[
	[2],
	[3,4],
	[6,5,7],
	[4,1,8,3]
]

[
	[2],
	[5,4],
	[11,5,7],
	[15,1,8,3]
]
�Զ����µ���С·����Ϊ?11������2+3+5+1= 11����
*/
#include<bits/stdc++.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle) {
	int inf = 10e8, len = triangle.size(), d[len][len], ans = inf;
	fill(d[0], d[0]+len*len, inf);
	d[0][0] = triangle[0][0];
	for(int i=1; i<len; i++) 
		d[i][0] = d[i-1][0] + triangle[i][0];
	for(int i=1; i<len; i++) 
		for(int j=1; j<=i; j++) 
			d[i][j] = min(d[i-1][j-1], d[i-1][j]) + triangle[i][j];
	for(int i=0; i<len; i++) 
		ans = min(ans, d[len-1][i]);
    return ans; 
}

int main() {
	vector<vector<int>> vec = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};
	printf("%d", minimumTotal(vec));
	return 0;
}
