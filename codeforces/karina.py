num_test_cases = int(input())

while num_test_cases > 0:
    size = int(input())
    array = list(map(int, input().split(' ')));


    max = int(sorted(array)[0]) * int(sorted(array)[1])

    max2 = int(sorted(array, reverse=True)[0]) * int(sorted(array, reverse=True)[1])

    print(max if max > max2 else max2)

    num_test_cases -= 1
