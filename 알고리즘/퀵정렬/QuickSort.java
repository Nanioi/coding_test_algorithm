package 알고리즘.퀵정렬;
import java.util.*;


public class QuickSort{
    public static List<Integer> quickSort(List<Integer> arr){
        if(arr.size() <= 1) return arr;

        int pivot = arr.get(arr.size()/2);
        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();

        for(int num : arr){
            if(num < pivot) left.add(num);
            else if(num == pivot) middle.add(num);
            else right.add(num);
        }

        List<Integer> sorted = new ArrayList<>();
        sorted.addAll(quickSort(left));
        sorted.addAll(middle);
        sorted.addAll(quickSort(right));
        return sorted;
    }
    public static void main(String[] args){
        List<Integer> input = Arrays.asList(3, 6, 8, 10, 1, 2, 1);
        List<Integer> sorted = quickSort(input);
        System.out.println(sorted);
    }
}