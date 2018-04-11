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


$a = array_rand(range(1,10000), 9000);
shuffle($a); //打乱数组的顺序
$t1 = microtime(true);
SelectSort($a); //冒泡排序
$t2 = microtime(true);
echo "选择排序用时：".(($t2-$t1)*1000).'ms'."\n";





