#include <iostream>
using namespace std;

void DrawBoard(char array[3][3])
{
    cout << endl;
    int index1 = 0;
    int index2 = -1;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!(i % 2))
            {
                cout << "---";
            }
            else if (j < 3)
            {

                if (index2 == 2)
                {
                    index1++;
                    index2 = 0;
                }
                else
                {
                    index2++;
                }
                cout << "| " << array[index1][index2] << " ";
            }
            else
            {
                cout << "|";
            }
        }
        cout << endl;
    }
}
char CheckWin(char array[3][3])
{
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2] && array[0][0] != ' ')
    {
        return array[0][0];
    }
    if (array[0][2] == array[1][1] && array[1][1] == array[2][0] && array[0][2] != ' ')
    {
        return array[0][2];
    }
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == array[i][1] && array[i][1] == array[i][2] && array[i][0] != ' ')
        {
            return array[i][0];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (array[0][i] == array[1][i] && array[1][i] == array[2][i] && array[0][i] != ' ')
        {
            return array[0][i];
        }
    }
    return ' ';
}
void main()
{
    char array[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = ' ';
        }
    }
    DrawBoard(array);
    bool isX = true;
    int count = 0;
    char gameOver = ' ';
    do
    {
        cout << "Which Block: ";
        int x, y;
        cin >> x >> y;
        while (array[x][y] != ' ')
        {
            cout << "Filled Bloack!" << endl;
            cin >> x >> y;
        }
        if (isX)
        {
            array[x][y] = 'X';
        }
        else
        {
            array[x][y] = 'O';
        }
        count++;
        DrawBoard(array);
        gameOver = CheckWin(array);
        if (gameOver == ' ' && count == 9)
        {
            cout << "Game Over! No One Won!" << endl;
            break;
        }
        isX = !isX;
    } while (gameOver == ' ');

    if (gameOver == 'X')
        cout << "X Won!" << endl;
    else if (gameOver == 'O')
        cout << "O Won!" << endl;

}