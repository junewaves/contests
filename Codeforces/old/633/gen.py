from random import randint
if __name__ == '__main__':
    with open('input.txt', 'w') as fout:
        fout.write(f'2\n')
        for i in range(2):
            a = 5
            fout.write(f'{a}\n')
            for j in range(a):
                fout.write(f'{randint(-5,5)} ')
            fout.write('\n')
