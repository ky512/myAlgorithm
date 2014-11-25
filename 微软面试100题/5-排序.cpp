#include <iostream>
using namespace std;

/**
 *	shell sort.
 **/

void shellSort(int array[],int len)
{
	for(int gap=len/2;gap>0;gap=gap/2)
	{
		int index;
		int temp;
		for(int i=0;i<gap;i++)
		{
			//²åÈëÅÅĞòstart
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
			//²åÈëÅÅĞòend

		}
	}
}

class MinK
{
private:
	int* array;
	int length;
public:
	MinK(int* arr,int len):array(arr),length(len)
	{

	}
	bool kmin(int k,int* &ret)
	{
		if(k>length)
		{
			return false;
		}
		ret=new int[k];
	
		for(int i=0;i<k;i++)
		{
			ret[i]=array[i];
		}
		shellSort(ret,k);
		
		for(int j=k;j<length;j++)
		{
			if(array[j]<ret[k-1])
			{
				ret[k-1]=array[j];
				shellSort(ret,4);
				/*
				for(int index=0;index<k;index++)
				{
					cout<<ret[index]<<' ';
				}
				cout<<endl;
				*/
			}
		}
		return true;
	}

};

int main(int argc,char* argv[])
{
	int arr[]={4,1,3,2,-1,6,0,7};
	/*
	insertionSort(arr);

	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<' ';
	}
	*/
	MinK temp(arr,sizeof(arr)/sizeof(arr[0]));
	int* ret;
	int k=4;
	if(temp.kmin(k,ret))
	{
		for(int i=0;i<k;i++)
		{
			cout<<ret[i]<<' ';
		}
	}

	cout<<endl;
	return 0;

}