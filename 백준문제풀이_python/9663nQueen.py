# x번째 행에 놓은 queen에 대해 검증
def check(x):
    #이전 행의 queen들 확인
    for i in range(x):
        if row[x]==row[i]: #위
            return False
        if abs(row[x]-row[i])==x-i: #대각선
            return False
    return True

#x번째 행에 대해 처리
def dfs(x):
    global result
    if x==n:
        result+=1
    else:
        #x번째 행의 각 열에 queen을 둔다고 가정
        for i in range(n):
            row[x]=i
            if check(x):
                dfs(x+1)
n=int(input())
row=[0]*n
result=0
dfs(0)
print(result)