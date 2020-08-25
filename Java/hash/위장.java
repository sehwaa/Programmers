import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<Integer, String> map = new HashMap<Integer, String>();
        HashSet<String> set = new HashSet<String>();
        
        for(int i = 0; i < clothes.length; i++){
            map.put(i, clothes[i][1]);
            set.add(clothes[i][1]);
        }
        
        int[] countArray = new int[set.size()];
        
        int setCount = 0;
        
        for(String x : set){
            for(int i = 0; i < map.size(); i++){
                if(map.get(i).equals(x)){
                    countArray[setCount] += 1;
                }
            }
            setCount++;
        }     
        
        for(int i = 0; i < countArray.length; i++){
            answer *= countArray[i] + 1;
        }
        return answer -1;
    }
}