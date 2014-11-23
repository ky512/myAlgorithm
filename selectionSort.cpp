#include <iostream>
#include <vector>
using namespace std;

/**
 * Simple select sort.
 **/

template <class Comparable>
void selectionSort( vector<Comparable>& a )
{
	int k=0;
	Comparable temp;
	for(int i=0;i<a.size();i++)
	{
		k=i;
		for(int j=i;j<a.size();j++)
		{
			if(a[k]>a[j])
			{
				k=j;
			}
		}
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
}

int main(int argc,char* argv[])
{
	vector<int> array;
	array.push_back(3);
	array.push_back(2);
	array.push_back(4);
	array.push_back(5);
	array.push_back(6);
	selectionSort(array);
	for(vector<int>::const_iterator item=array.begin();item!=array.end();item++)
	{
		cout<<*item<<' ';
	}

	return 0;
}
