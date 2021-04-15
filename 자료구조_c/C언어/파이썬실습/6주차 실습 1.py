score=[]
x=int(input())
score.append(x)
y=int(input())
score.append(y)
z=int(input())
score.append(z)

score.sort(reverse=True)
print(score[0])

