import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] day = new int[progresses.length];
        for(int i = 0; i < progresses.length; i++){
            if((100 - progresses[i]) % speeds[i] == 0){ day[i] = (int)((100 - progresses[i]) / speeds[i]); }
            else{ day[i] = (int)((100 - progresses[i]) / speeds[i]) + 1; }
        }
        
        ArrayList<Integer> dayIndex = new ArrayList<Integer>();
        dayIndex.add(0);
        
        for(int i = 0; i < day.length - 1; i++){
            for(int j = i+1; j < day.length; j++){
                if(j == day.length - 1){
                    if(day[i] > day[j]){
                        i = j;
                    }
                }else{
                    if(day[i] < day[j]){
                        dayIndex.add(j);
                        i = j-1;
                        break;
                    }
                }
            }
        }
        
        if(day[day.length-1] > day[dayIndex.get(dayIndex.size()-1)]){
            dayIndex.add(day.length-1);
        }
        
        int[] answer = new int[dayIndex.size()];
        
        for(int i = 0; i < answer.length; i++){
            if(i != answer.length -1){ answer[i] = dayIndex.get(i+1) - dayIndex.get(i);}
            else{ answer[i] = day.length - dayIndex.get(i); }
        }
        return answer;
    }
}