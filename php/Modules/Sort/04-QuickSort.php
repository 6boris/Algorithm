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


$a = array_rand(range(1,10000), 9000);
shuffle($a); //打乱数组的顺序
$t1 = microtime(true);
QuickSort($a); //冒泡排序
$t2 = microtime(true);
echo "快速排序用时：".(($t2-$t1)*1000).'ms'."\n";


