<?php
function FindNumbersWithSum($array, $sum)
{
    $res = [];
    $len = count($array);
    for( $i=0 ; $i<$len ; $i++ ){
        for( $j=$len-1 ; $j>=0 ; $j-- ){
           if($array[$i] + $array[$j] == $sum){
                $res[]=$array[$i];
                $res[]=$array[$j];
            return $res;
           }
        }
    }
    return $res;
}

$arr = [1,2,3,4,5,6,7,8];
$arr1 = FindNumbersWithSum($arr , 5);

print_r($arr1);

