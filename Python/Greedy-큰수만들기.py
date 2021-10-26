def solution(number, k):
    su = []
    
    i = 0
    while k > 0 and len(number) > 0:
        while len(su) > 0 and su[-1] < number[i]:
            su.pop()
            k -= 1
            if k == 0:
                break
        su.append(number[i])
        i += 1

    return "".join(su) + number[i:]
