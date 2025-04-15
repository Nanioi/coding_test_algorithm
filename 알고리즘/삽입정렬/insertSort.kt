fun insertionSortShift(arr: IntArray) : IntArray{
    var n = arr.size
    for (i in 1 until n){
        val key = arr[i]
        var j=i-1
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j] // shift
            j--
        }
        arr[j+1] = key
    }
    return arr
}

fun insertionSortSwap(arr: IntArray) : IntArray{
    var n = arr.size
    for (i in 1 until n){
        for(j in i downTo 1){
            if(arr[j] > arr[j-1]){
                val temp = arr[j]
                arr[j] = arr[j-1]
                arr[j-1] = temp
            }else{
                break
            }
        }
    }
    return arr
}

fun main() {
    val arr = intArrayOf(5, 1, 4, 2, 8)
    insertionSortShift(arr)
    //insertionSortSwap(arr)
    println("정렬된 배열: ${arr.joinToString(" ")}")
}