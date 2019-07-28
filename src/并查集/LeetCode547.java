package ���鼯;

import java.io.*;
import java.util.*;

public class LeetCode547 {
	static final int N = 310;
	static int[] father = new int[N]; //��Ÿ��׽ڵ� 
	static boolean isRoot[] = new boolean[N]; //��¼ÿ���ڵ��Ƿ���Ϊÿ�����ϵĸ��ڵ� 
	
	static void init(int n) {
		for(int i=0; i<n; i++) {
			father[i] = i;
			isRoot[i] = false;
		}
	}
	
	static int findFather(int x) {
		int a = x;
		while(x !=father[x]) {
			x = father[x];
		}
		//·��ѹ��
		while(a != father[a]) {
			father[a] = x;
			a = father[a];
		} 
		return x;
	}
	
	static void Union(int a, int b) {
		int faA = findFather(a);
		int faB = findFather(b);
		
		if(faA != faB) {
			father[faA] = faB;
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		int[][] M = new int[N][N];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				M[i][j] = sc.nextInt();
			}
		}
		sc.close();
		init(n);
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(M[i][j] == 1) {
					Union(i, j);
				}
			}
		}
		
		for(int i=0; i<n; i++) {
			isRoot[findFather(i)] = true; //i�ĸ��ڵ���findFahter(i) 
		}
		int ans = 0; //��¼������Ŀ
		for(int i=0; i<n; i++) {
			ans += isRoot[i] ? 1:0;
		} 	
		System.out.println(ans);
	}
}
