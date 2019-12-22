package LeetCode.买卖股票的最佳时机;

public class L309 {
	public static int maxProfit(int[] prices) {
	    int n = prices.length;
	    if(n == 0)
	    	return 0;
	    int dp_i_0 = 0, dp_i_1 = Integer.MIN_VALUE;
	    int dp_pre_0 = 0; // 代表 dp[i-2][0]
	    for (int i = 0; i < n; i++) {
	        int temp = dp_i_0;
	        dp_i_0 = Math.max(dp_i_0, dp_i_1 + prices[i]);
	        dp_i_1 = Math.max(dp_i_1, dp_pre_0 - prices[i]);
	        dp_pre_0 = temp;
	    }
	    return dp_i_0;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] prices = new int[] {1, 2, 3, 0, 2};
		System.out.println(maxProfit(prices));
	}

}
