<?php
/*
 * @Author: Kyle Liu 
 * @Date: 2018-04-10 21:57:36 
 * @Last Modified by: Kyle Liu
 * @Last Modified time: 2018-04-10 22:02:11
 * @Description: 04.快速排序
*/

function QuickSort($arr){  
    $length = count($arr);  
    if($length <= 1){  
        return $arr;  
    }
    $base_num = $arr[0];
    $left_array = array();
    $right_array = array();

    for($i=1; $i<$length; $i++){  
        if($base_num > $arr[$i]){  
            $left_array[] = $arr[$i];  
        }else{  
            $right_array[] = $arr[$i];  
        }  
    }  
    $left_array = QuickSort($left_array);  
    $right_array = QuickSort($right_array);  
    return array_merge($left_array, array($base_num), $right_array);  
} 


$arr = [1,2,6,5,3,8,7,11,2];
print_r( QuickSort($arr) );


