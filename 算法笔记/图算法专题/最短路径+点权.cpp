#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000; //��󶥵���
const int INF = 1000000000; //��INFΪһ���ܴ����  

int n, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
int d[MAXV]; //��㵽���������·������
bool vis[MAXV] = {false}; //������飬vis[i] = true��ʾ�ѷ��ʡ���ֵ��Ϊfalse
int weight[MAXV]; //��weight[u]��ʾ����u�е�������Ŀ������Ŀ���룩
int w[MAXV]; //������s����u�����ռ������������Ϊw[u]����ʼ��ʱֻ��w[s]Ϊweight[s]������w[u]��Ϊ0
 

void Dijkstra(int s) { //sΪ��� 
	fill(d, d+MAXV, INF); //fill����������d���鸳ֵΪINF������memset��
	memset(w, 0, sizeof(w));
	d[s] = 0;
	w[s] = weight[s];
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
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[u]) { //��uΪ�н����ʹd[v]����
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
				} else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]) {
					w[v] = w[u] + weight[v]; //������ͬʱ���ܷ�ʹw[v]���� 
				}
			} 
		} 
	} 
} 
