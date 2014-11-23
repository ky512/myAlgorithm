#include <iostream>
#include <vector>

using namespace std;

/**
 *	quick sort
 **/
 
 void swap(int array[],int i,int j)
 {
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
 }
 
 int  partition(int array[],int low,int high)
 {
	int pv=array[low];
	while(low<high)
	{
		while((low<high)&&(array[high]>=pv))
		{
			high--;
		}
		swap(array,low,high);
		while((low<high)&&(pv>=array[low]))
		{
			low++;
		}
		swap(array,low,high);
	}
	return low;
 }
 
 void QSort(int array[],int low,int high)
 {
	if(low<high)
	{
		int pivot=partition(array,low,high);
		QSort(array,low,pivot-1);
		QSort(array,pivot+1,high);
	}
 }
 
 void quickSort(int array[],int len)
 {
	QSort(array,0,len-1);
 }
 
int main(int argc,char* argv[])
{
	int array[]={49,38,65,97,26,13,27,49,55,4};

	quickSort(array,10);

	for(int i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}

	return 0;
}
