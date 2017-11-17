#include <iostream>
#include <string>
#include <utility>
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
void merge(int *array,int left,int right,int razd)
{	
	int *array1=new int[right-left];
	int i=0;int l=left;int r=razd+1;
	while((l<=razd)&&(r<=right))
	{
		if(array[l]>array[r])
		{
			array1[i]=array[l];
			l++;i++;
		}
		else if(array[l]<array[r])
		{
			array1[i]=array[r];
			r++;i++;
		}
	}
	while (l<=razd)
	{
		array1[i]=array[l];
		l++;i++;
	}
	while (r<=right)
	{
		array1[i]=array[r];
		r++;i++;
	}
	for(i=0;i<l+r;i++)
	{
		array[i]=array1[i];
	}
	delete[]array1;
}
long mergesort(int *array,int left,int right) { 
	long razd;                   
	if (left < right)	
	return          
    	razd = (left + right)/2;
    	mergesort(array, left, razd);       
    	mergesort(array,razd	, right);  
    	merge(array, left, right, razd);    
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
