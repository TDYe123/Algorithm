#include<bits/stdc++.h>
using namespace std;
const int MAXV = 1010;
struct Node {
	int id; //�ڵ��� 
	int layer; //�ڵ��� 
};

vector<Node> Adj[MAXV]; //�ڽӱ� 
bool inq[MAXV] = {false}; //�����Ƿ��ѱ����������

int BFS(int s, int L) { //startΪ��ʼ�ڵ㣬LΪ�������� 
	int numForward = 0; //ת����
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while(!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id;
		for(int i=0; i<Adj[u].size(); i++) {
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				numForward ++;
			}
		}
	} 
	return numForward;
} 

int main() { 
	Node user;
	int n, L, numFollow, idFollow;
	scanf("%d%d", &n, &L); //�ڵ�������������
	for(int i=1; i<=n; i++) {
		user.id = i;
		scanf("%d", &numFollow); //i���û���ע������
		for(int j=0; j<numFollow; j++) {
			scanf("%d", &idFollow);
			Adj[idFollow].push_back(user); //��idFollow->i 
		}
		
	}
	int numQuery, s;
	scanf("%d", &numQuery);
	for(int i=0; i<numQuery; i++) {
		memset(inq, false, sizeof(inq)); //inq�����ʼ��
		scanf("%d", &s);
		int numForward = BFS(s, L);
		printf("%d\n", numForward); 
	}
	return 0;
} 
