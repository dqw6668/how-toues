def date_time(time):
    data=time.split()
    d1=data[0].split('.')
    d2=data[1].split(':')
    dic={'01':'January','02':'February','03':'March','04':'April','05':'May','06':'June','07':'July',}
    hour=d2[0]+' hours '
    minu=d2[1]+' minutes'
    if d2[0]=='01':
        hour='1 hour '
    if d2[1]=='01':
        minu='1 minute'
    str1=dic[d1[1]]
    result=d1[0]+' '+str1+' '+d1[2]+' year '+hour+minu
    return result  
