def between_markers(text: str, begin: str, end: str) -> str:
    if begin in text:
        start = text.index(begin) + len(begin)
    else:
        start = 0
    if end in text:
        finish = text.index(end)
    else:
        finish = len(text)
    return (text[start:finish])
