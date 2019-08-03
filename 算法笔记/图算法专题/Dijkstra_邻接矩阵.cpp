#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000; //��󶥵���
const int INF = 1000000000; //��INFΪһ���ܴ���� 

int n, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
int d[MAXV]; //��㵽���������·������
bool vis[MAXV] = {false}; //������飬vis[i] = true��ʾ�ѷ��ʡ���ֵ��Ϊfalse

void Dijkstra(int s) { //sΪ��� 
	fill(d, d+MAXV, INF); //fill����������d���鸳ֵΪINF������memset��
	d[s] = 0;
	for(int i=0; i<n; i++) { //ѭ��n��
		int u = -1, MIN = INF; //uʹd[u]��С��MIN��Ÿ���С��d[u]
		for(int j=0; j<n; j++) { //�ҵ�δ���ʵĶ�����d[]��С��
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			} 			
		} 
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u == -1)
			return;
		vis[u] = true; //���uΪ�ѷ���
		for(int v=0; v<n; v++) {
			//���vδ���� && u�ܵ���v && ��uΪ�н����ʹd[v]����
			if(vis[v] == false && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v]; //�Ż�d[v] 
			} 
		} 
	} 
} 
