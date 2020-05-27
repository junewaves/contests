a = [[1, 2, 4, 7, 11],
     [3, 5, 8, 12, 17],
     [6, 9, 13, 18, 24],
     [10, 14, 19, 25, 31]]
x = len(a) + len(a[0]) - 1
d = [0] * x
s = []


if __name__ == "__main__":
    a = []
    st = 0
    for i in range(0, 10):
        a.append([0] * 10)
        k = i
        st = a[i - 2][0] + k + 1 if i >= 2 else i + 1
        for j in range(0, 10):
            a[i][j] = st + k
            st += k
            k += 1
    # for b in a:
    #     print(b)
    res = []
    for la in range(1, 11):
        res.append([0] * 10)
        for lb in range(1, 11):
            d = [0] * (la + lb - 1)
            s = []

            def dfs(i, j, dep):
                if dep < la + lb - 1:
                    d[dep] = a[i][j]
                if i + 1 < la and dep < la + lb - 1:
                    dfs(i + 1, j, dep + 1)
                if j + 1 < lb and dep < la + lb - 1:
                    dfs(i, j + 1, dep + 1)
                if dep == la + lb - 2:
                    if (sum(d)) not in s:
                        s.append(sum(d))
            dfs(0, 0, 0)
            res[la - 1][lb - 1] = len(s)
    for b in res:
        print(b)
