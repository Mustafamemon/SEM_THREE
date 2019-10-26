#include<iostream>
#include<queue>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>


using namespace std ;
// time
class Queries
{
	private:
		int start_time ;
		int duration ;
		int c_time ;
	public:
		Queries()
		{
			start_time=0;
			duration=0;
			c_time=0;
		}
		Queries(int s_time , int aduration ,int ac_time)
		{
			start_time=s_time;
			duration=aduration;
			c_time=ac_time;
		}
		friend ofstream& operator<<(ofstream &output ,const Queries &c);
		friend ostream& operator<<(ostream &output ,const Queries &c);
		friend istream& operator>>(istream &input, Queries &d);
		Queries* operator = (const Queries &Q)
		{
			if(this!=&Q)
			{
				start_time=Q.start_time;
				duration=Q.duration;
				c_time=Q.c_time;
			}
				return this; 
		}
		//start time
		int _start_time()
		{
			return start_time; 
		}
		// duration time
		int _duration()
		{
			return duration;
		}
		// comercial time
		int _c_time()
		{
			return c_time;
		}
		// end time
		int end_time()
		{
			return (start_time+duration+c_time);
		}
};
// compare time to get minimum in start time
struct compare{
	bool operator()(Queries Q1, Queries Q2) 
    { 
    	if(Q1._start_time() != Q2._start_time())
 	       return Q2._start_time() < Q1._start_time();
		else
		{
			return false;
			//return true ;
		}
    } 
    
};
// input
istream& operator>>(istream &input, Queries &d)
{
	input>>d.start_time>>d.duration>>d.c_time;
	return input ;
}
// output 
ofstream& operator<<(ofstream &output ,const Queries &c)
{	
	output<<c.start_time<<" "<<c.duration<<" "<<c.c_time;
	return output ;
}
// output
ostream& operator<<(ostream &output ,const Queries &c)
{	
	output<<c.start_time<<" "<<c.duration<<" "<<c.c_time;
	return output ;
}
// BST class
class BST
{	
	public:
		BST* left ;
		Queries Q; 
		BST* right ;
		BST()
		{
			left=NULL; 
			right=NULL;
		}
};
// insert in bst
BST* insert(BST *r , Queries q)
{
	if(r==NULL)
	{
		r=new BST ;
		r->Q=q;
	}
	else 
	{
		if(r->Q._start_time()>=q._start_time())
		{
			r->left=insert(r->left,q);
		}
		else
		{
			r->right=insert(r->right,q);
		}
	}
	return r ;
}
// inorder
void InOrder(BST *root, string name)
{
	ofstream fout;
	fout.open(name.c_str(),ios::app);
	if(root!=NULL)
	{
		InOrder(root->left,name);
		cout<<root->Q<<endl;
		fout<<root->Q<<endl;
		InOrder(root->right,name);
	}
}

int main()
{
	int num ;
	// Priority Queue Built in
	priority_queue <Queries , vector <Queries> ,compare> PQ ; 
	
	Queries Qu,Qu1; 
	BST *root=NULL;  BST *Conflicting=NULL; BST *Compatible=NULL;
	
	fstream fin ;
	
	char file_name[30];
	
	srand(time(NULL));
	// random number
	
	int rand_n=rand()%4+1; 
	//getting file name
	
	sprintf(file_name,"A3P1ProgMgr%i.txt",rand_n);
	
	fin.open(file_name,ios::in);
	if(fin.is_open())
	{
		cout<<"File Open : "<<file_name<<endl;	
		fin>>num;
		fin>>Qu;
	
		// first input of file insert in root
		Compatible=insert(Compatible,Qu);
		for(int i=0;i<num-1;i++)
		{
			fin>>Qu;
			PQ.push(Qu);		
		}		
		fin.close();
		
		for(int j=1;j<=5;j++)
		{
			if(j!=rand_n)
			{
				sprintf(file_name,"A3P1ProgMgr%i.txt",j);
				
				fin.open(file_name,ios::in);
				if (fin.is_open())
				{
					cout<<"File Open : "<<file_name<<endl;
					fin>>num;
					for(int i=0;i<num;i++)
					{
						fin>>Qu;
						PQ.push(Qu);		
					}		
					fin.close();
				}
				else
				{
					cout<<"File Not Found! ";
					exit(0);
				}
			}
			
		}
	}
	else
	{
		cout<<"File Not Found! ";
		exit(0);
	}	
	//  Queue empty
	//cout<<"root\n";
	while (PQ.empty() == false) 
    { 
		Qu=PQ.top();
	//	cout<<Qu<<endl;
		if(Qu.end_time()<=Compatible->Q._start_time()&& Qu._start_time()>=Qu1.end_time())
		{
			Qu1=Qu;
			Compatible=insert(Compatible,Qu);	
		} 
		else if(Compatible->Q.end_time()<=Qu._start_time() &&Qu._start_time()>=Qu1.end_time())
		{
			Qu1=Qu;
			Compatible=insert(Compatible,Qu);
		}
		else
		{
			Conflicting=insert(Conflicting,Qu);
		}	
		
		PQ.pop();
    }
    
	cout<<"Conflicting\n";
	InOrder(Conflicting,"Conflicting.txt");
	
	cout<<endl<<"Compatible\n"; 
	InOrder(Compatible,"Compatible.txt");
	
	return 0 ;
}
