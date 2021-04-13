def bank(deposit):
    interest=int(deposit*0.1)
    hap=deposit+interest

    return[deposit,interest,hap]

deposit=int(input("얼마를 예치하시겠습니다?"))
list=bank(deposit)
print("원금:",list[0])
print("이자:",list[1])
print("원리합계:",list[2])
    
    
          
