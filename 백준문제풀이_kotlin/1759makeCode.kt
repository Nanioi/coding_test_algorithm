//https://www.acmicpc.net/problem/1759

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (L, C) = readLine().split(" ").map { it.toInt() }
    val array = readLine().split(" ").sorted()

    val vowels = setOf('a', 'e', 'i', 'o', 'u')

    val result = mutableListOf<String>()

    // 조합을 생성하는 함수
    fun combination(start: Int, current: MutableList<Char>) {
        if (current.size == L) {
            //모음 갯수 
            val vowelCount = current.count { it in vowels } 
            // 자음 갯수 
            val consonantCount = current.size - vowelCount

            // 모음 1개 이상, 자음 2개 이상
            if (vowelCount >= 1 && consonantCount >= 2) {
                result.add(current.joinToString(""))
            }
            return
        }

        // 조합을 생성
        for (i in start until C) {
            current.add(array[i])
            combination(i + 1, current)
            current.removeAt(current.size - 1)
        }
    }

    // 조합 시작
    combination(0, mutableListOf())

    // 사전 순으로 출력
    result.forEach { println(it) }
}
