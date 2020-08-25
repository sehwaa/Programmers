import java.util.*;

class Solution {
    public int check(Queue<Integer> queue, int K){
        int result = 1;
        for(int i = 0; i < queue.size(); i++){
            int temp = queue.poll();
            if(temp < K){
                result = 0;
                queue.add(temp);
                break;
            }
        }
        return result;
    }
    public int solution(int[] scoville, int K) {   
        int answer = 0;
        Queue<Integer> queue = new PriorityQueue<Integer>();
        
        for(int i = 0; i < scoville.length; i++){
            queue.add(scoville[i]);
        }
        
        try{
            while(check(queue, K) != 1){
                int scovilleScore = 0;
                scovilleScore = queue.poll() + (queue.poll() * 2);
                queue.add(scovilleScore);
                answer++;
            }    
        }catch(NullPointerException e){
            answer = -1;
        }
        return answer;
    }
}