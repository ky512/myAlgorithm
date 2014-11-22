#include <iostream>
#include <vector>
using namespace std;

/**
 * Simple insertion sort.
 **/
template <class Comparable>
void insertionSort( vector<Comparable>& a )
{
    int j;

    for( int p = 1; p < a.size( ); p++ )
    {
        Comparable tmp = a[ p];
        for( j = p; j > 0 && tmp < a[ j - 1 ]; j-- )
            a[ j ] = a[ j - 1 ];
        a[ j ] = tmp;
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
	insertionSort(array);
	for(vector<int>::const_iterator item=array.begin();item!=array.end();item++)
	{
		cout<<*item<<' ';
	}

	return 0;
}
