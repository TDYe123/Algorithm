#include<bits/stdc++.h>
using namespace std;

int binarySearch(int list[], int left, int right, int x) {
	int mid;	//midΪleft��right���е�
	while(left <= right) {	//���left>right��û�취�γɱ�������
		mid = (left + right) / 2;	//ȡ�е�
		if(list[mid] == x)	return mid;
		else if(list[mid] > x) {	//�м��������x 
			right = right - 1;	//����������[left, right-1]���� 
		} else {	//�м����С��x 
			left = mid + 1;		//����������[mid+1, right]���� 
		}
	} 
	return -1;	//����ʧ�ܣ�����-1 
}

int main() {
	const int n = 15;
	int my_list[n] = {2, 29, 33, 42, 59, 67, 87, 92, 100, 210, 282, 381, 467, 578, 666};
	printf("The index is %d.", binarySearch(my_list, 0, n-1, 282));
	return 0;
} 
