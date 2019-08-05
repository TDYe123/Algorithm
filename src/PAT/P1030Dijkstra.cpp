#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510; //��󶥵���
const int INF = 1000000000; //��INFΪһ���ܴ���� 

int n, m, st, ed, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
int d[MAXV]; //��㵽���������·������
bool vis[MAXV] = {false}; //������飬vis[i] = true��ʾ�ѷ��ʡ���ֵ��Ϊfalse
int cost[MAXV][MAXV]; //cost[u][v]��ʾu->v�Ļ���
int c[MAXV]; //������s���ﶥ��u�����ٻ���Ϊc[u]����ʼ��ʱֻ��c[s]=0������c[u]��ΪINF 
int pre[MAXV];

void Dijkstra(int s) { //sΪ��� 
	fill(d, d+MAXV, INF); //fill����������d���鸳ֵΪINF������memset��
	fill(c, c+MAXV, INF);
	for(int i=0; i<n; i++)
		pre[i] = i;
	d[s] = 0;
	c[s] = 0;
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
				if(d[u] + G[u][v] < d[v]) { //��uΪ�н����ʹd[v]���� 
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				} else if(d[u] + G[u][v] == d[v]) { //��̾�����ͬʱ���ܷ�ʹc[v]���� 
					if(c[u] + cost[u][v] < c[v]) {
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}	
				} 
			} 

		} 
	} 
} 

void DFS(int v) { //sΪ����ţ�vΪ��ǰ���ʵĶ����ţ����յ㿪ʼ�ݹ飩 
	if(v == st) { //�����ǰ�Ѿ��������s���������㲢����
		printf("%d ", v);
		return; 
	} 
	DFS(pre[v]); //�ݹ����v��ǰ������pre[v]
	printf("%d ", v); 
} 

int main() {
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	int u, v;
	fill(G[0], G[0]+MAXV*MAXV, INF); //��ʼ��ͼG
	//fill(cost[0], cost[0]+MAXV*MAXV, INF); 
	for(int i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d%d", &G[u][v], &cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n", d[ed], c[ed]);
}