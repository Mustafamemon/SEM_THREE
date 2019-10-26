#include <iostream> 
#include <new> 
#include <cstdlib> 
 
using namespace std; 

template <class T, int len> class dyn_safe_array 
{ 
	T *aptr;   
	int length;  
public: 
  
	dyn_safe_array(); 
	dyn_safe_array(const dyn_safe_array &obj);
  	~dyn_safe_array() 
	{   
    	delete [] aptr; 
	} 
 
  	dyn_safe_array &operator=(const dyn_safe_array<T,len> &rh_op); 
 
 	T &operator[](int i);
 	
	 int getlen() 
	{
  	 	return length; 
  	} 
}; 
 
template <class T, int len>  dyn_safe_array<T, len>::dyn_safe_array() 
{  
  try 
  { 
    aptr = new T[len]; 
  } 
  catch(bad_alloc ba) 
  { 
	cout << "Can't allocate array.\n"; 
	exit(1); 
  } 

  for(int i=0; i < len; ++i)
  	aptr[i] = T();
	
	length = len; 
} 
 
template <class T, int len>  dyn_safe_array<T, len>::dyn_safe_array(const dyn_safe_array &obj) 
{  
  	cout << "Using dyn_safe_array's copy constructor to make a copy.\n"; 
 
  	try 
  	{ 
   		aptr = new T[obj.length]; 
	} 
	catch(bad_alloc ba)
	{ 
	    cout << "Can't allocate array.\n"; 
   	 exit(1); 
  	} 
  	length = obj.length; 
 
  	for(int i=0; i < length; ++i) 
    	aptr[i] = obj.aptr[i]; 
} 
 
template<class T, int len> dyn_safe_array<T, len> &  dyn_safe_array<T, len>::operator=(const dyn_safe_array<T, len> &rh_op) 
{ 
 
	cout << "Assigning one dyn_safe_array object to another.\n"; 
  	if(aptr && (length != rh_op.length)) 
	{ 
    	delete aptr; 
     
	    try 
		{ 
	      aptr = new T[rh_op.length]; 
	    }
		catch(bad_alloc ba) 
		{ 
			cout << "Can't allocate array.\n"; 
	    	exit(1); 
	    } 
  	} 
 
 	length = rh_op.length; 
 
  	for(int i=0; i < length; ++i) 
  	  aptr[i] = rh_op.aptr[i]; 
    return *this; 
} 
 
template <class T, int len> T &dyn_safe_array<T, len>::operator[](int i) 
{ 
 	if(i < 0 || i > length) 
 	{ 
 		cout << "\nIndex value of " << i << " is out-of-bounds.\n"; 
 		exit(1); 
 	}
	return aptr[i]; 
} 
 
template <class T, int len> dyn_safe_array<T, len> f(dyn_safe_array<T, len> x) 
{ 
 	cout << "f() is returning a copy of x.\n"; 
  	return x; 
} 
class myclass 
{ 
	public: 
	  int x; 
	  myclass(int i) { x = i; }; 
	  myclass() { x = -1; } 
}; 
 
int main() 
{ 
 
 	dyn_safe_array<int, 5> i_ar; 
 
  	for(int i=0; i < i_ar.getlen(); ++i) 
  	i_ar[i] = i; 
  
  	cout << "Contents of i_ar: "; 
  
  	for(int i=0; i < i_ar.getlen(); ++i) 
  		cout << i_ar[i] << " "; 

	cout << "\n\n"; 
 
  	cout << "Create i_ar2 and initialize it with i_ar. This results\n"<< "in dyn_safe_array's copy constructor being called.\n\n"; 
  	dyn_safe_array<int, 5> i_ar2 = i_ar; 
  	cout << "Contents of i_ar2: "; 
  	
	for(int i=0; i < i_ar2.getlen(); ++i)  
	  	cout << i_ar2[i] << " "; 
 	
	 cout << "\n\n"; 
 
  	cout << "Create i_ar3.\n"; 
  	dyn_safe_array<int, 5> i_ar3; 
 
  	cout << "Original contents of i_ar3: "; 
  	
	for(int i=0; i < i_ar3.getlen(); ++i)  
	  	cout << i_ar3[i] << " "; 
  	
	cout <<"\n\n"; 
 
  	cout << "Now, this line will execute: i_ar3 = f(i_ar);\n" 
       << "This will result in the following sequence of events:\n" 
       << "   1. dyn_safe_array's copy constructor is called to make a\n" 
       << "      copy of i_ar that is passed to the x parameter of f().\n" 
       << "   2. The copy constructor is called again when a copy\n" 
       << "      is made for the return value of f().\n" 
       << "   3. The overloaded assignment operator is called to\n" 
       << "      assign the result of f() to i_ar3.\n\n"; 
  
  	i_ar3 = f(i_ar); 
  	cout << "Contents of i_ar3 after receiving value from f(i_ar): "; 
  	
	for(int i=0; i < i_ar3.getlen(); ++i)  
	  	cout << i_ar3[i] << " "; 
 	
	cout << "\n\n"; 
 	cout << "Of course, dyn_safe_array works with class types, too.\n"; 
  	
	  dyn_safe_array<myclass, 3> mc_ar; 
	cout << "Original contents of mc_ar: "; 
  	
	for(int i=0; i < mc_ar.getlen(); ++i) 
	  	cout << mc_ar[i].x << " "; 
 	 	
	cout << endl; 
  	mc_ar[0].x = 9; 
  	mc_ar[1].x = 8; 
 	mc_ar[2].x = 7; 
  	cout << "Values in mc_ar after setting them: "; 
  	
	for(int i=0; i < mc_ar.getlen(); ++i) 
	  	cout << mc_ar[i].x << " "; 
  	
	cout << "\n\n"; 
 
  	cout << "Now, create mc_ar2 and then execute this statement:\n" 
       << "   mc_ar2 = f(mc_ar);\n\n"; 
 	dyn_safe_array<myclass, 3> mc_ar2; 
  	mc_ar2 = f(mc_ar); 
  	cout << "Contents of mc_ar2 after receiving f(mc_ar): "; 
  	for(int i=0; i < mc_ar2.getlen(); ++i) 
	  	cout << mc_ar2[i].x << " "; 
 	
	cout << endl; 
 
  	return 0; 
}

