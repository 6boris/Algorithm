<?php
/*
 * @Author: Kyle Liu 
 * @Date: 2018-04-10 21:38:49 
 * @Last Modified by: Kyle Liu
 * @Last Modified time: 2018-04-10 21:56:21
 * @Description: 03.插入排序 
*/

function InsertSort($arr){
    $len = count($arr);
    for($i=1 ; $i<$len ; $i++){
        $tmp = $arr[$i];
        for( $j=$i-1; $j>=0; $j-- ){
            if($tmp < $arr[$j]) {
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;  
            } else {
                break;
            }
        }
    }
    return $arr;
}

$arr = [1,2,6,5,3,8,7,11,2];
print_r(InsertSort($arr)); 
