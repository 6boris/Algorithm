package main

import "fmt"

func main() {
	arr := [10]int{1, 4, 8, 7, 6, 5, 9, 10, 2, 3}
	fmt.Println("Source:", arr)

	tmp := 0
	for i := 0; i < len(arr); i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				tmp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = tmp
			}
		}
	}

	fmt.Println("Sort:  ", arr)

}
