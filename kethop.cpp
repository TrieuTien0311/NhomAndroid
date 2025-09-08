#include<iostream>
#include<cstring>
#include <sstream>
using namespace std;
void hvi(int &a, int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}
int main()
{
	int i,n,j,k,x,y,max;
	string s="";
	cin>>n;
	int a[n+1];
	int b[n+1];
	for (i=1;i<=n;i++)
		cin>>a[i];
	cout<<endl;
	for (i=1;i<=n-1;i++)
		for (j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
				hvi(a[i],a[j]);
		}
	j=1;
	while (i!=0)
	{
		
		s="";
		for (i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
			s=s+ to_string(a[i]);
		}
		b[j]=stoll(s);
		j++;
		cout<<endl;
		i=n-1;
		while (i>0 && a[i]>a[i+1])
			i--;
		if (i>0)
		{
			k=n;
			while (a[k]<a[i])
				k--;
			hvi(a[k],a[i]);
			x=i+1;
			y=n;
			while(x<y)
			{
				hvi(a[x],a[y]);
				x++;
				y--;
			}
		}
		
	}
	max=b[1];
	for (i=2;i<=j-1;i++)
		if (b[i]>=max)
			max=b[i];
	cout<<max;
	return 0;	
}
