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

bign divide(bign a, int b, int& r) { //�߾�����;��ȳ���bign a ��int b 
	bign c;
	c.len = a.len; //��������ÿһλ���̵�ÿһλ��һһ��Ӧ�ģ������������ 
	for(int i=a.len-1; i>=0; i--) { //�Ӹ�λ��ʼ 
		r = r * 10 + a.d[i]; //����һλ�������������
		if(r < b)	c.d[i] = 0; //����������λΪ0
		else { //���� 
			c.d[i] = r / b; //��
			r = r % b; 
		} 
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
	string s1;
	int b;
	cin >> s1 >> b;
	bign a = change(s1);
	int r = 0;
	print(divide(a, b, r));
	return 0;
} 
