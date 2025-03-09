import sys
sys.setrecursionlimit(10000)

TC = int(input())
dx,dy = [1,0,-1,0],[0,1,0,-1]
B,visit=[],[]

def dfs(i,j,N,M):
    global B,visit
    if visit[i][j]==1:
        return
    
    visit[i][j]=1
    
    for k in range(4):
        ii,jj = i+dx[k],j+dy[k]
        if ii<0 or ii>=N or jj<0 or jj>=M or B[ii][jj]==0 or visit[ii][jj]==1:
            continue
        if B[ii][jj]==1 and visit[ii][jj]==0:
            dfs(ii,jj,N,M)

def process():
    global B,visit
    M,N,K = map(int,input().split())
    B=[[0 for i in range(M)] for i in range(N)]
    visit= [[0 for i in range(M)] for i in range(N)]
    for i in range(K):
        x,y = map(int,input().split())
        B[y][x]=1
    cnt=0
    for i in range(N):
        for j in range(M):
            if B[i][j]==0 or visit[i][j]==1:
                continue
            else:
                dfs(i,j,N,M)
                cnt+=1
    print(cnt)

for i in range(TC):
    process()