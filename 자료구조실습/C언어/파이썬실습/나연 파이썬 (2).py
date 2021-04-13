'''
## 1

def multiply(n1,n2) :
    result= n1*n2
    return result

def divide(n1,n2) :
    result=n1/n2
    return result

print(multiply(4,2))
print(divide(4,2))

##2
count=0

def count_factora(n):
    for i in range(1,n+1,1):
        if n%i==0 :
            count+=1
    return count
            
    
n=int(input())
result=count_factora(n)
print(result)

##3

def sum_digit(n) :
    result=0
    
    while n>0 :
        result+=n%10
        n//=10

    return result

n=int(input())
result = sum_digit(n)
print(result)


##4
def get_gcd(n1,n2):
    if n1>=n2 :
        for i in range(1,n2+1,1):
            if n1%i==0 and n2%i==0:
                result=i
    else :
        for i in range(1,n1+1,1):
            if n1%i==0 and n2%i==0:
                result=i
    return result

n1 = int(input())
n2 = int(input())
print(get_gcd(n1, n2))

##1
a=[3,4,5,1,2]

for i in range(len(a)):
    print(a[i])
    
##2
a=[5,2,4,1,3]

for i in range(len(a)-1):
    for j in range(len(a)-1):
        if a[j]>a[j+1]:
            tmp=a[j]
            a[j]=a[j+1]
            a[j+1]=tmp
print(a)

##3
a=[8,6,9,10,4,7,10,6,8,7]

Max=a[0]
Idx=0

for i in range(len(a)):
    if a[i]>Max:
        Max=a[i]
        Idx=i

print("Max=%d"%Max)
print("Idx=%d"%Idx)
'''
##4
s=[]

n=int(input())

for i in range(n) :
    s.append(int(input()))

max=s[0]
min=s[0]

for i in range(len(s)):
    if s[i]>max:
        max=s[i]
    if s[i]<min:
        min=s[i]

print("max=%d"%max)
print("min=%d"%min)
