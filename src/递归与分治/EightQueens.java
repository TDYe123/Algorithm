package �ݹ������;

public class EightQueens {
	static int[] queen = new int[9];
	static int[][] table = new int[9][9];
	static int count = 0; //��¼������
	static boolean available(int i, int j) {//�����ڵ�i�е�j��
		for(int k=1; k<i; k++) {
			if(j == queen[k])
				return false;
			if(Math.abs(i-k) == Math.abs(queen[k]-j)) {
				return false;
			}
		}
		return true;
	}
	
	static void put(int i) { //�ڵ�row�з��ûʺ�
		for(int j=1;j<9;j++){ //��1-8�б�����һ�еİ˸���λ
	        if(available(i, j)){ //������i��j��
	            queen[i] = j;
	            if(i == 8) { 
	                count++;
	                for(int t=1; t<9; t++) {
	                	System.out.print(queen[t] + " ");
	                }
	                System.out.println();
	                
	                return;
	            }
	            int nextrow = i + 1; //�ݹ����һ����
	            put(nextrow);
	        }
	    }
		return;
	}
	
	public static void main(String[] args) {
		put(1);
	    System.out.println(count);
	}

}
