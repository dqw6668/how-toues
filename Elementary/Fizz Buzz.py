def checkio(number):
    str1=''
    if (number%3==0 and number%5==0):
        str1="Fizz Buzz"
    elif (number%3!=0 and number%5==0):
        str1='Buzz'
    elif (number%3==0 and number%5!=0):
        str1='Fizz'
    elif (number%3!=0 and number%5!=0):
        str1=str(number)

    return str1
