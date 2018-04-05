def checkio(text):
    lower_text = text.lower()
    appear_time = {}
    for each in lower_text:
        if each.islower():
            if each not in appear_time:
                appear_time[each] = 0
            else:
                appear_time[each] += 1
    array = list(appear_time.items())
    array.sort(key=lambda x:x[0])
    array.sort(key=lambda x:x[1], reverse=True)
    return array[0][0]  
