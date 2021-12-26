def solution(numbers, ndays):
    fish = [0 for i in range(9)]

    for num in numbers:
        fish[num] += 1

    for n in range(ndays):
        spawn = fish[0]
        fish[:] = fish[1:] + [spawn]
        fish[6] += spawn

    return sum(fish)

if __name__ == '__main__':
    numbers = [int(num) for num in 
               open('input.txt').readline().split(',')]

    print('Part 1:', solution(numbers, 80))
    print('Part 2:', solution(numbers, 256))