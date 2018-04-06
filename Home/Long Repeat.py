def long_repeat(line):
    """
        length the longest substring that consists of the same char
    """
    # your code here
    if len(line)==0:return 0
    linel=line.lower()
    count=0
    max_count=0
    for i in range(len(line)-1):
        if linel[i]==linel[i+1]:
            count+=1
        else:
            max_count=max(max_count,count+1)
            count=0
    return max(max_count, count+1)  
