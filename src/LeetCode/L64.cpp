/*
*����һ�������Ǹ������� mxn����
���ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����
ʾ��:
����:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 7
����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
*/ 
#include<bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    //ֻ�������ߡ�������
    int inf = 100;
	int xlen = grid.size(), ylen = grid[0].size();
	vector<vector<int>> d;
    for(int i=0; i<xlen; i++) {
    	vector<int> t;
    	for(int j=0; j<ylen; j++) {
    		t.push_back(inf);
		}
    	d.push_back(t);
	}
	d[0][0] = grid[0][0];
	for(int i=1; i<xlen; i++) 
		d[i][0] = d[i-1][0] + grid[i][0];
	for(int j=1; j<ylen; j++) 
		d[0][j] = d[0][j-1] + grid[0][j];
	for(int i=1; i<xlen; i++) 
		for(int j=1; j<ylen; j++) 
			d[i][j] = min(d[i-1][j], d[i][j-1]) + grid[i][j]; 
	return d[xlen-1][ylen-1];	   
}

int main() {
	vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	printf("%d", minPathSum(grid)); 
	return 0;
}
