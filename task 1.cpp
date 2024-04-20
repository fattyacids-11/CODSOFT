#include<iostream>
#include<cstdlib>
#include<time.h>
 using namespace std;
 
void checker(int rand_no)
 {
 	int guess;
 	do{
 		cout<<"*****guess a number between 0-10******"<<endl;
 		cin>>guess;
 		if(guess > rand_no)
 		{
 			cout<<"\ntoo high, something smaller\n"<<endl<<"\n********try again******\n"<<endl;
		 }
		else if(guess < rand_no)
 		{
 			cout<<"\ntoo low, something higher\n"<<endl<<"\n********try again**********\n"<<endl;
		}
		else if(guess == rand_no)
 		{
 			cout<<"\n\n******your answer is correct*******\n\n"<<endl;
		}
	 }while(guess != rand_no);
 }
 
int random_generator()
 {
 	srand(time(NULL)); 	
 	int rand_no = 1 + (rand()%10);
 	return rand_no;
 }
 
 bool playagain(){
 	cout<<"do you want to play agian??"<<endl;
 	cout<<"1. yes\n2. no"<<endl;
 	int op;
 	cin>>op;
 	return op ==1;
 }
 
int main()
{

	bool play = true;
	while(play){
		int rand_no = random_generator();
		checker(rand_no);
		play = playagain();
	}
	cout<<"thank you for playing"<<endl;
 }
