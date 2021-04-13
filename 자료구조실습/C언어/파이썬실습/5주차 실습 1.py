def highest_score(a,b,c):
    if(a>b):
        if(a>c):
            highscore=a
        else:
            highscore=c
    else:
        if(b>c):
            highscore=b
        else:
            highscore=c
    return(highscore)

a=int(input())
b=int(input())
c=int(input())

print(highest_score(a,b,c))
