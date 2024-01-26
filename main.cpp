#include <iostream>
#include <fstream>

using namespace std;

char matrix[3][3] = { '1', '2', '3' , '4' , '5' , '6', '7' , '8' , '9' };
char player = 'X';

void display() {

    for (int i = 0; i < 3; i++) {
        cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t';
        for ( int j = 0; j < 3; j++) {

            if (j != 2)
                cout << matrix[i][j] << " | " ;
            else
                cout << matrix[i][j] ;
        }
        cout << endl;
    }
}

void play() {
    char choice;
    bool validChoice = true;

    while (validChoice) {
        cout << player << " turn: ";
        cin >> choice;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == choice) {
                    matrix[i][j] = player;
                    validChoice = false;
                    break;
                }
            }
        }

        if (validChoice) {
            cout << "InvaliD" << endl;
        }
    }

    if (player == 'X')
        player = 'O';
    else
        player = 'X';
}

char Winner() {
    int counter = 0;
    int x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        //sarti
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O') counter++;
            if (matrix[i][j] == 'X') x++;
            else if (matrix[i][j] == 'O') o++;
        }
        if (x == 3 || o == 3) {
            if (x > o)
                return 'X' ;
            else
                return 'O' ;
        }
        x = 0;
        o = 0;
    }
    for (int i = 0; i < 3; i++) {
        //sotoni
        for (int j = 0; j < 3; j++) {
            if (matrix[j][i] == 'X') x++;
            else if (matrix[j][i] == 'O') o++;
        }
        if (x == 3 || o == 3) {
            if (x > o)
                return 'X' ;
            else
                return 'O' ;
        }
        x = 0;
        o = 0;
    }
//zarbdari 1
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')return 'X';
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 'O';
//zarbdari 2
    if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')return 'X';
    else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') return 'O';

    if (counter == 0) return 'd';

    return 'r';
}

int main() {
    ofstream outputFile;
    bool playAgain = true;

    cout <<'\t'<<'\t'<<'\t' <<'\t'<< "Welcome To Korush,s XO Game | Press Enter To Start" <<endl<<endl;

    while (playAgain) {
        char matrix[3][3] = { '1', '2', '3' , '4' , '5' , '6', '7' , '8' , '9' };
        char player = 'X';

        while (Winner() == 'r') {
            display();
            play();
        }

        if (Winner() == 'd') {
            outputFile.open("game_results.txt", ios::app);
            outputFile << "Last game result: Draw";
            outputFile.close();
            cout << "draw"<< endl;
        } else {
            outputFile.open("game_results.txt", ios::app);
            outputFile << "Last game result: Player " << Winner() << " won" <<endl;
            outputFile.close();
            cout << "The winner is player: " << Winner() << endl;
        }

        char p;
        cout << "if you want to play again press y";
        cin >> p;
        playAgain = (p == 'y');
    }
}

