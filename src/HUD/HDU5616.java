package HUD;

import java.util.*;
import java.io.*;
public class HDU5616 {
	static int sum ;
	static final int MAX_N = 24;
	static final int MAX_W = 24*100;
	static int[] w = new int[MAX_N];
	static int[][] dp = new int[MAX_N][2*MAX_W+1];//0��ʾfalse, 1��ʾtrue, ��ʼ��Ϊ-1, ��ʾǰi����������ѡ�Ƿ����������Ϊj��������

	static int rec(int i, int j) {
		if(j > 2*sum || j <= 0) 
			return 0;
		if(dp[i][j] > 0) {
			//�Ѿ������ֱ��ʹ����ǰ���
			return dp[i][j];
		}
		int res = 0 ;
		if(j == sum) {
			res = 1;
		} else if(i == 0) {
			res = (w[i] == (2*sum -  j))||(w[i] == j) ? 1:0;
		} else {
			if(rec(i-1, j-w[i]+sum) == 1) 
				return dp[i][j] = 1;
			if(rec(i-1, j+w[i]-sum) == 1) 
				return dp[i][j] = 1;
			if(rec(i-1, j) == 1) {
				return dp[i][j] = 1;
			}
		}
		return dp[i][j] = res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int T = sc.nextInt();//��������
		int N = sc.nextInt();//�������
		for(int i=0; i<T; i++) {
			for(int j=0; j<N; j++) {
				w[j] = sc.nextInt();
				sum += w[j];
			}
			for(int j=0; j<N; j++) {
				w[j] += sum;
			}
			int M = sc.nextInt();//��ѯ����
			for(int k=0; k<M; k++) {
				System.out.println(rec(N-1, sc.nextInt()+sum) == 1 ? "YES":"NO");
			}
		}
	}
}
