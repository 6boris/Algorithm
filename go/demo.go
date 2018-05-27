package main

import (
	"fmt"
)

// 冒泡排序
func BubbleSort(arr []int) []int {
	length := len(arr)
	for i := 0; i < length; i++ {
		for j := 0; j < length-1-i; j++ {
			if arr[j] > arr[j+1] {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
	return arr
}

func selectSort(arr []int) []int {
	length := len(arr)
	for i := 0; i < length; i++ {
		min := i
		for j := i + 1; j < length; j++ {
			if arr[min] > arr[j] {
				min = j

			}
		}
		arr[i], arr[min] = arr[min], arr[i]
	}
	return arr
}

func InsertSort(arr []int) []int {
	for i := range arr {
		preIndex := i - 1
		current := arr[i]
		for preIndex >= 0 && arr[preIndex] > current {
			arr[preIndex+1] = arr[preIndex]
			preIndex -= 1
		}
		arr[preIndex+1] = current
	}
	return arr
}

func echo(arr []int) {
	for i := 0; i < len(arr); i++ {
		fmt.Print(" ", arr[i])
	}
	fmt.Println("")

}

func main() {
	arr := []int{1, 2, 5, 4, 3, 9, 8, 7, 6, 0}
	echo(arr)
	arr = InsertSort(arr)
	echo(arr)

	fmt.Println("demo")

}
