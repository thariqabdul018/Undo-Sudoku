#include<iostream>
#include"sudoku.h"
using namespace std;

int main(int argc, char* argv[]){
	int row, column, number;
	string filename;
	vector<vector<int>>theBoard(BoardSize, vector<int>(BoardSize));
	vector<vector<int>>originalBoard(BoardSize,vector<int>(BoardSIze));
	
	switch(){
		case 1:
			cout<<"Pastikan berikan parameter pada program\n";
			exit(1);
		case 2:
			filename = argv[1];
			break;
		default:
			cout<<"Pastikan berikan parameter pada program\n";
			exit(1);
	}
	createBoard(theBoard);
	populateBoardFromFile(theBoard, filename);
	createBoard(originalBoard);
	populateBoardFromFile(originalBoard,filename);
	
	cout<<"Selamat bermain sudoku\n";
	
	string userChoice = "";
	do{
		cout<<"Masukkan Pilihanmu (print, write, erase, quit): ";
		cin>> userChoice;
		if(userChoice == "print"){
			printBoard(theBoard);
			continue;
		}
		if(userChoice == "write"){
			cout<<"Input Row: ";
			cin>>row;
			cout<<"Input Column: ";
			cin>>column;
			cout<<"Input Number: ";
			cin>>number;
			
			if(fixedValues(theBoard, row, column)==false && CheckRow(theBoard, row, number) == false){
				theBoard[(row-1)][(column-1)]=number;
				printBoard(theBoard);
			}else{
				cout<<"\n";
			}
			continue;
		}
		if(userChoice=="erase"){
			cout<<"Input Row: ";
			cin>>row;
			cout<<"Input Column: ";
			cin>>column;
			
			if(erase(originalBoard, row, column) == false){
				theBoard[(row-1)][(column-1)]=Empty;
				printBoard(theBoard);
			}else{
				cout<<"Error: Mencoba menghapus angka\n";
			}
			continue;
		}
	}
}
