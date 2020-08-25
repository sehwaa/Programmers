class Solution {
    public int[] solution(int[] prices) {
        prices[prices.length-1] = 0;
        int[] keep = new int[prices.length];
        
        for(int i = 0; i < prices.length-1; i++){
            int time = 1;
            for(int j = i+1; j < prices.length; j++){
                if(prices[i] <= prices[j]){ time++;}
                else{ break; }
            }
            keep[i] = time;
        }
        
        keep[prices.length-1] = 0;
        
        return keep;
    }
}