def average(list):
    return(list[0]+list[1]+list[2])/3

score=[]
x=int(input())
score.append(x)
y=int(input())
score.append(y)
z=int(input())
score.append(z)

avg=average(score)

if avg<60:
    print("non pass")
else:
    print("pass")
