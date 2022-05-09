#include<iostream>
using namespace std;

/* NOTE:
		1. Make it cleaner
		2. Finising
		3. Finalize looping
		4. Add design.
		STATUS:DONE @Feb 27,2022
		BY: Quiros, Paul John C. 
		:For practice only (redo of Old activity in Programming 1)
		*/
void fillBoard(int, char *array);
void board(int, char *array);
void playerReg(char players[]);
void getWinner(int,char);
void boardGuide(int dimension);
bool checkWin(int,char, char *array);
bool getInput(int,int, char *array, char players[]);


int main(){
	char playerSymb[2]={};
	char cont = 'Y';
	
	while( cont == 'Y'){
		int sizeOf = 0;
		int round = 0;	
		system("CLS");
		
		while((sizeOf < 3) || (sizeOf > 8)){
			cout << "Enter Tic-Tac-Toe dimensions (3~8): ";
			cin >>sizeOf;	
			if((sizeOf < 3) || (sizeOf > 8)){
				cout << "Out of Range! Try another"<<endl;
			}
		}
		system("CLS");
		cout << "Initializing Multi-Dimensional Tic-Tac-Toe!" <<endl;
		
		char array[sizeOf][sizeOf];
		fillBoard(sizeOf,*array);
		board (sizeOf, *array);	
		playerReg(playerSymb);
		system("CLS");
		boardGuide(sizeOf);
		while( round < (sizeOf*sizeOf)){
			if((round%2)==0){
				cout << "\n" <<"Player " << playerSymb[round%2] <<endl;
				getInput((round%2),sizeOf,*array,playerSymb);
			}else{
				cout << "\n" << "Player " << playerSymb[round%2] <<endl;
				getInput((round%2),sizeOf,*array,playerSymb);
			}

			board(sizeOf,*array);
			if(checkWin(sizeOf, playerSymb[round%2], *array)==true){
				break;
			}
			round++;
		}
		if(checkWin(sizeOf, playerSymb[round%2], *array)==true){
			getWinner(round,playerSymb[round%2]);
		}
	
		cout << "Start a new game? Press [Y] to continue, any key to end" << endl;
		cin >> cont;
		if( cont == 'y'){
			cont = 'Y';
		}
	}

	return 0;
}

void fillBoard(int dimension, char *array){

	for(int ctr=0;ctr<dimension*dimension;ctr++){
		int (array[ctr] =' ');
	}
	
}

void board(int dimension, char *array ){
	
	for(int ctr1=0;ctr1<dimension;ctr1++){
		if (ctr1==0){
			cout << char(201) << char(205);
			for(int ctr2=1;ctr2<dimension;ctr2++){
				cout << char(205) <<char(205) << char(203) << char(205);
			}
			cout << char(205) << char(205) << char(187);
		}
		cout <<"\n" << char(186);
		for(int ctr3=0;ctr3<dimension;ctr3++){
			cout << " " << array[(ctr1*dimension)+ctr3] << " " << char(186);
		}
		if(!(ctr1==(dimension-1))){
			cout << "\n" << char(204);
			for(int ctr4=0;ctr4<dimension;ctr4++){
				cout << char(205) << char(205) << char(205);
				if(ctr4==(dimension-1)){
					cout << char(185);
				}else{
					cout << char(206);
				}
			}			
		}else{
			cout << "\n" << char(200);
			for(int ctr5=0;ctr5<dimension;ctr5++){
				cout << char(205) << char(205) << char(205);
				if (ctr5==(dimension-1)){
					cout << char(188);
				}else{
					cout << char(202);
				}
			}
			
		}

	}
}

void playerReg(char players[]){
	
	for(int ctr=0; ctr<2;ctr++){
		bool checkValid = false;
		if(ctr==0){
				cout << "\n" << "Enter First player's symbol (Alphanumeric) : ";
		}else if(ctr==1){
				cout << "\n" << "Enter Second player's symbol (Alphanumeric) : ";
		}
		while ( checkValid == false){
			cin >> players[ctr];
			if((players[ctr]>64 && players[ctr]<91)||((players[ctr]>97 && players[ctr]<123)) && players[ctr-1]!=players[ctr]){
				cout << "Input is valid!"  << "Player '"<< players[ctr] << "' Registered!\n";
				break;
			}else{
				cout << "\n" << "Invalid input! Try (A~Z): ";
			}
		}
	}
}

