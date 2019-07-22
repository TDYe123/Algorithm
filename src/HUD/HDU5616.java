package HUD;

import java.util.*;
import java.io.*;
public class HDU5616 {
	static final int MAX_N = 24;
	static final int MAX_W = 24*100;
	static int[] w = new int[MAX_N];
	static int[][] dp = new int[MAX_N][2*MAX_W+1];//0��ʾfalse, 1��ʾtrue, ��ʼ��Ϊ-1, ��ʾǰi����������ѡ�Ƿ����������Ϊj��������

	static int rec(int i, int j) {
		if(j > 2*MAX_W || j <= 0) 
			return 0;
		if(dp[i][j] > 0) {
			//�Ѿ������ֱ��ʹ����ǰ���
			return dp[i][j];
		}
		int res = 0 ;
		if(j == 2400) {
			res = 1;
		} else if(i == 0) {
			res = (w[i] == (2*MAX_W -  j))||(w[i] == j) ? 1:0;
		} else {
			if((rec(i-1, j-w[i]+MAX_W)|rec(i-1, j+w[i]-MAX_W)|rec(i-1, j)) == 1) {
				res = 1;
			}
		}
		return dp[i][j] = res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		for(int i=0; i<MAX_N; i++) {
			for(int j=0; j<2*MAX_W+1; j++) {
				dp[i][j] = -1;
			}
		}
		int T = sc.nextInt();//��������
		int N = sc.nextInt();//�������
		for(int i=0; i<T; i++) {
			for(int j=0; j<N; j++) {
				w[j] = sc.nextInt()+MAX_W;
			}
			int M = sc.nextInt();//��ѯ����
			for(int k=0; k<M; k++) {
				System.out.println(rec(N-1, sc.nextInt()+MAX_W) == 1 ? "YES":"NO");
			}
		}
	}
}
