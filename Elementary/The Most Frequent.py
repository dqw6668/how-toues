rom collections import Counter  '百度下Counter的用法'
def most_frequent(data):
    word_counts = Counter(data)
    top = word_counts.most_common(1)
    return top[0][0]  
