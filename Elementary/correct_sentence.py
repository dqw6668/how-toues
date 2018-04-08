def correct_sentence(text: str) -> str:
    """
        returns a corrected sentence which starts with a capital letter
        and ends with a dot.
    """
    # your code here
    if text[-1]=='.':
        return text[0].title()+text[1:]
    else:return text[0].title()+text[1:]+'.'
