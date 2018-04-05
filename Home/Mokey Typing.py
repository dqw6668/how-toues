def count_words(text, words):
    text=text.lower()
    count=0
    for word in words:
        if word in text:
            count+=1
    return count  
