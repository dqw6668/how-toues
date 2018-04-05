def checkio(data):
    #Your code here```
    #It's main function. Don't remove this function
    #It's used for auto-testing and must return a result for check.

    #replace this for solution
    list2=[]
    for num in data:
        count=data.count(num)
        if count>=2:
            list2.append(num)
        else:pass
    return list2  
