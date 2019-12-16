/*��������������������nums1 �� nums2���� nums2 �ϲ���?nums1?�У�ʹ��?num1 ��Ϊһ���������顣
˵��:
��ʼ��nums1��nums2��Ԫ�������ֱ�Ϊm��n��
����Լ���nums1���㹻�Ŀռ䣨�ռ��С���ڻ����m + n�������� nums2 �е�Ԫ�ء�
ʾ��:
����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
���:[1,2,2,3,5,6]
*/
#include<bits/stdc++.h>
using namespace std;

//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//	for(int i=m, j=0; i<m+n && j<n; i++, j++) 
//		nums1[i] = nums2[j];
//	sort(nums1.begin(), nums1.end());
//}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int> copy;
	for(int i = 0; i < m; i++) 
		copy.push_back(nums1[i]);
	int i = 0, j = 0, t = 0;
	while(i < m && j < n) 
		nums1[t++] = (copy[i] <= nums2[j]) ? copy[i++] : nums2[j++];	
	while(i < m)
		nums1[t++] = copy[i++];
	while(j < n)
		nums1[t++] = nums2[j++];	
}

int main() {
	vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
	merge(nums1, 3, nums2, 3);
	for(int i=0; i<6; i++) 
		cout << nums1[i] << " ";
	return 0;
}
