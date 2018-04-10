<?php
/**
 * 反转数组
 * @param  array $arr 
 * @return array
 */
function reverse($arr)
{
    $n = count($arr);

    $left = 0;
    $right = $n - 1;

    while ($left < $right) {
        $temp = $arr[$left];
        $arr[$left++] = $arr[$right];
        $arr[$right--] = $temp;
    }

    return $arr;
}

$arr = [1,2,3,4,5,6,7,8,9,10];
print_r(reverse($arr));

