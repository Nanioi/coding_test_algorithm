'''
total=0
count=0

while total<20 :
    dice=int(input())
    print("dice=%d"%dice)
    total+=dice
    count+=1


print("Count = %d" %count)
print("Total = %d" %total)


##2번

total=0
num=0

while total<100 :
    num+=1
    total+=num

print("Num = %d" %num)
print("Total = %d" %total)


##3번

total=0
count=0

while total<20 :
    dice=int(input())
    print("dice=%d"%dice)
    if dice!=4 :
        total+=dice
    count+=1


print("Count = %d" %count)
print("Total = %d" %total)

##4번

num=int(input())
print("num=%d"%num)

result=0
while num>10 :
    result+=num%10
    num//=10

result+=num
print("Result=%d"%result)

##5번


num=int(input())
print("num=%d"%num)

result=0
while num>0 :
    result*=10
    result+=num%10
    num//=10

print("Result=%d"%result)

##1번

num=int(input())
print("num = %d" %num)
result=1

for i in range(1,num+1,1) :
    result*=i

print("Result=%d"%result)

##2번
    
num=int(input())
print("num = %d" %num)
sum1=0
sum2=0

for i in range(1,num+1,2) :
    sum1+=i
for i in range(2,num+1,2) :
    sum2+=i

print("Sum1=%d"%sum1)
print("Sum2=%d"%sum2)

##3번

num=int(input())
count=0

for i in range(1,num+1,1) :
    if num%i==0 :
        count+=1

print("Result=%d"%count)

'''
##4번

for i in range (1,6,1) :
    for j in range(1,i+1,1) :
        print("%d"%i,end="")
    print()

