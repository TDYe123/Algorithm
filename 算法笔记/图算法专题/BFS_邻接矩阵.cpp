#include<bits/stdc++.h>
using namespace std;
int n, G[MAXV][MAXV]; //nΪ��������MAXVΪ��󶥵���
bool inq[MAXV] = {false}; //������i��������У���inq[i]==true����ֵΪfalse

void BFS(int u) { //����u���ڵ���ͨ�� 
	queue<int> q; //�������q
	q.push(u); //����ʼ��u���
	inq[u] = true; //����u�ѱ����������
	while(!q.empty()) {
		int u = q.front(); //ȡ������Ԫ��
		printf("%d ", u); //����u 
		q.pop(); //������Ԫ�س���
		for(int v=0; v<n; v++) {
			//���u���ڽӵ�vδ��������� 
			if(inq[v] == false && G[u][v] != INF) {
				q.push(v); //��v���
				inq[v] = true; //���vΪ�ѱ���������� 
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

int main() {
	
}
