thisyear=2018
today=int("0424")
print("이름,생년,생일(4자리수)을 입력하세요")
name=input("이름:")
yy=int(input("생년:"))
mmdd=int(input("생일:"))
age=thisyear-yy
if mmdd>today:
    age=age-1
print(name,"님의 만나이는",age,"살입니다.")
