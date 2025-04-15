package 알고리즘.삽입정렬;

public class InsertionSort {

    // 방법1 - while + shift 
    public static void insertionSortShift(int[] arr) {
        for (int i=1; i< arr.length; i++){
            int key = arr[i];
            int j = i-1;
            while (j >=0 && arr[j] > key){
                arr[j+1] = arr[j]; // shift
                j--;
            }
            arr[j+1] = key; // insert
        }
    }

    // 방법2 - for + swap 
    public static void insertionSortSwap(int[] arr) {
        for (int i=1; i<arr.length; i++){
            for (int j=i-1; j>=0; j--){
                if(arr[j] < arr[j-1]){
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }else{
                    break; // 이 앞은 이미 정렬된 상태
                }
            }
        }
    }

    public static void main(String[] args){
        int[] arr = {5,1,4,2,8};
        insertionSortShift(arr);
        // insertionSortSwap(arr);
        System.out.print("정렬 후 배열 : ");
        for(int num : arr){
            System.out.print(num + " ");
        }
    }
}
