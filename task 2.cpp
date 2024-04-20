#include<iostream>
using namespace std;


void addition(int x, int y)
{
	cout<<"sum = "<<x+y<<endl;
}
void subtraction(int x, int y)
{
	cout<<"difference = "<<x-y<<endl;
}
void multiplication(int x, int y)
{
	cout<<"product = "<<x*y<<endl;
}
void division(int x, int y)
{
		cout<<"quotient = "<<x/y<<endl;
	
	
}

int main()
{
	bool tryagain = true;
	while(tryagain)
	{
	cout<<"****** CALCULATOR ******"<<endl;
	cout<<"what do you want to perform?"<<endl;
	cout<<"1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION"<<endl;
	int op;
	cin>>op;
	cout<<"enter two integers"<<endl;
	int x, y;
	cin>>x>>y;
	
		if (op == 1)
	{
		addition(x,y);
	}
	else if(op == 2)
	{
		subtraction(x,y);
	}
	else if(op==3)
	{
		multiplication(x,y);	
	}
	else if(op==4)
	{
		division(x,y);
	}
	else {
		cout<<"try again"<<endl;
	}
	    cout << "do you want to try again? (1 for yes, 0 for no): ";
        cin>>tryagain;

	}
	cout<<"thank you for using calculator"<<endl;
	return 0;
	
}
