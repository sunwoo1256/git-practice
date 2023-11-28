#include <iostream>

using namespace std;

void print_array(char (*board)[3]){		// board[][3]도 가능
	cout << " " << board[0][0] << " |" << " " << board[0][1] << " |" << " " << board[0][2] << endl;
	cout << "---|---|---" << endl;
	cout << " " << board[1][0] << " |" << " " << board[1][1] << " |" << " " << board[1][2] << endl;
	cout << "---|---|---" << endl;
	cout << " " << board[2][0] << " |" << " " << board[2][1] << " |" << " " << board[2][2] << endl;

}

char input(char (*board)[3]){
	int x, y;
	char player;
	static int cnt = 0;
	cout << "선택할 곳의 x, y 좌표를 입력하세요\n";
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	//cout<<x<<y;
	if(cnt%2){
		player = 'X';
	}
	else{
		player = 'O';
	}
	board[x][y] = player;
	cnt++;
	
	return player;
}

bool win(char (*board)[3], char player){
	bool win = false;
	
	for(int i = 0; i < 3; i++){
		if(player == board[i][0] && board[i][0] == board[i][1] && board[i][2] == board[i][1]){
			cout << player << " win!" << endl;
			win = true;
		}
		if(player == board[0][i] && board[0][i] == board[1][i] && board[2][i] == board[1][i]){
			cout << player << " win!" << endl;
			win = true;
		}
	}
	
	if(player == board[0][0] && board[0][0] == board[1][1] && board[2][2] == board[1][1]){
		cout << player << " win!" << endl;
		win = true;
	}
	if(player == board[0][2] && board[0][2] == board[1][1] && board[2][0] == board[1][1]){
		cout << player << " win!" << endl;
		win = true;
	}
	
	return win;
}


int main(int argc, char* argv[]) {
	char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
	print_array(board);
	
	while(!win(board, input(board))){
		print_array(board);
	}
	print_array(board);
	
	
	return 0;
}