def checkio(a):
    x=''.join(a)
    m=['012','345','678','036','147','258','048','246']
    for i in m:
        if x[int(i[0])]==x[int(i[1])]==x[int(i[2])]in'XO':
            return x[int(i[0])]
    return 'D'     
