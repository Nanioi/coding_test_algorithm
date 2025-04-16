// https://www.acmicpc.net/problem/16768

import java.io.*;
import java.util.*;


val dx = arrayOf(0,0,1,-1)
val dy = arrayOf(1,-1,0,0)

fun main() = with(System.`in`.bufferedReader()) {
  val (n,k) = readLine().split(" ").map{ it.toInt() }
  val mooyoBoard = Array(n){ charArrayOf() }
  for (i in 0 until n){
    mooyoBoard[i] = readLine().toCharArray()
  }
  //print(mooyoBoard.contentDeepToString())

  var hasChange = true
  while(hasChange){
    hasChange = false
    val checked = Array(n){ IntArray(mooyoBoard[0].size) {0} }
    var ret = 0
    // todo dfs 돌면서 같은 값이 몇개인지 체크 
    for(i in 0 until n){
      for(j in 0 until mooyoBoard[i].size){
        val removeXY = mutableListOf<Pair<Int, Int>>()
        if(checked[i][j] == 0){
          ret = checkSameCnt(i,j,checked,mooyoBoard,removeXY)
        }

        // todo k개이상인 경우 제거할 값으로 변경   
        if(ret >= k){
          hasChange = true
          // 저장된 좌표들 removeXY를 제거할 값으로 변경
        }
      }
    }
    // todo 제거 후 남은 요소들 아래로 내리기 
  }


  // 출력
  for (i in 0 until n){
    println(mooyoBoard[i].joinToString(""))
  } 
}

fun checkSameCnt(i:Int, j:Int, checked: Array<IntArray>, mooyoBoard: Array<CharArray>,removeXY : MutableList<Pair<Int,Int>>): Int{
    checked[i][j] = 1
    removeXY.add(Pair(i,j))
    var cnt = 0
    for (i in 0..3){
        val ii = i + dx[i]
        val jj = j + dy[i]
    
    }

    return cnt
}