keypad = [[1, 4, 7, '*'], [2, 5, 8, 0], [3, 6, 9, '#']]
left = [0, 3]
right = [2, 3]


def solution(numbers, hand):
    answer = ''

    for n in numbers:
        for idx, v in enumerate(keypad):
            if n in v:
                co = v.index(n)
                if idx == 0:
                    answer += 'L'
                    left[0] = 0
                    left[1] = co
                elif idx == 2:
                    answer += 'R'
                    right[0] = 2
                    right[1] = co
                else:
                    now = [1, co]
                    left_distance = abs(now[0] - left[0]) + abs(now[1] - left[1])
                    right_distance = abs(now[0] - right[0]) + abs(now[1] - right[1])
                    if left_distance > right_distance:
                        answer += 'R'
                        right[0] = 1
                        right[1] = co
                    elif right_distance > left_distance:
                        answer += 'L'
                        left[0] = 1
                        left[1] = co
                    else:
                        if hand == "right":
                            answer += 'R'
                            right[0] = 1
                            right[1] = co
                        else:
                            answer += 'L'
                            left[0] = 1
                            left[1] = co

    return answer