/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
int maxProfit(int* prices, int pricesSize) {
    /*
    int max = -1;
    int min = 1000000000;
    int maxday = -1;
    int minday = -1;
    int diff = 0;
    for(int i = 0; i < pricesSize; i++){
        if(prices[i]<min){
            min = prices[i];
            minday = prices[i];
            max = -1;
            maxday = -1;
            for(int j = i+1; j < pricesSize; j++){
                if(prices[j]>max){
                    max = prices[j];
                    maxday = j;
                    if(max-min > diff){
                        diff = max - min;
                    }
                }
            }
        }
    }
    return diff;*/
    int minPrice = 10000000;      // 初始值应该设成什么？第一天的价格，还是某个极大值？
    int maxProfit = 0;     // 初始值呢？既然还没交易过，利润最少是多少？
    
    for (int i = 0; i < pricesSize; i++) {
        // 第一步：用当前价格和minPrice算一下利润，够不够更新maxProfit？
        if(prices[i]-minPrice > maxProfit) maxProfit = prices[i]-minPrice;
        // 第二步：当前价格是不是比minPrice还低？要不要更新minPrice？
        if(prices[i] < minPrice) minPrice = prices[i];
    }
    
    return maxProfit;
}
// @lc code=end

