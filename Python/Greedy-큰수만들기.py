def solution(number, k):
    number = list(number)
    su = []
    
    while k > 0 and len(number) > 0:
        while len(su) > 0 and su[-1] < number[0]:
            su.pop()
            k -= 1
            if k == 0:
                break
        su.append(number.pop(0))

    return "".join(su+number)
