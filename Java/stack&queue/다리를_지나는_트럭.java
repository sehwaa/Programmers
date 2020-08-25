import java.util.*;
class Solution {
   public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Queue<Integer> waitTruck = new LinkedList<Integer>();
        Queue<Integer> crossTruck = new LinkedList<Integer>();
            
        for(int i = 0; i < truck_weights.length; i++){
            waitTruck.offer(truck_weights[i]);
        }
        
        while(!waitTruck.isEmpty()){
            int sum = 0;
            for(int i = 0 ; i <= bridge_length; i++){
                if(i != bridge_length){
                    try{
                        sum += waitTruck.peek();
                        if(sum <= weight){
                            crossTruck.offer(waitTruck.poll());
                        }else{
                            crossTruck.offer(-1);
                            sum -= waitTruck.peek();
                        }                        
                    }catch(NullPointerException e){
                        break;
                    }
                }else{
                	try {
                		if(crossTruck.peek() != -1){
                            sum -= crossTruck.poll();
                        }else if(crossTruck.peek() == -1) {
                        	crossTruck.poll();
                        }
                	}catch(NullPointerException e) {
                		break;
                	}
                    i = i - 2;
                    answer++;
                }
            }
        }
        
        if(crossTruck.size() != 0){
            answer += crossTruck.size();
        }

        return answer + bridge_length;
    }
}