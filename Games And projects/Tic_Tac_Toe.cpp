#include <iostream>

using namespace std;

char ch[9] = { '1','2','3','4','5','6','7','8','9' };
int num;
char player1 = { 'X' };
char player2 = { 'O' };

void Draw();
void player_1();
void player_2();
bool X_Wins();
bool O_Wins();

int main(){

	do
	{
		Draw();
		player_1();
		Draw();

		if (X_Wins())
		{
			cout << "\t\t\t\tPlayer<1> Wins!" << endl;
			break;
		}

		player_2();
		Draw();

		if (O_Wins())
		{
			cout << "\t\t\t\tPlayer<2> Wins!" << endl;
            break;
		}
		cout << "\n\n\n";

	} while (true);

    return 0;
}

void Draw()
{
	system("clear");
	cout << "\t\t\t\tTic Toc Toe Game\n" << endl;
	cout << "\t\t\t\tplayer<1>: X\n";
	cout << "\t\t\t\tplayer<2>: O\n";
	cout << endl << endl;

	cout << "\t\t\t\t"<<ch[0] << "  |  " << ch[1] << "  |  " << ch[2] << "\n";
	cout << "\t\t\t\t-------------" << endl;

	cout << "\t\t\t\t"<<ch[3] << "  |  " << ch[4] << "  |  " << ch[5] << "\n";
	cout << "\t\t\t\t-------------" << endl;

	cout << "\t\t\t\t"<<ch[6] << "  |  " << ch[7] << "  |  " << ch[8] << "\n\n";
}

void player_1()
{

	cout << "\t\t\t\tPlayer<1> Enter number: ";
	cin >> num;

	switch (num)
	{

	case 1:
		ch[0] = player1;
		break;
	case 2:
		ch[1] = player1;
		break;
	case 3:
		ch[2] = player1;
		break;
	case 4:
		ch[3] = player1;
		break;
	case 5:
		ch[4] = player1;
		break;
	case 6:
		ch[5] = player1;
		break;
	case 7:
		ch[6] = player1;
		break;
	case 8:
		ch[7] = player1;
		break;
	case 9:
		ch[8] = player1;
		break;
	default:
		cout << "\t\t\t\t\nplease, enter number from <1> to <9>!\n\n" << endl;
		player_1();
		break;
	}

}

void player_2()
{

	cout << "\t\t\t\tPlayer<2> Enter number: ";
	cin >> num;

	switch (num)
	{

	case 1:
		ch[0] = player2;
		break;
	case 2:
		ch[1] = player2;
		break;
	case 3:
		ch[2] = player2;
		break;
	case 4:
		ch[3] = player2;
		break;
	case 5:
		ch[4] = player2;
		break;
	case 6:
		ch[5] = player2;
		break;
	case 7:
		ch[6] = player2;
		break;
	case 8:
		ch[7] = player2;
		break;
	case 9:
		ch[8] = player2;
		break;
	default:
		cout << "\t\t\t\t\nplease, enter number from <1> to <9>!\n\n" << endl;
		player_2();
		break;
	}

}

bool X_Wins()
{
	if (ch[0] == 'X' && ch[1] == 'X' && ch[2] == 'X') return true;
	else if (ch[3] == 'X' && ch[4] == 'X' && ch[5] == 'X') return true;
	else if (ch[6] == 'X' && ch[7] == 'X' && ch[8] == 'X') return true;

    else if (ch[0] == 'X' && ch[3] == 'X' && ch[6] == 'X') return true;
    else if (ch[1] == 'X' && ch[4] == 'X' && ch[7] == 'X') return true;
    else if (ch[2] == 'X' && ch[5] == 'X' && ch[8] == 'X') return true;

    else if (ch[0] == 'X' && ch[4] == 'X' && ch[8] == 'X') return true;
    else if (ch[2] == 'X' && ch[4] == 'X' && ch[6] == 'X') return true;

    else return false;
}

bool O_Wins()
{
	if (ch[0] == 'O' && ch[1] == 'O' && ch[2] == 'O')
		return true;
	else if (ch[3] == 'O' && ch[4] == 'O' && ch[5] == 'O')
		return true;
	else if (ch[6] == 'O' && ch[7] == 'O' && ch[8] == 'O')
		return true;
	else if (ch[0] == 'O' && ch[3] == 'O' && ch[6] == 'O')
		return true;
	else if (ch[1] == 'O' && ch[4] == 'O' && ch[7] == 'O')
		return true;
	else if (ch[2] == 'O' && ch[5] == 'O' && ch[8] == 'O')
		return true;
	else if (ch[0] == 'O' && ch[4] == 'O' && ch[8] == 'O')
		return true;
	else if (ch[2] == 'O' && ch[4] == 'O' && ch[6] == 'O')
		return true;
	else
		return false;
}