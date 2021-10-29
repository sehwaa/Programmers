from collections import Counter

def solution(s):
    return [t[0] for t in Counter(list(map(int, s.replace('{', '').replace('}','').split(',')))).most_common()]
