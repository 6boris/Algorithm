package main

import "fmt"

func InsertSort(arr [10]int) [10]int {
	var i, j, tmp int
	for i = 1; i < len(arr); i++ {
		tmp = arr[i]
		for j = i; j > 0 && arr[j-1] > tmp; j-- {
			arr[j] = arr[j-1]
		}
		arr[j] = tmp
	}
	return arr
}

func main() {
	arr := [10]int{1, 4, 8, 7, 6, 5, 9, 10, 2, 3}
	fmt.Println("Source:", arr)

	arr = InsertSort(arr)

	fmt.Println("Sort:  ", arr)

}
