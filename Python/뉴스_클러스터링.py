import re

def solution(str1, str2):
    str1_set = []
    for i in range(len(str1)-1):
        ex = "".join(re.compile('[A-Z]+').findall(str1[i].upper() + str1[i+1].upper()))
        if len(ex) >= 2:
            str1_set.append(ex)
            
    str2_set = []
    for i in range(len(str2)-1):
        ex = "".join(re.compile('[A-Z]+').findall(str2[i].upper() + str2[i+1].upper()))
        if len(ex) >= 2:
            str2_set.append(ex)
    
    str1_copy = str1_set.copy()
    str2_copy = str2_set.copy()
    
    intersection = []
    for i in str1_set:
        if i in str2_copy:
            str1_copy.remove(i)
            str2_copy.remove(i)
            intersection.append(i)
            
    union = str1_set + str2_set
    for i in intersection:
        union.remove(i)
        
    return int(len(intersection)/len(union) * 65536) if len(union) != 0 else 65536
