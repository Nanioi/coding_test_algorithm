

'''##1

import random

 

f = open('lotto_num.txt',"w")

balls=list(range(1,20)) 

for i in range(6):

    c=random.choice(balls)

    c=str(c)

    f.write(c)

 

##2

s=[]

for i in range(6):

    n=int(input())

    s.append(n)

print(s)

 

 

f=open('lotto_num.txt',"r")

a=f.readlines()

a[0]=int(a[0])

print(a)

 

cnt=0

for i in range(6):

    for j in range(6):

        if s[i]==a[j]:

            cnt+=1

 

print("Correct = %d "%cnt)


##1

total=0

 

while True:

    color=input("color = ")

    if color=='white':

        total+=1000

    elif color=='yellow':

        total+=2000

    elif color=='blue':

        total+=3000

    elif color=='red':

        total+=5000

    else:

        break

 

print("Total price = %d"%total)

 

##2

 

n=int(input("# of students = "))

 

S=0

D=0

O=0

avgS=0

avgO=0

avgD=0

 

for i in range(n):

 S,O,D=input("score = ").split()

 S=int(S)

 O=int(O)

 D=int(D)

 avgS+=S

 avgO+=O

 avgD+=D

 

avgS/=n

avgO/=n

avgD/=n

print("Average(SW) = %d"%avgS)

print("Average(OS) = %d"%avgO)

print("Average(DB) = %d"%avgD)

 

##3

n=[]

total=0

c=int(input("Input # of sushi = "))

 

for i in range(c):

    name=input("name = ")

    n.append(name)

 

for i in range(c):

    if n[i]=='salmon roe':

        total+=1000

    elif n[i]=='red sea bream':

        total+=3000

    elif n[i]=='egg roll':

        total+=1000

    elif n[i]=='shrimp':

        total+=2000

    elif n[i]=='kimbab':

        total+=1000

    elif n[i]=='tuna':

        total+=5000

 

print("Total price = %d"%total)

 

 

##4

 

score=[]

 

for i in range(8):

    score.append(int(input("Score = ")))
 

for i in range(7):

    for j in range(7):

        if score[j]<score[j+1]:

            tmp=score[j]

            score[j]=score[j+1]

            score[j+1]=tmp

for i in range(8):

    print(score[i])

'''
##5

Grade = [

['C', 'B', 'A', 'C', 'D'],

['F', 'D', 'C', 'D', 'B'],

['A', 'B', 'A', 'B', 'A'],

['A', 'A', 'B', 'C', 'D'],

['B', 'B', 'B', 'B', 'B'],

['B', 'B', 'C', 'D', 'F'],

['C', 'A', 'A', 'A', 'A'],

['D', 'A', 'A', 'C', 'F']

]

avg=[0]*8

print(avg)
 

for i in range(8):

    for j in range(5):

        

      if Grade[i][j]=='A':

          if j==3:

              avg[i]+=(2*4)

          elif j==4:

              avg[i]+=(1*4)

          else:

              avg[i]+=(3*4)

      elif Grade[i][j]=='B':

          if j==3:

              avg[i]+=(2*3)

          elif j==4:

              avg[i]+=(1*3)

          else:

              avg[i]+=(3*3)

      elif Grade[i][j]=='C':

          if j==3:

              avg[i]+=(2*2)

          elif j==4:

              avg[i]+=(1*2)

          else:

              avg[i]+=(3*2)

      elif Grade[i][j]=='D':

          if j==3:

              avg[i]+=(2*1)

          elif j==4:

              avg[i]+=(1*1)

          else:

              avg[i]+=(3*1)

      else:

         avg[i]+=0

    avg[i]/=12

 

for i in range(8):

    print("%d = %.2lf"%(i,avg[i]))

    

 
'''
##6

 

sub=("SW", "DB", "OS", "DS", "AI", "CG", "SE", "HCI")

 

inp=[]

s=()

 

for i in range(8):

    inp.append(input("Input Subjects = ").split())

    inp=set(inp)

    s=inp|s

    inp=list(inp)

 

 

print("Selected Subjects = ",s)

print("Deleted Subjects = ",sub-s) 

name=input()

n=int(input())

f=open(name,'w')

for i in range(1,n+1,1):

    f.write(str(i)+'\n')

f.close()

 

##2

name=input()

f=open(name,'r')

sum=0

 

while True:

    line=f.readline()

 

    if not line:

        break

    sum+=int(line)

print(sum)

f.close()



text=f.read()

print(text)



##3

name=input()

n=input()

 

f=open(name,'a')

f.write(n)

text=f.read()

print(text)

f.close()

 

##4

 

fw = open("menu.txt", "w")

print("<메뉴 입력>")

num = int(input("# of menus = "))

 

for i in range(num):

    name=input()

    fw.write("메뉴 이름: ",name,"\n")

    money=input()

    fw.write("메뉴 가격: ",money,"\n")

fw.close()

 

fw.open("menu.txt","r")

print("<메뉴판>")

text=fw.read()

print(text)

    

fw.close()

 

##5

m = input("문자열 입력 : ")

fw = open("python.txt", "w")

n=int(input("n 입력 : "))

 

fw.write(m)

fw.close()

fw=open("python.txt","r")

fw.seek(n)

c=fw.read(1)

print("%d bytes 떨어진 위치에 있는 문자 : %c" %(n,c))

 

fw.close()

 



줄바꿈 문자열 : \n

 

파일 입출력

fp = open("파일경로 및 파일명", "w") #파일 열기 => w는 쓰기, r은 읽기, a는 추가모드

fp.write("내용") #연 파일에 내용 쓰기

line = fp.readline() #연 파일에서 한 줄 읽어오기

s = fp.read() <--파일 내용 전체를 문자열로 반환

fp.seek(n) <--파일의 n번째 bite로 이동

s = fp.read(n) <--파일에서 n개의 bite만큼 반환

fp.close #열었던 파일 닫기

'''

 
