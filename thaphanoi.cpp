#include<iostream>
using namespace std;
 
#define MAX 20

//Khai bao Prototype
int thap[3][MAX];
int top[3];
int n;


void khoidong ()
{
	for (int i=0;i<3;i++)
		thap[i][0]=MAX;
	for (int i=1;i<=n;i++)
		thap[0][i]=n-i+1;
	top[0]=n;
}

int heuristic ()
{
	int t=n,h;
	int diasai=0,diadung=0;
	for (int i=1;i<=n;i++,t--)
	{
		if (thap[1][i]!=t&&thap[1][i]!=0)
			diasai++;
			if(thap[1][i]==t)
			diadung++;
	}
	h=n+diasai-diadung;
	return h;
}

void hoantra (int cocdi,int cocden)
{
	top[cocdi]++;
	thap[cocden][top[cocden]--]=0;
}

void luuthap (int luucocdi,int luucocden)
{
	int tam=thap[luucocdi][top[luucocdi]];
	thap[luucocden][++top[luucocden]]=tam;
	thap[luucocdi][top[luucocdi]--]=0;
}

void ThapHN ()
{
	int hmin,luucocdi,luucocden;
	int cocvuaden=-1;
	khoidong();
	do
	{
		hmin=2*MAX;
		for (int cocdi=0;cocdi<3;cocdi++)
			if (cocdi!=cocvuaden)
				for (int cocden=0;cocden<3;cocden++)
					if ((cocdi!=cocden)&&thap[cocdi][top[cocdi]]<thap[cocden][top[cocden]])
					{
						thap[cocden][++top[cocden]]=thap[cocdi][top[cocdi]--];
						int h=heuristic();
						if (h<hmin)
						{
							hmin=h;
						}
						hoantra(cocdi,cocden);
					}
		for (int cocdi=0;cocdi<3;cocdi++)
			if (cocdi!=cocvuaden)
				for (int cocden=0;cocden<3;cocden++)
					if ((cocdi!=cocden)&&thap[cocdi][top[cocdi]]<thap[cocden][top[cocden]])
					{
						thap[cocden][++top[cocden]]=thap[cocdi][top[cocdi]--];
						int h=heuristic();
						if (h==hmin)
						{
							luucocdi=cocdi;
							luucocden=cocden;
							cout<<"di chuyen tu coc "<<cocdi+1<<" sang coc "<<cocden+1<<endl;
							cout<<"h= "<<hmin<<endl;
						}
						hoantra(cocdi,cocden);
					}
		luuthap(luucocdi,luucocden);
		cocvuaden=luucocden;
	} 	while(hmin!=0);
}
int main()
{

	cout<<"Nhap so dia:";
	cin>>n;
	ThapHN();
}
