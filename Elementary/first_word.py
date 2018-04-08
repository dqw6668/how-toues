import re
def first_word(text: str) -> str:
    """
        returns the first word in a given text.
    """
    # your code here

    pat1 = "[a-zA-Z']+"
    result = re.search(pat1,text)
    result = str(result.group())
    return result
