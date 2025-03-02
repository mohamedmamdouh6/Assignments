#include <iostream>
using namespace std;

void InitBoard(char array[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			array[i][j] = ' ';
		}
	}
}
void DrawBoard(char array[6][7])
{
	int index1 = 0;
	int index2 = -1;
	cout << "  0   1   2   3   4   5   6" << endl;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j < 7)
				{
					cout << "----";
				}
				else
				{
					cout << "-";
				}
			}
			else if (j < 7)
			{
				if (index2 == 6)
				{
					index1++;
					index2 = 0;
				}
				else
				{
					index2++;
				}
				cout << "| " << array[index1][index2] << ' ';
			}
			else
			{
				cout << '|';
			}
		}
		cout << endl;
	}
}
char CheckWin(char array[6][7])
{
	// Horizontal
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == array[i][j + 1] &&
				array[i][j + 1] == array[i][j + 2] &&
				array[i][j + 2] == array[i][j + 3] && array[i][j] != ' ')
			{
				return array[i][j];
			}
		}
	}

	// Vertical
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[i][j] == array[i + 1][j] &&
				array[i + 1][j] == array[i + 2][j] &&
				array[i + 2][j] == array[i + 3][j] && array[i][j] != ' ')
			{
				return array[i][j];
			}
		}
	}

	// Diagonal Left
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == array[i + 1][j + 1] &&
				array[i + 1][j + 1] == array[i + 2][j + 2] &&
				array[i + 2][j + 2] == array[i + 3][j + 3] && array[i][j] != ' ')
			{
				return array[i][j];
			}
		}
	}
	// Diagonal Right
	for (int i = 0; i < 3; i++)
	{
		for (int j = 3; j < 7; j++)
		{
			if (array[i][j] == array[i + 1][j - 1] &&
				array[i + 1][j - 1] == array[i + 2][j - 2] &&
				array[i + 2][j - 2] == array[i + 3][j - 3] && array[i][j] != ' ')
			{
				return array[i][j];
			}
		}
	}
	return ' ';

}
void main()
{
	char board[6][7];
	InitBoard(board);
	DrawBoard(board);
	int pos;
	char gameOver = ' ';
	int count = 0;
	bool isP1 = true;
	while (gameOver == ' ' && count < 42)
	{
		cout << "Which Block: ";
		cin >> pos;
		while (pos > 6 || pos < 0 || board[0][pos] != ' ')
		{
			cout << "Invalid Position!" << endl;
			cout << "Enter again: ";
			cin >> pos;
		}
		for (int i = 0; i < 6; i++)
		{
			if (board[i + 1][pos] != ' ' || i == 5)
			{
				if (board[i][pos] == ' ')
				{
					if (isP1)
					{
						board[i][pos] = '$';
						break;
					}
					else
					{
						board[i][pos] = '#';
						break;
					}
				}
			}
		}
		isP1 = !isP1;
		count++;
		DrawBoard(board);
		if (count >= 7)
		{
			gameOver = CheckWin(board);
		}
		if (gameOver == '#' || gameOver == '$')
		{
			break;
		}

	}

	if (gameOver == '#')
		cout << "# Won!" << endl;
	else if (gameOver == '$')
		cout << "$ Won!" << endl;
	else
		cout << "No One Won!" << endl;
}