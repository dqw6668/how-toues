def find_message(text):
    """Find a secret message"""
    data=[]
    for i in range(len(text)):
        if text[i].isupper():
            data.append(text[i])

    return "".join(data)
