print("안녕하세요?")
guess=0
while guess!=5:
    g=input("1~10사이의 숫자를 입력: ")
    guess=int(g)
    if guess==5:
      print("맞습니다.")
    else:
        if guess>5:
            print("작은 수를 입력하세요.")
        if guess<5:
            print("큰 수를 입력하세요.")          
      
