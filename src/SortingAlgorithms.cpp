#include <iostream>

void BubbleSortByRubenid(int, int*);
void SelectionSortByRubenid(int, int*);
void InsertionSortByRubenid(int, int*);
void HeapSortByRubenid(int, int*);
void ShellSortByRubenid(int, int*);
void QuickSortByRubenid(int, int*);
void MergeSortByRubenid(int, int*);

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}	

void BubbleSortByRubenid(int size, int* array) {
 for(int i = 0; i < size; ++i) {
            bool swap = false;
            for(int j = 0; j < size - i - 1; ++j) {
                if(array[j] > array[j + 1]) {
                    Swap(array[j + 1], array[j]);
                    swap = true;
                }
            }
            if(swap == false) {
                break;
            }
        }
}

void SelectionSortByRubenid(int size, int* array) {
	for(int i = 0; i < size; ++i) {
            int min_value_index = i;
            for(int j = i; j < size; ++j) {
                if(array[j] < array[min_value_index]) {
                    min_value_index = j;
                }
            }
            Swap(array[i], array[min_value_index]);
        }
    }


void InsertionSortByRubenid(int size, int* array) {
	for(int i = 1; i < size; ++i) {
            int key = array[i];
            int j = i - 1;
            while(j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;
        }
}


int Partitioning(int* array, int start, int end) {
	int  pivot = array[end];
        int i = start - 1;
        for(int j = start; j <= end; ++j) {
            if(array[j] < pivot) {
                ++i;
                Swap(array[i], array[j]);
            }
        }
        Swap(array[i + 1], array[end]);
        return i + 1;
}

void QuickSortHelper(int* array, int start, int end) {
	if(start <= end) {
            int position = Partitioning(array, start, end);
            Partitioning(array, start, position - 1);
            Partitioning(array, position + 1, end);
        }    
}


void QuickSortByRubenid(int size, int* array) {   
    QuickSortHelper(array, 0, size - 1);
}

 void MergeHelper(int* array, int* array1, int* array2, int n1, int n2, int start)
    {
        int i = 0;
        int j = 0;
        int k = start;
        while(i < n1 && j < n2) {
            if(array1[i] <= array2[j]) {
                array[k] = array1[i];
                ++i;
            } else {
                array[k] = array2[j];
                ++j;
            }
            ++k;
        }
        while(i < n1) {
            array[k] = array1[i];
            ++i;
            ++k;
        }
        while(j < n2) {
            array[k] = array2[j];
            ++j;
            ++k;
        }
    }


void Merge(int* array, int start, int middle, int end) {
	int n1 = middle - start + 1;
        int n2 = end - middle;
        int* array1 = new int[n1];
        int* array2 = new int[n2];
        for(int i = 0; i < n1; ++i) {
            array1[i] = array[start + i];
        }
        for(int j = 0; j < n2; ++j) {
            array2[j] = array[middle + 1 + j];
        }
        MergeHelper(array, array1, array2, n1, n2, start);
        delete [] array1;
        delete [] array2;	
    }
    
void MergeSortHelper(int* array, int start, int end) {
	if(start < end) {
            int mid = start + (end - start) / 2;
            MergeSortHelper(array, start, mid);
            MergeSortHelper(array, mid + 1, end);
            Merge(array, start, mid, end);
        }
    }


void MergeSortByRubenid(int size, int* array) {
    MergeSortHelper(array, 0, size - 1);
}


void Heapify(int* array, int size, int root) {
	int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        if(left < size && array[left] > array[largest]) {
            largest = left;
        }
        if(right < size && array[right] > array[largest]) {
            largest = right;
        }
        if(largest != root) {
            Swap(array[largest], array[root]);
            Heapify(array, size, largest);
        }
	}


void HeapSortByRubenid(int size, int* array) {
       for(int i = size / 2 - 1; i >= 0; --i) {
            Heapify(array, size, i);
        }
        for(int i = size - 1; i >= 0; --i) {
            Swap(array[0], array[i]);
            Heapify(array, i, 0);
        }
}

void ShellSortByRubenid(int size, int* array) {
for(int interval = size / 2; interval > 0; interval /= 2) {
            for(int i = interval; i < size; ++i) {
                int temp = array[i];
                int j;
                for(j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                    array[j] = array[j - interval];
                }
                array[j] = temp;
            }
        }	
}


