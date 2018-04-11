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


$a = array_rand(range(1,10000), 9000);
shuffle($a); //打乱数组的顺序
$t1 = microtime(true);
InsertSort($a); //冒泡排序
$t2 = microtime(true);
echo "插入排序用时：".(($t2-$t1)*1000).'ms'."\n";
