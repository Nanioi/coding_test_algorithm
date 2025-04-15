fun bubbleSort(data : IntArray){
    val n = data.size
    for(i in 0 until n){
        var swapped = false
        for(j in 0 until n-i-1){
            if (data[j] > data[j+1]){
                val temp = data[j]
                data[j] = data[j+1]
                data[j+1] = temp
                swapped = true
            }
        }
        if (!swapped) break
    }
}

fun main(){
    val arr = IntArrayOf(5,1,4,2,8)
    println("정렬 전 배열 : ${arr.joinToString(", ")}")
    bubbleSort(arr)
    println("정렬 후 배열 : ${arr.joinToString(", ")}")
}