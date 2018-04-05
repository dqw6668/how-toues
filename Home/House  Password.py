def checkio(data):
    if len(data)>=10:
        if not(data.isdigit() or data.isalpha() or data.islower() or data.isupper()):
            return True
    return False
