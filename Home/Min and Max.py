def minSimple(arg1, arg2, key):
    if key!=None and key(arg1)<key(arg2) or key==None and arg1<arg2: return arg1
    return arg2

def min(*args, **kwargs):

    key=kwargs.get("key", None)         # Extracting key
    if len(args)==1: args=list(args[0]) # Adapting arguments

    # Comparing arguments, one by one
    result=args[0]
    for x in range(1,len(args)):
        result=minSimple(result,args[x],key)
    return result


def maxSimple(arg1, arg2, key):
    if key!=None and key(arg2)>key(arg1) or key==None and arg2>arg1: return arg2
    return arg1

def max(*args, **kwargs):

    key=kwargs.get("key", None)         # Extracting key
    if len(args)==1: args=list(args[0]) # Adapting arguments

    # Comparing arguments, one by one
    result=args[0]
    for x in range(1,len(args)):
        result=maxSimple(result,args[x],key)
    return result  
