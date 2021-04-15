def scretkey(a):
    n1=int((a/1000)%10)
    n2=int((a/100)%10)
    n3=int((a/10)%10)
    n4=int(a%10)

    goodpass=True

    if n1==n2 or n1==n3 or n1==n4 or n2==n3 or n2==n4 or n3==n4:
        goodpass=False
    elif n2==n1+1 and n3==n2+1 and n4==n3+1 : 
        goodpass=False
    elif n3==n4+1 and n2==n3+1 and n1==n2+1 :
        goodpass=False
    return(goodpass)

password=int(input())

if (scretkey(password)):
    print("사용할 수 있는 암호입니다.")
else:
    print("사용할 수 없는 암호입니다.")
