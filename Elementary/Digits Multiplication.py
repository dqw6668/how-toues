def checkio(number):
    n = number
    cal = 1
    while n >= 1:
        if n % 10 == 0:
            n = int(n / 10)
            continue

        else:
            cal *= n % 10
            n = int(n / 10)
    return cal  
