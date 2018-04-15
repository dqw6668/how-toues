def bigger_price(limit, data):
    result=[]
    data=sorted(data, key=lambda x: x['price'], reverse=True)

    for i in range(limit):
        result.append(data[i])
    return result
