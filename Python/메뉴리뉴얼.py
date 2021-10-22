from itertools import combinations
from collections import Counter


def solution(orders, course):
    answer = []

    for c in course:
        t = []
        for o in orders:
            com = combinations(sorted(o), c)
            t.extend(com)

        count = Counter(t).most_common()

        max = -1
        for c in count:
            if c[1] >= max and c[1] > 1:
                max = c[1]
                answer.append("".join(c[0]))
            else:
                break

    return sorted(answer)