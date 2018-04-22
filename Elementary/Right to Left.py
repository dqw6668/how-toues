def left_join(phrases):
    str = ','
    str=str.join(phrases)
    str=str.replace('right', 'left')
    return str  
