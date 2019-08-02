#include<bits/stdc++.h>
using namespace std;

vector<int> Adj[MAXV]; //ͼG�� Adj[u]��ŴӶ���u�������Ե�������ж���
int n; //nΪ��������MAXVΪ��󶥵���
bool inq[MAXV] = {false}; //������i��������У���inq[i]==true����ֵΪfalse

void BFS(int u) { //����������ͨ�� 
	queue<int> q; //�������q
	q.push(u); //����ʼ��u���
	inq[u] = true; //����u�ѱ����������
	while(!q.empty()) { //ֻҪ���зǿ� 
		int u = q.front(); //ȡ������Ԫ��
		printf("%d ", u); //����u 
		q.pop(); //������Ԫ�س��� 
		for(int i=0; i<Adj[u].size(); i++) { //ö��u�����ܵ�������ж��� 
			int v = Adj[u][i];
			if(inq[v] == false) { //���vδ����������� 
				q.push(v); //��v���
				inq[v] = true; //���v�Ա���������� 
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

