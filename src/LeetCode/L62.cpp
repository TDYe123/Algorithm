/*
һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
������ÿ��ֻ�����»��������ƶ�һ����
��������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
���ܹ��ж�������ͬ��·����
*/
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
	int d[n][m];
	fill(d[0], d[0]+n*m, 0);
	for(int i=0; i<n; i++) 
		d[i][0] = 1;
	for(int i=0; i<m; i++)
		d[0][i] = 1;
	for(int i=1; i<n; i++) {
		for(int j=1; j<m; j++) 
			d[i][j] = d[i][j-1] + d[i-1][j];
	}
	return d[n-1][m-1];
}

int main() {
	printf("%d", uniquePaths(7, 3));
	return 0;
}
