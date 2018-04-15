def best_stock(data):
    d=sorted(data,key=data.get) ‘data.get的用法’
    return d[-1]
