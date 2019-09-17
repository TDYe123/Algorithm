/*
*PAT1047 Student List for Course (25 ��)
*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2510;
int n, k, c, id;
string name; //����string��cin��ʱ
char names[40010][5]; 
vector<int> arr[maxn];

bool cmp(int a, int b) {
	return strcmp(names[a], names[b]) < 0;
}

int main() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		scanf("%s%d", names[i], &c);
		for(int j=0; j<c; j++) {
			scanf("%d", &id);
			arr[id].push_back(i);
		}
	}
	for(int i=1; i<=k; i++) {
		sort(arr[i].begin(), arr[i].end(), cmp);
		cout << i << " " << arr[i].size() << endl;
		for(int j=0; j<arr[i].size(); j++) {
			printf("%s\n", names[arr[i][j]]);
		}
	}
	return 0;
}