void getWinner(int round, char symb){
	cout << "\n" <<"Player " << symb << " won at Round " << round << "!" << endl;
	cout <<  char(205) <<  char(205) <<  char(205) << "CONGRATS"  << char(205) <<  char(205) <<  char(205)  << endl;
}

void boardGuide(int dimension){
	cout << char(205) << char(205) << char(205) << "Board GUIDE" << char(205) << char(205) << char(205) << endl;
	for(int ctr1=0;ctr1<dimension;ctr1++){
		if (ctr1==0){
			cout << char(201) << char(205);
			for(int ctr2=1;ctr2<dimension;ctr2++){
				cout << char(205) <<char(205) << char(203) << char(205);
			}
			cout << char(205) << char(205) << char(187);
		}
		cout <<"\n" << char(186);
		for(int ctr3=0;ctr3<dimension;ctr3++){
			cout << " " << (ctr1*dimension)+(ctr3+1) << " " << char(186);
		}
		if(!(ctr1==(dimension-1))){
			cout << "\n" << char(204);
			for(int ctr4=0;ctr4<dimension;ctr4++){
				cout << char(205) << char(205) << char(205);
				if(ctr4==(dimension-1)){
					cout << char(185);
				}else{
					cout << char(206);
				}
			}			
		}else{
			cout << "\n" << char(200);
			for(int ctr5=0;ctr5<dimension;ctr5++){
				cout << char(205) << char(205) << char(205);
				if (ctr5==(dimension-1)){
					cout << char(188);
				}else{
					cout << char(202);
				}
			}
			
		}

	}	
	cout << endl;
}

bool checkWin(int dimension, char symb, char *array){
	
	int ctr1=0;
	int matchCounter=0;
	while(ctr1<dimension){ //HORINZONTAL CHECKING
		int ctr2=0;
		while(ctr2<dimension){
			if(array[(ctr1*dimension)+ctr2]==symb){
				matchCounter += 1;
			}if(matchCounter == dimension){
				cout << "rorh";
				return true;
			}
			ctr2++;		
		}
	
		matchCounter=0;
		ctr1++;
	}
	
	ctr1=0;
	matchCounter=0;
	
	while(ctr1<dimension){//CHECKING VERTICALLY
		int ctr2=0;
		while(ctr2<dimension){
			if(array[(ctr2*dimension)+ctr1]==symb){
				matchCounter += 1;
			}if(matchCounter == dimension){
				cout << "rorv";
				return true;
			}
			ctr2++;
		}
		matchCounter=0;
		ctr1++;
	}
	
	ctr1=0;
	matchCounter=0;
	
	while(ctr1<dimension){//DIAGONAL CHECK, start left
		if(array[0]== ' '){
			return false;
		}
		if(array[(ctr1*dimension)+ctr1]==symb){
			matchCounter += 1;
		}if(matchCounter == dimension){
			cout << "rord";
			return true;
		}
		ctr1++;
	}
	
	ctr1=0;
	matchCounter=0;
	
	while(ctr1<dimension){//DIAGONAL CHECK, start right
		if(array[(dimension-1)]==' '){
			return false;
		}
		if(array[(dimension-1)*(ctr1+1)]==symb){
			matchCounter += 1;
		}if(matchCounter == dimension){
			return true;
		}
		ctr1++;
	}
	return false;
}

bool getInput(int player,int dimension, char*array, char players[]){
	
	bool valid = false;
	int input;
	
	cout << "Input cell number [1 ~ " << dimension*dimension << "]: " << endl;
	while (valid==false){
		cin >> input;
		if((array[input-1] == players[0]) || array[input-1]== players[1]){
			cout<<"Cells is already taken! Choose Another: ";
			valid = false;
		}else{
			if((input < 0)||(input>dimension*dimension)){
				cout<<"Chosen cell is out of range! Choose Another!: ";
				valid=false;
			}else if(input == 0){
				cout<<"Chosen cell is out of range! Choose Another!: ";
				valid=false;
			}else{
				array[input-1]=players[player];
				valid=true;
			}
		}
	}
}



