#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510; //��󶥵���
const int INF = 1000000000; //��INFΪһ���ܴ���� 

int n, m, start, end, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
int d[MAXV]; //��㵽���������·������
bool vis[MAXV] = {false}; //������飬vis[i] = true��ʾ�ѷ��ʡ���ֵ��Ϊfalse
int num[MAXV]; //�����s���ﶥ��u�����·������Ϊnum[u]����ʼ��ʱֻ��num[s]Ϊ1������num[u]��Ϊ0 
int weight[MAXV];
int w[MAXV];

void Dijkstra(int s) { //sΪ��� 
	fill(d, d+MAXV, INF); //fill����������d���鸳ֵΪINF������memset��
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	d[s] = 0;
	num[s] = 1;
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
				if(d[u] + G[u][v] < d[v]) { //��uΪ�н����ʹd[v]����
					d[v] = d[u] + G[u][v]; 
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				} else if(d[u] + G[u][v] == d[v]){
					if(w[u] + weight[v] > w[v]) {
						w[v] = w[u] + weight[v]; 
					}
					num[v] += num[u]; //���·����ͬʱ�ۼ�num 
				}
				
			} 
		} 
	} 
} 

int main() {
	scanf("%d%d%d%d", &n, &m, &start, &end);
	for(int i=0; i<n; i++) {
		scanf("%d", &weight[i]);
	}
	//��ʼ��ͼ
	fill(G[0], G[0] + MAXV*MAXV, INF); //��ʼ��ͼ��û�еı߼�ΪINF 
	int u, v;
	for(int i=0; i<m; i++) {
		scanf("%d%d", &u, &v);
		scanf("%d", &G[u][v]);
		G[v][u] = G[u][v];	
	}
	Dijkstra(start);
	printf("%d %d\n", num[end], w[end]);
	return 0;
}	
		 
