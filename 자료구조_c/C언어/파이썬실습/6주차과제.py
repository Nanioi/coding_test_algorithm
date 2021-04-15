n=int(input())

totalm=0
totals=0
totalh=0

for i in range(0,n,1):
    m=int(input())
    totalm+=m
    s=int(input())
    totals+=s

totals+=totalm*60
totalh=totals//3600
totals%=3600
totalm=totals//60
totals%=60

print("%d hour %d minute %d second"%(totalh,totalm,totals))

    
