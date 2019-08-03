#include<bits/stdc++.h>
using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n; //�ڵ����� 
int m; //���� 
int start, end;
int G[MAXV][MAXV];
int d[MAXV];
vector<int> pre[MAXV]; //��Žڵ��ǰ���ڵ� 
int vis[MAXV] = {false};
int optValue = INF; //�ڶ��������ֵ 
vector<int> path, tempPath; //����·������ʱ·�� 

int V[MAXV][MAXV]; //��Ȩ 

void Dijkstra(int s) { //sΪ���
	fill(d, d+MAXV, INF);
	d[s] = 0;
	for(int i=0; i<n; i++) { //ѭ��n�� 
		int u = -1, MIN = INF;
		for(int j=0; j<n; j++) {
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		} 
		if(u == -1)
			return;
		vis[u] = true;
		for(int v=0; v<n; v++) {
			if(vis[v] == false && G[u][v] != INF) {
				if(d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v]; //�Ż�d[v]
					pre[v].clear(); //���pre[v]
					pre[v].push_back(u); //��v��ǰ��Ϊu 
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u); //��v��ǰ��Ϊu 
				}
			}
		}
	} 	
}

void DFS(int v) { //vΪ��ǰ���ʽڵ� 
	//�ݹ�߽� 
	if(v == start) { //���������Ҷ�ӽڵ�start����·������㣩
		tempPath.push_back(v);  //�������start������ʱ·��tempPath�������
		int value = 0; //�����ʱ·��tempPath�ĵڶ���ߵ�ֵ
		//����tempPath�ϵ�valueֵ
		
		//��Ȩ֮�� 
		for(int i=tempPath.size()-1; i>0; i--) { //������ʽڵ㣬ѭ������Ϊi>0
			//��ǰ�ڵ�id����һ�ڵ�idNext
			int id = tempPath[i], idNext = tempPath[i-1];
			value += V[id][idNext]; //value���ӱ�id->idNext�ı�Ȩ 	
		} 
		
		if(value < optValue) { //�����ǰֵ��������ֵ 
			optValue = value; //���µڶ��������ֵ������·��
			path = tempPath; 
		}
		tempPath.pop_back(); //���ռ���Ľڵ�ɾ��
		return;
	}
	
	//�ݹ�ʽ
	tempPath.push_back(v); //����ǰ���ʽڵ������ʱ·��tempPath�������
	for(int i=0; i<pre[v].size(); i++) {
		DFS(pre[v][i]); //�ڵ�v��ǰ���ڵ�pre[v][i]���ݹ� 
	} 
	tempPath.pop_back(); //����������ǰ���ڵ㣬����ǰ�ڵ�vɾ�� 
} 

int main() {
	scanf("%d%d%d%d", &n, &m, &start, &end);
	int from, to, dis, cost;
	fill(G[0], G[0]+MAXV*MAXV, INF); //��ʼ��ͼG
	fill(V[0], V[0]+MAXV*MAXV, INF); 
	for(int i=0; i<m; i++) {
		scanf("%d%d%d%d", &from, &to, &dis, &cost);
		G[from][to] = G[to][from] = dis;
		V[from][to] = V[to][from] = cost;
	}
	
	
	Dijkstra(start);
	DFS(end);
	for(int i=path.size()-1; i>=0; i--) {
		printf("%d ", path[i]);
	} 
	printf("%d %d\n", d[end], optValue);
	return 0;	
}
