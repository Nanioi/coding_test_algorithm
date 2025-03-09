//https://www.acmicpc.net/problem/1987

import java.io.BufferedReader
import java.io.InputStreamReader

//방향 벡터 선언
val dx = arrayOf(0, 0, 1, -1)
val dy = arrayOf(1, -1, 0, 0)


lateinit var board : Array<CharArray>
// val board = mutableListOf<String>()
var maxRoutesLength = 0 

fun main() = with(System.`in`.bufferedReader()){
    
    //input
    val (n,m) = readLine().split(" ").map{ it.toInt() }
    board = Array(n){ readLine().toCharArray() }
    // repeat(n){
    //     board.add(readLine())
    // }

    // (0,0)부터 탐색 시작
    bfs(0,0,n,m)
    print(maxRoutesLength)
}

fun bfs(x:Int, y:Int, n:Int, m:Int){

    var needVisit = mutableSetOf<Triple<Int, Int, String>>()
    needVisit.add(Triple(x,y,board[x][y].toString()))

    while (needVisit.isNotEmpty()){
        val (i,j,steps) = needVisit.first()
        needVisit.remove(needVisit.first())

        maxRoutesLength = maxOf(maxRoutesLength, steps.length)

        // x,y 좌표 기준으로 상,하,좌,우 돌면서 경로 체크
        for (ii in 0..3){
            val xx = i + dx[ii]
            val yy = j + dy[ii]

            if(xx >= 0 && xx < n && yy >=0 && yy<m && !steps.contains(board[xx][yy])){
                needVisit.add(Triple(xx,yy,steps+board[xx][yy]))
            }
        } 
    }
}