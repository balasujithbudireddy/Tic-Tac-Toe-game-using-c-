#include<iostream>
#include<conio.h>
using namespace std;

int turn=1;
char mark='o';
int input;
void matrix();
int addmark();
int check();
void printboard();
char board[3][3]={' ',' ',' '
				  ,' ',' ',' '	
				  ,' ',' ',' '};
void matrix(){
	cout<<endl<<endl<<"Input matrix"<<endl;
	cout<<" 1 | 2 | 3 "<<endl;
	cout<<"----------"<<endl;
	cout<<" 4 | 5 | 6" <<endl;
	cout<<"----------"<<endl;
	cout<<" 7 | 8 | 9 "<<endl;
	 
}

int addmark(){
	for(int i=0,k=1;i<3;i++){
		for(int j=0;j<3;j++,k++){
			if(k==input){
				if(board[i][j]==' '){
					board[i][j]=mark;
					return 1;
				}else{
					cout<<"invalid input";
					getch();
					return 0;
				}
			}
		}
	}
}
int check(){
	//checking rows
	if(board[0][0]==mark && board[0][1]==mark && board[0][2]==mark) return 1;
	if(board[1][0]==mark && board[1][1]==mark && board[1][2]==mark) return 1;
	if(board[2][0]==mark && board[2][1]==mark && board[2][2]==mark) return 1;
	//checking columns
	if(board[0][0]==mark && board[1][0]==mark && board[2][0]==mark) return 1;
	if(board[0][1]==mark && board[1][1]==mark && board[2][1]==mark) return 1;
	if(board[0][2]==mark && board[1][2]==mark && board[2][2]==mark) return 1;
	//checking diagonals
	if(board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) return 1;
	if(board[0][2]==mark && board[1][1]==mark && board[2][0]==mark) return 1;
	
	return 0;
}

void printboard(){
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<""<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<""<<endl;
	cout<<"------------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<""<<endl;
}
int main(){
	int won=0;
	int validinput=0;
	string player1;
	cout<<"player-1 enter your name:"<<endl;
	getline(cin,player1);
	string player2;
	cout<<"player-2 enter your name: "<<endl;
	getline(cin,player2);
	for(int i=0;i<9;i++){
		system("cls");
		printboard();
		if(turn) cout<<player1<<"'s turn (use symbol:o)"<<endl;
		else cout<<player2<<"'s turn (use symbol:x) "<<endl;
		matrix();
		cout<<"enter input from input matrix: "<<endl;
		cin>>input;
		while(input<0 || input>9){
			cout<<"invalid input.please try again:"<<endl;
			cin>>input;
		}
		if(turn) mark= 'o';
		else mark='x';
		validinput=addmark();
		if(!validinput){
			i--;
			continue;
		}
		won=check();
		if(won){
			system("cls");
			printboard();
			if(turn) cout<<endl<<"*** congatulations "<< player1<<"-You won *** ";
			else cout<<endl<<"*** congatulations "<< player2<<" -You won *** "; 
			getch();
			break;
		}
		if(i==8){
			system("cls");
			printboard();
			cout<<endl<<"*** Match drawn ***";
		}
		turn=!turn;
	}
}
