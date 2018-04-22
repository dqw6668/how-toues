def checkio(words):
    i=0
    for word in words.split():
        if word.isalpha():
            i+=1
            if i==3:return True
        else:i=0
    return False  
