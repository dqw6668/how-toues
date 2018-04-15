def popular_words(text, words):
    text=text.lower()
    dit={}
    count=0
    for s in words:
        if s in text:
            count=text.count(s)
            dit[s]=count
        else:
            dit[s]=0
    return dit
