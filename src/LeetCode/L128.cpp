/*	����һ��δ������������飬�ҳ���������еĳ��ȡ�
	Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��
	ʾ��:
	����: [100, 4, 200, 1, 3, 2]
	���: 4
	����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
*/
#include<bits/stdc++.h>
using namespace std;
/*O(nlogn)
int longestConsecutive(vector<int>& nums) {
	int longest = 1, len = 1;
	sort(nums.begin(), nums.end());
	for(auto it=nums.begin()+1; it != nums.end(); it++) {
		if(*it == *(it-1)+1)
			len++;
		else {
			if(len > longest)
				longest = len;
			len = 1;
		}
	}
    return longest;    
}
*/
/*
��C++дʧ���ˣ���ΪC++��û��HashSetһ��ţ�ƵĶ��� 
*/
int longestConsecutive(vector<int>& nums) {
    int maxn = 2048;
    bool exist[maxn] = {false};
    for (auto it=nums.begin(); it!=nums.end(); it++) 
        exist[*it+1024] = true;

    int longestStreak = 0;

    for (auto it=nums.begin(); it!=nums.end(); it++) {
        if (!exist[*it-1+1024]) {
            int currentNum = *it;
            int currentStreak = 1;

            while (exist[currentNum+1+1024]) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}


int main() {
	vector<int> vec = {100, 4, 200, 1, 3, 2};
	printf("%d", longestConsecutive(vec));
	return 0;
}
