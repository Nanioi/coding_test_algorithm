// https://www.acmicpc.net/problem/9663

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

val n =  BufferedReader(InputStreamReader(System.`in`)).readLine().toInt()
var result = 0
var row = IntArray(n) // [0,0,0,0,0] 

fun main(){
    dfs(0)
    print(result)
}


// i번째 행에 대한 처리 
fun dfs(i : Int) {
    if(i == n){ // 끝까지 도달한 경우 result +1 
        result +=1 
    }else{
        for(j in 0 until n){
            row[i] = j
            if(check(i)){ // 해당 행의 j열에 퀸을 놓을 수 있는 경우 
                dfs(i+1) // 다음행 탐색 
            }
        }
    }
}

fun check(i:Int) : Boolean{
    // i행의 이전 행들 탐색
    for (ii in 0 until i){
        if(row[ii] == row[i]){
            //퀸의 위치가 위에 위치
            return false
        }
        if(abs(row[ii]-row[i]) == (i-ii)){
            //퀸의 위치가 대각선에 위치
            return false
        }
    }
    return true
}
