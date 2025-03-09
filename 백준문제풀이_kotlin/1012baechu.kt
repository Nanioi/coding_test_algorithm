//https://www.acmicpc.net/problem/1012

import java.io.*;
import java.util.*;

//방향벡터 
val dx = arrayOf(0, 0, 1, -1)
val dy = arrayOf(1, -1, 0, 0)

fun main()= with(System.`in`.bufferedReader()){
    val testCaseCnt : Int = readLine().toInt()
    val result = StringBuilder()
    repeat(testCaseCnt){
       // println(getMinWormNum(this))
       //println() 의 입출력 작업은 느려 StringBuilder사용해 개선
       result.append(getMinWormNum(this)).append('\n')
    }
    print(result)
}

fun getMinWormNum(br : BufferedReader): Int {
  var result = 0
  val (m,n,k) = br.readLine().split(" ").map{ it.toInt() }
  val baechu = Array(n){ IntArray(m) {0} }
  val checked = Array(n){ IntArray(m) {0} }

  repeat(k){
      val (j,i) = br.readLine().split(" ").map{ it.toInt() }
      baechu[i][j] = 1
  }
  // println(baechu.contentDeepToString())
  for (i in 0 until n){
    for(j in 0 until m){
      if(checked[i][j] == 0 && baechu[i][j] == 1){
        result+=1
        // 주변 탐색 
        dfs(i,j,n,m,baechu,checked)
      }
    }
  } 
  return result
}

fun dfs(i: Int, j:Int,n:Int,m:Int, baechu: Array<IntArray>, checked:Array<IntArray>){
  for(d in 0..3){
    val ii = i+dx[d]
    val jj = j+dy[d]

    // 범위안에 있으면서 탐색해야하는 좌표인지 체크 
    if(ii >= 0 && ii < n && jj >=0 && jj < m && checked[ii][jj]==0 && baechu[ii][jj]==1){
      checked[ii][jj]=1
      dfs(ii,jj,n,m,baechu,checked)
    }
  }
}