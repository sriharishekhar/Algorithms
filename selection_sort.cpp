#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int a[], int n)
{
	int i, j, min;  

	for (int i = 0; i < n; i++)
	{
	    for (i = 0; i < n; i++)  
    	{  
        	min = i;  
        	for (j = i+1; j < n; j++)  
        	if (a[j] < a[min])  
            min = j;  
  
  	        swap(&a[min], &a[i]); 		
		}

		cout << "Sorted array = ";
	
		for (int i = 0; i < n; i++)
		{ 
			cout << a[i] << " ";
		}
	}
}

int main()
{
	int a[] = {5,21,3,14,1};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "Unsorted array = ";
	
	for (int i = 0; i < n; i++)
	{ 
		cout << a[i] << " ";
	}
	cout << endl;
	
	selection_sort(a, n);
	return 0;
}