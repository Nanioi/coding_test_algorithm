fun selectionSort(arr : IntArray) : IntArray{
    val n = arr.size
    for(i in 0 until n-1){
        var minIndex = i
        for(j in i+1 until n){
            if(arr[minIndex] > arr[j]){
                minIndex = j
            }
        }
        val temp = arr[minIdex]
        arr[minIndex] = arr[i]
        arr[i] = temp
    }
    return arr
}

fun main() {
    val arr = intArrayOf(64, 25, 12, 22, 11)
    selectionSort(arr)
    println(arr.joinToString(" "))
}
