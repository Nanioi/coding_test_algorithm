fun mergeSort(arr : List<Int>) : List<Int>{
    if(arr.size <= 1){
        return arr
    }

    val mid = arr.size/2
    val left = mergeSort(arr.subList(0,mid))
    val right = mergeSort(arr.subList(mid, arr.size))

    return merge(left,right)
}

fun merge(left:List<Int>, right:List<Int>) : List<Int>{
    val result = mutableListOf<Int>()
    var i=0
    var j=0

    while (i < left.size && j < right.size){
        if(left[i] < right[j]){
            result.add(left[i])
            i++
        }else{
            result.add(right[j])
            j++
        }
    }

    result.addAll(left.subList(i,left.size))
    result.addAll(right.subList(j,right.size))
    return result
}

fun main() {
    val sorted = mergeSort(listOf(3, 6, 8, 10, 1, 2, 1))
    println(sorted)
}
