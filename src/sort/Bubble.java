package sort;

/**
* 
* Title: Bubble Sort
* Description:
* @author Kyle Liu  
* @date Mar 23, 2018
*/

public class Bubble {

	public static void main(String[] args) {
		System.out.println("Bubble Sort");
		int[][] arr = new int[2][2];
		for (int i=0 ; i<arr.length ; i++) {
			for(int j=0 ; j<arr[i].length ; j++) {
				arr[i][j] = 1	;
			}
		}
		
		
		for (int i=0 ; i<arr.length ; i++) {
			for(int j=0 ; j<arr[i].length ; j++) {
				System.out.println(arr[i][j]+" ");
			}
		}
		demo();
	}
		
	public static  void demo() {
		System.out.println("asd");
	}

}
