#include <iostream>
using namespace std;
// Bubble Sort
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
// Quick Sort
int partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++)
	{
		if (arr[i] <= pivot)
			count++;
	}
	int pivotIndex = count + start;
	swap(arr[pivotIndex], arr[start]);
	int i = start;
	int j = end;
	while (i < pivotIndex && j > pivotIndex)
	{
		while (arr[j] >= pivot)
			j--;
		while (arr[i] < pivot)
			i++;
		swap(arr[i++], arr[j--]);
	}
	return pivotIndex;
}
void QuickSort(int arr[], int start , int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	QuickSort(arr, start, p - 1);
	QuickSort(arr, p + 1, end);
}
// Merge Sort
void Merge(int arr[], int begin, int end, int mid)
{
	int i = begin;
	int k = begin;
	int j = mid + 1;
	int temp[100];
	while (i <= mid && j <= end) 
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (j <= end)
		temp[k++] = arr[j++];
	while (i <= mid)
		temp[k++] = arr[i++];
	for (int x = begin; x < k; x++)
		arr[x] = temp[x];
}
void MergeSort(int arr[], int begin, int end)
{
	int mid = (begin + end) / 2;
	if (begin < end)
	{
		MergeSort(arr, begin, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, begin, end, mid);
	}
}
int main()
{
	return 0;
}