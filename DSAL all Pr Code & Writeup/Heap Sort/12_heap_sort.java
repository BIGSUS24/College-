//Proram to implement heap sort

import java.util.Scanner;
public class HeapSort {
	public void sort(int arr[])
	{
		int n = arr.length;

		// Build heap (rearrange array)
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);

		// One by one extract an element from heap
		for (int i = n - 1; i >= 0; i--) {
			// Move current root to end
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;

			// call max heapify on the reduced heap
			heapify(arr, i, 0);
		}
	}

	// To heapify a subtree rooted with node i which is
	// an index in arr[]. n is size of heap
	void heapify(int arr[], int n, int i)
	{
		int largest = i; // Initialize largest as root
		int l = 2 * i + 1; // left = 2*i + 1
		int r = 2 * i + 2; // right = 2*i + 2

		// If left child is larger than root
		if (l < n && arr[l] > arr[largest])
			largest = l;

		// If right child is larger than largest so far
		if (r < n && arr[r] > arr[largest])
			largest = r;

		// If largest is not root
		if (largest != i) {
			int swap = arr[i];
			arr[i] = arr[largest];
			arr[largest] = swap;

			// Recursively heapify the affected sub-tree
			heapify(arr, n, largest);
		}
	}

	/* A utility function to print array of size n */
	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}

	// Driver program
	public static void main(String args[])
	{
		
Scanner sc=new Scanner(System.in);
		int n;    //Declare array size
     		System.out.println("Enter the total number of elements ");
    		n=sc.nextInt();     //Initialize array size

     		int arr[]=new int[n];   //Declare the array
      		System.out.println("Enter the elements of the array ");
     		 for(int i=0; i<n ;i++)     //Initialize the array
     		 {
      		    arr[i]=sc.nextInt();
      		}
//int arr[] = { 12, 11, 13, 5, 6, 7 };
//		int n = arr.length;

		HeapSort ob = new HeapSort();
		ob.sort(arr);

		System.out.println("Sorted array is");
		printArray(arr);
	}
}

/* Output


Enter the total number of elements 
7
Enter the elements of the array 12
4
5
67
2
56
40
Sorted array is
2 4 5 12 40 56 67 

*/
