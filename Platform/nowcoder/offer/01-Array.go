package main

import (
	"fmt"
)

func Solution(arr [][]int, num int) bool {

	for i, j := 0, len(arr[0])-1; i < len(arr) && j >= 0; {
		// fmt.Println(arr[i][j])
		if arr[i][j] > num {
			j--
			continue
		} else if arr[i][j] < num {
			i++
			continue
		} else {
			return true
		}
	}

	return false
}

func main() {
	arr := [][]int{
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25},
		{26, 27, 28, 29, 30},
		{31, 32, 33, 34, 35},
	}

	fmt.Println(Solution(arr, 33))
}
