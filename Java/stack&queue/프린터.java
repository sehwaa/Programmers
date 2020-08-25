import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int key = priorities[location];
        
        ArrayList<Integer> q = new ArrayList<Integer>();
        
        for(int i = 0; i < priorities.length; i++){
            if(i != location){ q.add(priorities[i]); }
            else{ q.add(10);}
        }
        
        while(q.contains(10) && q.size() > 1){
            if(q.get(0) != 10){
                for(int i = 1; i < q.size(); i++){
                    if(q.get(0) < q.get(i) && q.get(i) != 10){
                        q.add(q.get(0));
                        q.remove(0);
                        break;
                    }else if(q.get(0) < q.get(i) && q.get(i) == 10){
                        if(q.get(0) < key){
                            q.add(q.get(0));
                            q.remove(0);
                            break;
                        }
                    }

                    if(i == q.size()-1 && q.get(i) != 10){
                        if(q.get(0) > q.get(i)){
                            answer++;
                            q.remove(0);
                            break;
                        }else if(q.get(0) == q.get(i)) {
                        	answer++;
                        	q.remove(0);
                        	break;
                        }
                    }else if(i == q.size()-1 && q.get(i) == 10) {
                    	if(q.get(0) > key) {
                    		answer++;
                    		q.remove(0);
                    		break;
                    	}else if(q.get(0) == key) {
                    		answer++;
                    		q.remove(0);
                            break;
                    	}
                    }
                }
            }else{
                for(int i = 1; i < q.size(); i++){
                    if(key < q.get(i)){
                        q.add(q.get(0));
                        q.remove(0);
                        break;
                    }
                    if(i == q.size()-1){
                        if(key > q.get(i)){
                            answer++;
                            q.remove(0);
                            break;
                        }else if(key == q.get(i)) {
                        	answer++;
                        	q.remove(0);
                        	break;
                        }
                    }
                }
            }
        }
        
        if(q.contains(10) && q.size() == 1){
            answer = priorities.length;
        }
        return answer;
    }
}