def bfs(x,y):
    global result

    #동일한 경우는 한 번만 계산하기 위해 set사용
    q=set()
    q.add((x,y,a[x][y]))

    while q:
        x,y,step=q.pop()
        # 가장 긴 이동거리 저장
        result=max(result,len(step))
        
        for i in range(4):
            xx,yy=x+dx[i],y+dy[i]
            if xx>=0 and xx<n and yy>=0 and yy<m and a[xx][yy] not in step:
                q.add((xx,yy,step+a[xx][yy]))

n,m=map(int,input().split())
a=[]
dx,dy=[0,-1,0,1],[1,0,-1,0]
for _ in range(n):
    a.append(input())

result=0
bfs(0,0)
print(result)
