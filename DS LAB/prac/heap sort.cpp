
#include <iostream>
using namespace std;

void Heapify(int array[], int i, int n)
{
 	int largest,temp;
  	int left=2*i;
  	int right=(2*i+1);
  	if((left<=n)&&array[left]<array[i])
  		largest=left;
  	else
  		largest=i;
  	if((right<=n)&&(array[right]<array[largest]))
  		largest=right;
  	if(largest!=i)
    {
      	temp=array[i];
     	array[i]=array[largest];
      	array[largest]=temp;
    	Heapify(array, largest,n);
    }
}
void heap(int array[], int n)
{
  	for(int k = n/2; k >= 1; k--)
    {
    	Heapify(array, k, n);
    }
}
void Heapsort(int array[], int n)
{
  	heap(array,n);
  	int i, temp;
  	for (i = n; i >= 2; i--)
  	{
	    temp = array[i];
	    array[i] = array[1];
	    array[1] = temp;
      	Heapify(array,1, i-1);
    }
}

int main()
{
  	int n;
  	cout<<"Enter the size of the array"<<endl;
  	cin>>n;
  	int *array=new int [n];
  	cout<<"Enter the elements in the array"<<endl;
  	for (int i = 1; i <= n; i++)
  	{
      	cin>>array[i];
		
    }
    
//  	Heapsort(array, n);
  	cout<<"SORTED\n";
  	for (int i = 1; i <=n; i++)
  	{
  		int *a=new int [i];
  		for (int j = 1 ; j<=i ; j++){
  				a[j] = array[j];
		  }
  		Heapify(a,  0, i)

  		;for(int j = 1 ; j<=i ; j++){
    		cout<<array[j]<<" ";
    	}
    	cout<<endl;
  		for(int j = 1 ; j<=i ; j++){
    		cout<<a[j]<<" ";
    	}
    	cout<<endl;
    	delete a;
    }
}

