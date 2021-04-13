def even_odd(n):
    return(n%2)




num1=int(input("정수를 입력하시오:"))
num2=int(input("정수를 입력하시오:"))

if even_odd(num1):
    print("홀수입니다.")
else:
    print("짝수입니다.")
if even_odd(num2):
    print("홀수입니다.")
else:
    print("짝수입니다.")
