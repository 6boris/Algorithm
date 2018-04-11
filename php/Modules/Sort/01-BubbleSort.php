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
        for( $j=0 ; $j < $len-$i-1 ; $j++ ){
            if( $arr[$j] > $arr[$j+1] ){
                $tmp = $arr[$j+1];
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;
            }
        }
    }
    return $arr;
}


$a = array_rand(range(1,10000), 9000);
shuffle($a); //打乱数组的顺序
$t1 = microtime(true);
BubbleSort($a); //冒泡排序
$t2 = microtime(true);
echo "冒泡排序用时：".(($t2-$t1)*1000).'ms'."\n";



