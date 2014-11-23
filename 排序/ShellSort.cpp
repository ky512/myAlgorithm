#include <iostream>
#include <vector>

using namespace std;

/**
 *	shell sort.
 **/

void shellSort(int array[],int len)
{
	for(int gap=len/3+1;gap>0;gap=gap/3+1)
	{
		int index;
		int temp;
		for(int i=0;i<gap;i++)
		{
			//²åÈëÅÅÐòstart
			for(int j=gap;j<len;j+=gap)
			{
				temp=array[j];
				index=j;
				for(int k=j-gap;(k>=0)&&(temp<array[k]);k-=gap)
				{
					array[index]=array[k];
					index=k;
				}
				array[index]=temp;
			}
			//²åÈëÅÅÐòend

		}
	}
}

int main(int argc,char* argv[])
{
	int array[]={49,38,65,97,26,13,27,49,55,4};

	shellSort(array,10);

	for(int i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}

	return 0;
}