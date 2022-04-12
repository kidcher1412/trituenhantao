#include <iostream>
#include <fstream>
const int MAX_SIZE = 1000;
using namespace std;
int checkvisited[100];
void input(int a[100][100],int &n) {
	ifstream fi("thamlamdothi.inp");
	fi >> n ;
	for (int i = 0 ; i<n; ++i)
    for (int j = 0 ; j<n; ++j)
	{
		fi >> a[i][j];
		checkvisited[i]=0;
	 }
	fi.close();
}
int minhang(int a[100][100], int n,int row)
{
    int i,j;
    int min=a[row][0];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(checkvisited[j]==0)
			if(a[row][j]<min)
                min=a[row][j];
    return min;
}
int main()
{
	int a[100][100];
    int n;
	input(a,n);
/*	cout<<n<<endl;
    	for (int i = 0 ; i<n; ++i)
        {
        cout<<endl;
    	for (int j = 0 ; j<n; ++j) cout<<a[i][j]<<" ";
        }
*/
	int start;
	cout<<"nhap dinh bat dau: "; cin>>start;
	start=start-1;
	int started=start;
	checkvisited[start]=1;
	
	int t=3;
	int s=0;
	while(t<n)
	{
	
		for(int j=0;j<n;j++)
				if(a[start][j]==minhang(a,n,start))
				{
					cout<<"di tu cot "<<start+1<<" sang cot "<<j+1<<endl;
					checkvisited[j]=1;
					s=s+a[start][j];
					start=j;
				}
		t++;
	}
	cout<<"di tu cot "<<start+1<<" sang cot "<<started+1<<endl;
	s=s+a[start][started];
	cout<<s<<endl;
}
