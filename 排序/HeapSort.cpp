/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapsort( vector<Comparable> & a )
{
    for( int i = a.size( ) / 2; i >= 0; i-- )  /* buildHeap */
        percDown( a, i, a.size( ) );
    for( int j = a.size( ) - 1; j > 0; j-- )
    {
        swap( a[ 0 ], a[ j ] );                /* deleteMax */
        percDown( a, 0, j );
    }
}

/**
 * Internal method for heapsort.
 * i is the index of an item in the heap.
 * Returns the index of the left child.
 */
inline int leftChild( int i )
{
    return 2 * i + 1;
}

/**
 * Internal method for heapsort that is used in deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void percDown( vector<Comparable> & a, int i, int n )
{
    int child;
    Comparable tmp;

    for( tmp = a[ i ]; leftChild( i ) < n; i = child )
    {
        child = leftChild( i );
        if( child != n - 1 && a[ child ] < a[ child + 1 ] )
            child++;
        if( tmp < a[ child ] )
            a[ i ] = a[ child ];
        else
            break;
    }
    a[ i ] = tmp;
}

//ky512
//HeapSort.h
#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_

#include <vector>
#include <algorithm>
using namespace std;

template<class T>
void heapSort(vector<T>& a)
{
	// build Heap
	for(int i=a.size()/2;i>=0;i--)
	{
		percDown(a,i,a.size());
	}
	//delete Max
	for(int j=a.size()-1;j>0;j--)
	{
		swap(a[0],a[j]);
		percDown(a,0,j);
	}
}

inline int leftChild(int i)
{
	return 2*i+1;
}

template<class T>
void percDown(vector<T>& a,int i,int n)
{
	int child;
	T tmp;

	for(tmp=a[i];leftChild(i)<n;i=child)
	{
		child=leftChild(i);
		if((child!=n-1)&&(a[child]<a[child+1]))
		{
			child++;
		}
		if(tmp<a[child])
		{
			a[i]=a[child];
		}
		else
			break;
	}
	a[i]=tmp;
}


#endif


//main.cpp
#include <iostream>
#include "HeapSort.h"
#include <vector>

using namespace std;
int main(int argc,char* argv[])
{
	vector<int> array;
	array.push_back(31);
	array.push_back(41);
	array.push_back(59);
	array.push_back(26);
	array.push_back(53);
	array.push_back(58);
	array.push_back(97);

	heapSort(array);

	for(vector<int>::iterator item=array.begin();item!=array.end();item++)
	{
		cout<<*item<<' '; 
	}
	return 0;
}
