#include <bits/stdc++.h>

using namespace std;



int main()
{
    vector<vector <int> > arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int j=0 , counter=0;
    int sum = 0 ,max=0;
    for(int i=0;i<4;i++)
    {
        while(j<4)
        {
            while(counter!=3)
            {
            	cout<<arr[i][j]<<" ";
                sum=sum+arr[i][j];
                counter++;
                j++;
            }
            sum=sum+arr[i+1][j-2];
            cout<<endl<<" "<<arr[i+1][j-2]<<" "<<endl;
			counter=0;
            j=j-3;
            while(counter!=3)
            {
            	cout<<arr[i+2][j]<<" ";	
                sum=sum+arr[i+2][j];
                counter++;
                j++;
            }
            cout<<endl;
            counter=0;
            j=j-2;
            if(max<sum)
                max=sum;
            sum=0;
        }
        counter=0;
        sum=0;
        j=0;
    }
    cout<<max;
    return 0;
}

