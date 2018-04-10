<?php
/*
 * @Author: Kyle Liu 
 * @Date: 2018-04-10 21:14:41 
 * @Last Modified by: Kyle Liu
 * @Last Modified time: 2018-04-10 21:30:06
 * @Description: 01.冒泡排序
*/

function BubbleSort($arr){
    $len = count($arr);
    for( $i=0 ; $i<$len ; $i++ ){
        for( $j=0 ; $j<$len-i ; $j++ ){
            if( $arr[$j]>$arr[$j+1] ){
                $tmp = $arr[$j+1];
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;
            }
        }
    }
    return $arr;
}

$arr = [1,2,3,7,6,1,9,8,3];

print_r(BubbleSort($arr));


