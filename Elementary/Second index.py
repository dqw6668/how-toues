def second_index(text: str, symbol: str):
    """
        returns the second index of a symbol in a given text
    """
    # your code here
    if text.count(symbol)<2:return None
    else:return text.find(symbol,text.find(symbol)+1)
