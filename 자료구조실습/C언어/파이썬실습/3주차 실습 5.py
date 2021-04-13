num=int(input())
sum=0
n=1
while n!=0:
    n=num%10
    sum=sum+n
    num=num//10
print(sum)
