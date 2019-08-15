#include<bits/stdc++.h>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;
int n, k; //�ڵ����� ���ߵ����� 
int G[MAXV][MAXV];
int vis[MAXV] = {false};
int d[MAXV];

vector<int> pre[MAXV]; //��Žڵ��ǰ���ڵ� 
vector<int> path, tempPath; //����·������ʱ·�� 
int W[MAXV]; //��Ȩ =>happiness
int optValue; //�ڶ��������ֵ 

int num[MAXV]; //�����s���ﶥ��u�����·������Ϊnum[u]����ʼ��ʱֻ��num[s]Ϊ1������num[u]��Ϊ0 

int st, ed;

map<string, int> mp;

void Dijkstra(int s) { //sΪ���
	d[s] = 0;
	memset(num, 0, sizeof(num));
	num[s] = 1;
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
					num[v] = num[u];
					pre[v].clear(); //���pre[v]
					pre[v].push_back(u); //��v��ǰ��Ϊu 
				} else if(d[u] + G[u][v] == d[v]) {
					pre[v].push_back(u); //��v��ǰ��Ϊu 
					num[v] += num[u];
				}
			}
		}
	} 	
}

void DFS(int v) { //vΪ��ǰ���ʽڵ� 
	//�ݹ�߽� 
	if(v == st) { //���������Ҷ�ӽڵ�start����·������㣩
		tempPath.push_back(v);  //�������start������ʱ·��tempPath�������
		int value = 0; //�����ʱ·��tempPath�ĵڶ���ߵ�ֵ
		//����tempPath�ϵ�valueֵ
		
		//��Ȩ֮��
		for(int i=tempPath.size()-1; i>=0; i--) { //������ʽڵ㣬ѭ������Ϊi>=0
			//��ǰ�ڵ�id����һ�ڵ�idNext
			int id = tempPath[i];
			value += W[id]; //value���ӱ�id�ĵ�Ȩ 	
		}  
		
		if(value > optValue) { //�����ǰֵ��������ֵ 
			optValue = value; //���µڶ��������ֵ������·��
			path = tempPath; 
		} else if(value == optValue) {
			if(tempPath.size() < path.size())
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

string int2str(int n) {
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if(it->second == n) 
			return it->first;
	}
}

int main() {
	string address;
	int happiness;
	scanf("%d %d", &n, &k);
	getchar();
	cin >> address;
	mp[address] = 0;
	W[0] = 0;
	st = 0;
	for(int i=1; i<n; i++) {
		cin >> address >> happiness;
		mp[address] = i;
		if(address == "ROM")
			ed = i;
		W[i] = happiness;
	}
	string from_str, to_str;
	int from, to, cost;
	fill(d, d+MAXV, INF);
	fill(G[0], G[0]+MAXV*MAXV, INF);
	for(int i=0; i<k; i++) {
		cin >> from_str >> to_str >> cost;
		from = mp[from_str];
		to = mp[to_str];
		G[from][to] = cost;
		G[to][from] = cost;
	}
	
	Dijkstra(st);
	DFS(ed);
	printf("%d %d %d %d\n", num[ed], d[ed], optValue, optValue/(path.size()-1));
	for(int i=path.size()-1; i>=0; i--) {
		if(i == path.size()-1)
			cout << int2str(path[i]);
		else
			cout << "->" << int2str(path[i]);
	}
	printf("\n");
	return 0;	
}
