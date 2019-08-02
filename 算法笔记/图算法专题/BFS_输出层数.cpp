#include<bits/stdc++.h>
using namespace std;

struct Node {
	int v; //������
	int layer; //������ 
}; 

vector<Node> Adj[MAXV]; //ͼG�� Adj[u]��ŴӶ���u�������Ե�������ж���
int n; //nΪ��������MAXVΪ��󶥵���
bool inq[MAXV] = {false}; //������i��������У���inq[i]==true����ֵΪfalse

void BFS(int s) { //sΪ��ʼ������ 
	queue<Node> q; //BFS����q
	Node start; //��ʼ����
	start.v = s; //��ʼ������
	start.layer = 0; //��ʼ������Ϊ0
	q.push(start); //����ʼ����ѹ����� 
	inq[start.v] = true; //����u�ѱ����������
	while(!q.empty()) { //ֻҪ���зǿ� 
		Node topNode = q.front(); //ȡ������Ԫ��
		printf("%d-%d ", topNode.v, topNode.layer); //����u 
		q.pop(); //������Ԫ�س��� 
		for(int i=0; i<Adj[u].size(); i++) { //ö��u�����ܵ�������ж��� 
			Node next = Adj[u][i];
			next.layer = topNode.layer + 1;
			if(inq[next.v] == false) { //���vδ����������� 
				q.push(next); //��v���
				inq[next.v] = true; //���v�Ա���������� 
			}
		}
		 
	}	
} 

void BFSTravel() { //����ͼG 
	for(int u=0; u<n; u++) { //ö�����ж��� 
		if(inq[u] == false) { //���uδ����������� 
			BFS(u); //����u���ڵ���ͨ�� 
		} 
	} 
} 

