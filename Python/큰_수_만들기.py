max_result = 0

def find_su(idx: int, k: int, number: str, added_su: str):
    # global max_result

    if idx + 1 >= len(number) - k:
        return added_su

    su = list(number)[idx + 1: len(number) - k]
    max_su = max(su)

    for i in range(idx+1, len(number)-k):
        if number[i] == max_su:
            s = find_su(i, k, number, added_su + number[i])
            if s is not None:
                return s

    return


def solution(number, k):
    su = list(number)[0:len(number) - k]
    max_su = max(su)

    s = find_su(0, k, number, number[0] if max_su == number[0] else "")
    
    print(s)

    return str(max_result)
