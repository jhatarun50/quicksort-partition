. Quick Sort is a divide-and-conquer algorithm that works by selecting a pivot element and partitioning the array into two sub-arrays: one containing elements smaller than the pivot and the other containing elements greater than the pivot. The array is then recursively sorted by applying the same process to the sub-arrays.

Plan:
Choose a Pivot: In this case, you can use the last element in the array as the pivot (common practice).
Partition the Array: Reorder the array so that elements smaller than the pivot come before it, and elements greater than the pivot come after it.
Recursively Apply: Apply the same process to the left and right sub-arrays.
Key Operations:
Partition: This function will reorder the array around a pivot such that all elements smaller than the pivot come before it, and all elements greater than the pivot come after it. After partitioning, return the index of the pivot.
QuickSort: This will call itself recursively on the left and right parts of the array based on the pivot position.
