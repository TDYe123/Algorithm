#include<bits/stdc++.h>
using namespace std;
struct bign {
	int d[1000];
	int len;
	bign() {
		fill(d, d+1000, 0);
		len = 0;
	}
};

bign change(string str) { //������ת��Ϊbign 
	bign a;
	a.len = str.length();
	for(int i=0; i<a.len; i++) {
		a.d[i] = str[a.len-1-i] - '0'; //������ã�������� 
	}
	return a; 
}

bign sub(bign a, bign b) { //�߾���a-b 
	bign c;
	for(int i=0; i<max(a.len, b.len); i++) {
		if(a.d[i] < b.d[i]) { //���������
			a.d[i+1]--; //���λ��λ
			a.d[i]+=10; //��ǰλ��10 
		}
		c.d[c.len++] = a.d[i] - b.d[i]; //�������Ϊ��ǰλ��� 
	}
	while(c.len >= 2 && c.d[c.len-1] == 0) {
		c.len--; //ȥ����λ��0��ͬʱ���ٱ���һλ���λ 
	} 
	return c;
}

void print(bign a) {
	for(int i=a.len-1; i>=0; i--) {
		printf("%d", a.d[i]);
	}
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	bign a = change(s1);
	bign b = change(s2);
	print(sub(a, b));
	return 0;
} 
