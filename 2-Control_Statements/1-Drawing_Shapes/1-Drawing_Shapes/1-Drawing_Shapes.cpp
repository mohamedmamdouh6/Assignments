#include <iostream>
using namespace std;

void main()
{
	int height;
	char symbol;
	cout << "Enter a character: ";
	cin >> symbol;
	cout << "Enter the height(odd/even) between 4 to 100: ";
	cin >> height;
	if (height > 100 || height < 4)
	{
		cout << "Invalid" << endl;
	}
	else
	{
		char again = 'y';
		while (again == 'y')
		{
			if (height % 2 == 0)
			{
				cout << "\n\tAvailable: " << endl;
				cout << "[0] Triangle" << endl;
				cout << "[1] Hollow Triangle" << endl;
				cout << "[2] Square " << endl;
				cout << "[3] Hollow Square" << endl;
				cout << "[4] Rectangle" << endl;
				cout << "[5] Hollow Rectangle" << endl;
			}
			else
			{
				cout << "\n\tAvailable: " << endl;
				cout << "[0] Triangle" << endl;
				cout << "[1] Hollow Triangle" << endl;
				cout << "[2] Square " << endl;
				cout << "[3] Hollow Square" << endl;
				cout << "[4] Rectangle" << endl;
				cout << "[5] Hollow Rectangle" << endl;
				cout << "[6] Rhombus" << endl;
				cout << "[7] Hollow Rhombus" << endl;
				cout << "[8] Hourglass" << endl;
				cout << "[9] Hellow Hourglass" << endl;
				cout << "[10]Butterfly" << endl;
				cout << "[11] Hellow Butterfly" << endl;

			}
			int shape;
			cout << "\nWhich one?: ";
			cin >> shape;
			switch (shape)
			{

			case 0:
			{
				cout << endl << "Triangle:\n" << endl;
				int space = height - 1;
				int stars = 1;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= space; j++)
					{
						cout << ' ';
					}
					for (int j = 1; j <= stars; j++)
					{
						cout << symbol;
					}
					cout << endl;
					space--;
					stars += 2;
				}
				break;
			}
			case 1:
			{
				cout << endl << "Hollow Triangle:\n" << endl;
				int spaces = height - 1;
				int stars = 1;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= spaces; j++)
					{
						cout << ' ';
					}
					for (int j = 1; j <= stars; j++)
					{
						if (i == 1 || i == height || j == 1 || j == stars)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
					spaces--;
					stars += 2;
				}
				break;
			}
			case 2:
			{
				cout << endl << "Square: \n" << endl;
				int stars = 1;
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < height * 2; j++)
						cout << symbol;
					cout << endl;
				}
				break;
			}
			case 3:
			{
				cout << endl << "Hollow Square:\n" << endl;
				int stars = 1;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= height * 2; j++)
					{
						if (i == 1 || i == height || j == 1 || j == height * 2)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
				}
				break;
			}
			case 4:
			{
				cout << endl << "Rectangle:\n" << endl;
				int stars = height * height;
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < stars; j++)
						cout << symbol;
					cout << endl;
				}
				break;
			}
			case 5:
			{
				cout << endl << "Hollow Rectangle:\n" << endl;
				int stars = height * height;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= stars; j++)
					{
						if (i == 1 || i == height || j == 1 || j == stars)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
				}
				break;
			}
			case 6:
			{
				cout << endl << "Rhombus:\n" << endl;
				int spaces = height / 2;
				int stars = 1;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= spaces; j++)
					{
						cout << ' ';
					}
					for (int j = 1; j <= stars; j++)
					{
						cout << symbol;
					}
					cout << endl;
					if (i <= height / 2)
					{
						spaces--;
						stars += 2;
					}
					else
					{
						stars -= 2;
						spaces++;
					}
				}
				break;
			}
			case 7:
			{
				cout << endl << "Hollow Rhombus:\n" << endl;
				int spaces = height / 2;
				int stars = 1;
				for (int i = 1; i <= height; i++)
				{
					for (int j = 1; j <= spaces; j++)
					{
						cout << ' ';
					}
					for (int j = 1; j <= stars; j++)
					{
						if (i == 1 || i == height || j == 1 || j == stars)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
					if (i <= height / 2)
					{
						spaces--;
						stars += 2;
					}
					else
					{
						spaces++;
						stars -= 2;
					}
				}
				break;
			}
			case 8:
			{
				cout << endl << "Hourglass:\n" << endl;
				if (height % 2 == 0)
				{
					cout << "Enter a odd number!!" << endl;
				}
				else
				{

					int spaces = 0;
					int stars = height;

					for (int i = 0; i < height; i++)
					{
						for (int j = 0; j < spaces; j++)
						{
							cout << ' ';
						}
						for (int j = 0; j < stars; j++)
						{
							cout << symbol;
						}
						cout << endl;
						if (i < height / 2)
						{
							stars -= 2;
							spaces++;
						}
						else
						{
							stars += 2;
							spaces--;
						}
					}
				}
				break;
			}
			case 9:
			{
				cout << endl << "Hellow Hourglass:\n" << endl;
				int spaces = 0;
				int stars = height;
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < spaces; j++)
					{
						cout << ' ';
					}
					for (int j = 0; j < stars; j++)
					{
						if (i == 0 || i == height - 1 || j == 0 || j == stars - 1)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
					if (i < height / 2)
					{
						stars -= 2;
						spaces++;
					}
					else
					{
						spaces--;
						stars += 2;
					}
				}
				break;
			}
			case 10:
			{
				int mid = height / 2;
				cout << "\n\t.*. Butterfly .*.\n" << endl;
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < height; j++)
					{
						if ((j <= i && i <= mid) || (j >= (height - 1) - i && i <= mid) || (j < height - i && i > mid) || (j >= i && i > mid))
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
				}
				break;
			}
			case 11:
			{
				cout << "\n\t.*. Hellow Butterfly .*.\n" << endl;
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < height; j++)
					{
						if (j == 0 || j == height - 1 || j == i || j == (height - 1) - i)
						{
							cout << symbol;
						}
						else
						{
							cout << ' ';
						}
					}
					cout << endl;
				}
				break;

			}
			default:
				cout << "Invalid shape" << endl;
			}
			cout << "Again?(y/n): ";
			cin >> again;
		}
	}
}