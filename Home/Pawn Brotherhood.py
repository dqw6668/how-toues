def safe_pawns(pawns):
    data=['a','b','c','d','e','f','g','h']
    result=''
    count=0
    result_c=''
    result_b=''
    for x in range(1,9):
        result=data[0]+str(x)
        if result in pawns:
            if (data[1]+str(x-1))in pawns:
                count+=1
    for y in range(1,9):
        result=data[7]+str(y)
        if result in pawns:
            if (data[6]+str(y-1)) in pawns:
                count+=1
    for i in range(1,7):
        for j in range(1,9):
            result=data[i]+str(j)
            if result in pawns:
                result_c=data[i-1]+str(j-1)
                result_b=data[i+1]+str(j-1)
                if ((result_c in pawns) or (result_b in pawns)):
                    count+=1
    return count   
