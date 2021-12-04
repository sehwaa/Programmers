def is_valid_string(s: list) -> bool:
    stack = []
    for j in s:
        if j == '[' or j == '{' or j == '(':
            stack.append(j)
        else:
            if len(stack) == 0 or (stack[-1] == '[' and j != ']') or (stack[-1] == '(' and j != ')') or (stack[-1] == '{' and j != '}'):
                return False
            else:
                stack.pop()
    return True

def solution(s):
    answer = 0
    
    s = list(s)
    if len(s) % 2 != 0:
        return answer
    
    for i in range(len(s)):
        a = s.pop(0)
        s.append(a)
        if is_valid_string(s):
            answer += 1
                
    return answer
