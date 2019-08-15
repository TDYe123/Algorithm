/*
*1098 Insertion or Heap Sort (25 ��)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int A[maxn], T[maxn], n; //nΪԪ�ظ����������±�Ϊ1~n 
bool Heap_isEqual(int arr[]) {  //������ʱ����������������򻯣����д�ͷ����ʼ�Ƚ� 
	for(int i=1; i<=n; i++) {
		if(T[i] != arr[i])
			return false;
	}
	return true;
} 

void print(int arr[]) {
	for(int i=1; i<=n; i++) {
		if(i == 1)
			printf("%d", arr[i]);	
		else 
			printf(" %d", arr[i]);
	}	
	printf("\n");
}

void perDown(int arr[], int i, int n) {
	int child, temp;
	for(temp = arr[i]; 2*i<=n; i=child) {
		child = 2*i;
		if(child != n && arr[child]<arr[child+1])
			child++;
		if(temp<arr[child])
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = temp;
}

void HeapSort(int arr[], int len) { //�����ڶ�����ߵ�һ��Ԫ�ؿ�ʼ 
	for(int i=len/2; i>=1; i--)
		perDown(arr, i, len);
	bool equal = false;
	for(int i=len; i>1; i--) {
		equal = Heap_isEqual(A);
		swap(arr[1], arr[i]);
		perDown(arr, 1, i-1);
		if(equal) {
			printf("Heap Sort\n");
			print(A);
			break;
		} 
	}
} 

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d", &A[i]);
	for(int i=1; i<=n; i++) 
		scanf("%d", &T[i]);
			
	if(n == 1) {
		printf("Insertion Sort\n");
		print(A);
		return 0;
	}
	
	int pos = 1;
	for(int i=2; i<=n; i++) {
		if(T[i] < T[i-1]) {
			pos = i;
			break;
		}
	}
	
	bool flag = true; //�Ƿ��ǲ������� 
	for(int i=pos; i<=n; i++) {
		if(A[i] != T[i]) {
			flag = false;
			break;
		} 
	}
	if(flag) {
		printf("Insertion Sort\n");
		sort(A+1, A+pos+1);
        print(A);
	} else
		HeapSort(A, n);
	return 0;
}
