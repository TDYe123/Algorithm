#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int sqrN = 316;

stack<int> st; //ջ
int block[sqrN]; //��¼ÿһ���д��ڵ�Ԫ�ظ���
int table[maxn]; //hash���飬��¼��ǰԪ�ش��ڵĸ���

void PeekMedian(int K) {
	int sum = 0; //sum��ŵ�ǰ�ۼƴ��ڵ����ĸ���
	int idx = 0; //���
	while(sum + block[idx] < K) { //�ҵ���K��������ڿ��
		sum += block[idx++]; 
	} 
	int num = idx*sqrN; //idx�ſ�ĵ�һ����
	while(sum + table[num] < K) {
		sum += table[num++]; //�ۼӿ���Ԫ�ظ�����ֱ��sum�ﵽK	 
	} 
	printf("%d\n", num); //sum�ﵽK���ҵ��˵�K�����Ϊnum 
} 

void Push(int x) {
	st.push(x); //��ջ
	block[x/sqrN]++; //x���ڿ��Ԫ�ظ�����1
	table[x]++; 
} 

void Pop() {
	int x = st.top(); //���ջ��Ԫ��
	st.pop(); //��ջ
	block[x/sqrN]--; //x���ڿ��Ԫ�ظ�����1 
	table[x]--; //x�Ĵ��ڸ�����1 
	printf("%d\n", x); //���x 
} 

int main() {
	int x, query;
	memset(block, 0, sizeof(block));
	memset(table, 0, sizeof(table)); 
	char cmd[20]; //����
	scanf("%d", &query); //��ѯ��Ŀ
	for(int i=0; i<query; i++) {
		scanf("%s", cmd);
		if(!strcmp(cmd, "Push")) {
			scanf("%d", &x);
			Push(x);
		} else if(!strcmp(cmd, "Pop")) {
			if(st.empty()) 
				printf("Invalid\n");
			else 
				Pop();	
		} else {
			if(st.empty()) 
				printf("Invalid\n");
			else {
				int K = st.size();
				if(K%2 == 1)
					K = (K+1)/2;
				else
					K = K/2;
				PeekMedian(K);
			}
				
		}
	} 
	return 0;
} 
