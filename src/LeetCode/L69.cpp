/*ʵ��int sqrt(int x)������
���㲢����x��ƽ����������x �ǷǸ�������
���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��
ʾ�� 1:
����: 4
���: 2
ʾ�� 2:
����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842..., 
���ڷ���������������С�����ֽ�����ȥ��
*/
#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
	if(x == 0)
		return 0; 
    double pre = x, current = x;
	while(true) {
		current = (current+x/current)/2;
		if(abs(current-pre) < 1e-6)
			return int(current);
		pre = current;
	}    
} 

int main() {
	int a = 8;
	printf("%d", mySqrt(a));
	return 0;
}
