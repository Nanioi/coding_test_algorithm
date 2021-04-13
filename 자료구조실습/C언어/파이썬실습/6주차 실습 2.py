score=[]
x=int(input())
score.append(x)
y=int(input())
score.append(y)
z=int(input())
score.append(z)

def average_score(x,y,z):
    average=(x+y+z)/3.0
    return(average)

if (average_score(x,y,z))<60.0:
    print("non pass")
else:
    print("pass")
