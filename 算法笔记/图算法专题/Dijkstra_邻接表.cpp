#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1000;
const int INF = 1000000000;
struct Node {
	int v; //vΪ�ߵ�Ŀ�궥��
	int dis; //disΪ��Ȩ 
}; 
vector<Node> Adj[MAXV]; //ͼG��Adj[u]��ŴӶ���u�������Ե�������ж���
int n; //nΪ��������ͼGʹ���ڽӱ�ʵ�֣�MAXVΪ��󶥵���
int d[MAXV]; //��㵽���������·�� 
bool vis[MAXV] = {false}; //������飬vis[i] == true��ʾ�ѷ��ʡ���ֵ��Ϊfalse

void Dijkstra(int s) { //sΪ��� 
	fill(d, d+MAXV, INF); //fill����������d���鸳ֵΪINF������memset��
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
		vis[u] = true;
		//ֻ���������forѭ�����ڽӾ����д����ͬ
		for(int j=0; j<Adj[u].size(); j++) {
			int v = Adj[u][j].v; //ͨ���ڽӱ�ֱ�ӻ��u�ܵ���Ķ���v
			if(vis[v] == false && d[u] + Adj[u][j].dis < d[v]) {
				//���vδ����&&��uΪ�н�����ʹd[v]����
				d[v] = d[u] + Adj[u][j].dis; //�Ż�d[v] 
			} 
		} 
	}
} 

