package 알고리즘.병합정렬;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MergeSort {
    public static List<Integer> mergeSort(List<Integer> arr){
        if(arr.size() <= 1){
            return arr;
        }

        int mid = arr.size() /2;
        List<Integer> left = mergeSort(arr.subList(0,mid));
        List<Integer> right = mergeSort(arr.subList(mid,arr.size()));
        
        return merge(left,right);
    }

    public static List<Integer> merge(List<Integer> left, List<Integer> right){
        List<Integer> result = new ArrayList<Integer>();
        int i=0, j =0;

        while (i < left.size() && j < right.size()){
            if(left.get(i) < right.get(j)){
                result.add(left.get(i));
                i++;
           }else{
                result.add(right.get(j));
                j++;
           }
        }
        result.addAll(left.subList(i, left.size()));
        result.addAll(right.subList(j, right.size()));
        return result;
    }

    public static void main(String[] args){
        List<Integer> input = Arrays.asList(3, 6, 8, 10, 1, 2, 1);
        List<Integer> sorted = mergeSort(input);
        System.out.println(sorted);
    }
}
