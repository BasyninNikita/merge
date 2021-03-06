#include <iostream>
#include <string>
#include <sstream>
using namespace std;
void vyvod(int *array,unsigned int size)
{
	for(unsigned int i=0;i<size;i++)
	{
		cout<<array[i]<<" ";
	}
}
bool vvod(int *array,unsigned int size)
{
    string stroka;
    getline(cin,stroka);	
    istringstream stream(stroka);
    for(unsigned int i=0;i<size;i++)
    {
        if(!(stream>>array[i])){
            cout<<"nepolnuy massiv";
            return false;
        }   	
    }
    return true;
} 
void mergesort(int * array,int left, int right)
{
    if (left < right)
    {
        int razd = (left + right)/2;
        mergesort(array, left, razd);
        mergesort(array, razd+1, right);
        int * array1 = new int[right - left +1];
        int i = 0;
        int l = left;
        int r = razd + 1;
        while(l <= razd && r <= right)
        {
             if(array[l] < array[r])
             {
                array1[i] = array[l++];
             }
             else
             {
                 array1	[i] = array[r++];
             }
             i++;
        }
        while( r <= right )
        {
             array1[ i ] = array[ r++ ];
             i++;
        }
        while( l <= razd )
        {
              array1[ i ] = array[ l++ ];
              i++;
        }
        for( i = 0; i < right-left+1; i++ )
        {
           array[left+i] = array1[i];
        }
        delete [] array1;
    }
}
int main(int argc, char** argv) {
	unsigned int size;
	string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	if(!(stream>>size)){
        	cout<<"error"<<endl;
       		return -1;
    	}	
	int *array=new int[size];
	if(vvod(array,size))
	{
		mergesort(array,0,size-1);
		vyvod(array,size);
	}
	delete[]array;
	return 0;
}
