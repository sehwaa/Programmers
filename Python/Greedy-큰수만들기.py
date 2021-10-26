def solution(number, k):
    su = []
    
    i = 0
    while k > 0 and i < len(number):
        while len(su) > 0 and su[-1] < number[i]:
            su.pop()
            k -= 1
            if k == 0:
                break
        su.append(number[i])
        i += 1

    if k == 0:
        return "".join(su) + number[i:]
    else:
        for i in range(k):
            su.pop()
        return "".join(su)
