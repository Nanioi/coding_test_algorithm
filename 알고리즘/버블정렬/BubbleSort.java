public class BubbleSort{
    public static void bubbleSort(int[] data){
        int n = data.length;
        for(int i=0; i<n-1; i++){
            boolean swapped = false;
            for(int j=0; j< n-i-1; j++){
                if(data[j] > data[j+1]){
                    int temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                    swapped = true;
                }
            }
            if(!swapped){
                break;
            }
        }
    }

    public static void main(String[] args){
        int[] arr = {5,1,4,2,8};
        bubbleSort(arr);
        System.out.print("정렬 후 배열 : ");
        for(int num : arr){
            System.out.print(num + " ");
        }
    }
}