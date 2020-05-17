#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	srand(unsigned(time(0)));
	int diceSides=0;
	cout<<"Rules:"<<endl;
	cout<<"If you roll even,you roll one more die.Othervise stop"<<endl;
	cout<<"Goal is to roll exactly 3 dice"<<endl;
	cout<<endl<<"Enter number of sides for dice:";
	cin>>diceSides;
	double *prob=new double[diceSides];
	int i=0;
	while (i<diceSides)
	{
		cout<<endl<<"Enter probability for side "<<(i+1)<<" :";
		cin>>prob[i];
		i++;
	}
	int r=0;
	cout<<endl<<"Your dice are:"<<endl;
	while (r<3)
	{
		double alpha=rand()*1.0/RAND_MAX;
		i=1;
		while ((i<diceSides)and((alpha-prob[i-1])>0))
		{
			alpha-=prob[i-1];
			i++;
		}
		cout<<i;
		if (r!=2)
		   cout<<",";
		if (((i%2==1)and(r<2))or((i%2==0)and(r==2)))
		{
			cout<<endl<<"You lose!";
			r=10;
		}
		r++;
	}
	if (r==3)
	{
		cout<<endl<<"Congratulations!You won!";
	}
}
