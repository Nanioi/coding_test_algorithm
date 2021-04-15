def get_gcd(a,b):
    i=1
    cnt=0
    while i<=a and i<=b:
        if(a%i==0 and b%i==0):
           cnt=i
        i=i+1
    return(cnt)
n1=int(input())
n2=int(input())

print(get_gcd(n1,n2))
           
