
def partition(arr, low, high):
	pivot = arr[high]
	i = low-1

	for j in range(low, high):
		if (arr[j] < pivot):
			i += 1
			arr[i], arr[j] = arr[j], arr[i]

	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i+1


def quickSort(arr, low, high):
	if(low < high):
		pivot_index = partition(arr, low, high)
		quickSort(arr, low, pivot_index-1)
		quickSort(arr, pivot_index+1, high)


arr = list(map(int, input().split(' ')))
n = len(arr)
quickSort(arr, 0, n-1)

print("Sorted Array: ", arr)

