#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int coins[maxn]; //�±�Ϊ��ֵ����Ÿ���ֵ������
int N, M, coin, max_value, min_value = 1010;
int main() {
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> coin;
		max_value = max(max_value, coin); 
		min_value = min(min_value, coin);
		coins[coin]++;
	}
	for(int i=min_value; i<=M/2; i++) { //�˴�i<=M/2������max_value/2 
		if(coins[i] > 0) {
			coins[i]--;
			if(coins[M-i] > 0) {
				cout << i << " " << M-i << endl;
				return 0;
			}
			coins[i]++; //����ղ���M���Ż�[i] 
		}
	} 
	cout << "No Solution" << endl;
	return 0;
} 
