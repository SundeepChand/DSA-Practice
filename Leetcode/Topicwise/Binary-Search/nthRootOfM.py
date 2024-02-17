def getNthRoot(m, n):
    lb, ub = 0, m
    ans = ub

    THRESHOLD_ERROR = 0.000000001

    while True:
        mid = lb + (ub - lb) / 2.0
        curRes = mid ** n

        # print(f'DEB: {lb}, {ub}, {curRes}, {m}')

        if abs(curRes - m) < THRESHOLD_ERROR:
            ans = mid
            break
        elif curRes > m:
            ub = mid
        else:
            lb = mid

    return round(ans, 6)


print(getNthRoot(69, 4))
