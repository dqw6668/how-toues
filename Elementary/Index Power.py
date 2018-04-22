def index_power(array, n):
    count=len(array)
    data=0
    if (n<=(count-1)):
        data=array[n]**n
    else:data=-1
    return data  
