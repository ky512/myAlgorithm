#include <iostream>
#include <vector>
using namespace std;

/**
 *	merge sort
 **/
 
 void swap(int array[],int i,int j)
 {
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
 }
 
 void Merge(int src[],int dst[],int low,int mid,int high)
 {
	int i=low;
	int j=mid+1;
	int k=low;

	while((i<=mid)&&(j<=high))
	{
		if(src[i]<src[j])
		{
			dst[k]=src[i];
			i++;
			//k++;
		}
		else
		{
			dst[k]=src[j];
			j++;
			//k++
		}
		k++;
	}
	while(i<=mid)
	{
		dst[k++]=src[i++];
	}
	while(j<=high)
	{
		dst[k++]=src[j++];
	}
 }

 void MSort(int src[],int dst[],int low,int high,int max)
 {
	 if(low==high)
	 {
		 dst[low]=src[low];
	 }
	 else
	 {
		 int mid=(low+high)/2;
		 int* space=new int[10];
		 MSort(src,space,low,mid,max);
		 MSort(src,space,mid+1,high,max);
		 Merge(space,dst,low,mid,high);
		 delete [] space;
	 }

 }
 void mergeSort(int array[],int len)  //O(nlog(n))
 {
	 MSort(array,array,0,len-1,len);	
 }
 
int main(int argc,char* argv[])
{
	int array[]={49,38,65,97,26,13,27,49,55,4};

	mergeSort(array,10);

	for(int i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}

	return 0;
}
