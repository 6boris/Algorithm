<?php
/*
 * @Author: Kyle Liu 
 * @Date: 2018-04-10 21:28:48 
 * @Last Modified by: Kyle Liu
 * @Last Modified time: 2018-04-10 21:38:05
 * @Description: 02.选择排序
*/

function SelectSort($arr){
    $len = count($arr);
    for( $i=0 ; $i<$len ; $i++ ){
        $tmp = $arr[$i];
        for($j=$i-1 ; $j>=0 ; $j--){
            if($tmp < $arr[$j]){
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;
            }else{
                break;
            }

        }
    }
    return $arr;
}


$arr = [2,5,6,8,2,3,1,44,2];
print_r(SelectSort($arr));





