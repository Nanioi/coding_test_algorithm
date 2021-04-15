def plus(a,b):
    return(a+b)
def minus(a,b):
    return(a-b)
def multi(a,b):
    return(a*b)
def div(a,b):
    return(a//b)

a=int(input())
b=int(input())
p=plus(a,b)
m=minus(a,b)
mt=multi(a,b)
d=div(a,b)

print("합:",p)
print("차:",m)
print("곱:",mt)
print("몫:",d)
