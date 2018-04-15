def checkio(array):
    """
        sums even-indexes elements and multiply at the last
    """
    if len(array)==0:return 0
    else:
        last=array[-1]
        data=array[::2]
        c=0
        for i in data:
            c+=i
    return c*last
