#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x) & -(x))
int getSum(int x) {
	int sum = 0; //��¼��
	for(int i=x; i>0; i-=lowbit(i)) {
		sum += c[i];
	}
}

//update��������x����������v 
void update(int x, int v) {
	for(int i=x; i<=N; i+=lowbit(i)) {
		c[i] += v;
	}
}

int main() {
	
} 
