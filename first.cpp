#include <iostream>
#include <conio.h>
#include <ctime>

void guide();
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
void player1Move(char *spaces, char player1);
void player2Move(char *spaces, char player2);
bool checkWinnerFor2(char *spaces,char player1,char player2);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);


int main()
{
    bool flag = true;
    while (flag)
    {
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char player = 'X';
        char computer = 'O';
        char player1 = 'O';
        char player2 = 'X';
        bool running = true;
        std::cout << "\nWELCOME TO TIC TAC TOE GAME MADE BY AKHLAQ HUSAIN\n";
        int choice;
        std::cout << "\nOPTIONS\n\n1.Play With Computer\n2.2 Player game\n3.Guide\n4.Exit\n\n:-> ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            drawBoard(spaces);
            while (running)
            {
                playerMove(spaces, player);
                if (checkWinner(spaces, player, computer))
                {
                    drawBoard(spaces);
                    running = false;
                    break;
                }
                else if (checkTie(spaces))
                {
                    running = false;
                    break;
                }
                computerMove(spaces, computer);
                drawBoard(spaces);
                if (checkWinner(spaces, player, computer))
                {
                    running = false;
                    break;
                }
                else if (checkTie(spaces))
                {
                    running = false;
                    break;
                }
            }
            getch();
            break;
        case 2:
            drawBoard(spaces);
            while (running)
            {
                player1Move(spaces, player1);
                drawBoard(spaces);
                if (checkWinnerFor2(spaces, player1, player2))
                {
                    drawBoard(spaces);
                    running = false;
                    break;
                }
                else if (checkTie(spaces))
                {
                    running = false;
                    break;
                }
                player2Move(spaces, player2);
                drawBoard(spaces);
                if (checkWinnerFor2(spaces, player1, player2))
                {
                    running = false;
                    break;
                }
                else if (checkTie(spaces))
                {
                    running = false;
                    break;
                }
            }
            getch();
            break;
        case 3:
            guide();
            getch();
            break;
        case 4:
            flag = false;
            break;
        default:
            std::cout << "\nInvalid Choise Plzz Select Valid Choise";
            getch();
            break;
        }
    }

    std::cout << "\nThanks for playing!\n";
    getch();

    return 0;
}

void drawBoard(char *spaces)
{
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "\n";
    std::cout << "     |     |     \n";
    std::cout << "\n";
}
void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        std::cout << "Enter a spot to place a marker (1-9) : ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer)
{
    if ((spaces[0] == spaces[1]) && (spaces[1] == spaces[2]) && (spaces[0] != ' '))
    {
        spaces[0] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[3] == spaces[4]) && (spaces[4] == spaces[5]) && (spaces[3] != ' '))
    {
        spaces[3] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[6] == spaces[7]) && (spaces[7] == spaces[8]) && (spaces[6] != ' '))
    {
        spaces[6] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[0] == spaces[3]) && (spaces[3] == spaces[6]) && (spaces[0] != ' '))
    {
        spaces[0] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[4] == spaces[1]) && (spaces[1] == spaces[7]) && (spaces[1] != ' '))
    {
        spaces[4] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[2] == spaces[5]) && (spaces[5] == spaces[8]) && (spaces[2] != ' '))
    {
        spaces[2] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[0] == spaces[4]) && (spaces[4] == spaces[8]) && (spaces[0] != ' '))
    {
        spaces[0] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else if ((spaces[2] == spaces[4]) && (spaces[4] == spaces[6]) && (spaces[2] != ' '))
    {
        spaces[2] == player ? std::cout << "\nYOU WIN!\n" : std::cout << "\nYOU LOOSE!\n";
        return 1;
    }
    else
    {
        return false;
    }

    return true;
}
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}
void player1Move(char *spaces, char player1){
    int number;
    do
    {
        std::cout << "Player1 Enter a spot to place a marker (1-9) : ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player1;
            break;
        }
    } while (!number > 0 || !number < 8);
}
void player2Move(char *spaces, char player2){
    int number;
    do
    {
        std::cout << "Player2 Enter a spot to place a marker (1-9) : ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ')
        {
            spaces[number] = player2;
            break;
        }
    } while (!number > 0 || !number < 8);
}
void guide(){
    std::cout<<"\nSpot Location And Its Name\n";
    std::cout << "\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << 1 << "  |  " << 2 << "  |  " << 3 << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << 4 << "  |  " << 5 << "  |  " << 6 << "\n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << 7 << "  |  " << 8 << "  |  " << 9 << "\n";
    std::cout << "     |     |     \n";
    std::cout << "\n";
}
bool checkWinnerFor2(char *spaces,char player1,char player2){
    if ((spaces[0] == spaces[1]) && (spaces[1] == spaces[2]) && (spaces[0] != ' '))
    {
        spaces[0] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[3] == spaces[4]) && (spaces[4] == spaces[5]) && (spaces[3] != ' '))
    {
        spaces[3] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[6] == spaces[7]) && (spaces[7] == spaces[8]) && (spaces[6] != ' '))
    {
        spaces[6] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[0] == spaces[3]) && (spaces[3] == spaces[6]) && (spaces[0] != ' '))
    {
        spaces[0] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[4] == spaces[1]) && (spaces[1] == spaces[7]) && (spaces[1] != ' '))
    {
        spaces[4] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[2] == spaces[5]) && (spaces[5] == spaces[8]) && (spaces[2] != ' '))
    {
        spaces[2] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[0] == spaces[4]) && (spaces[4] == spaces[8]) && (spaces[0] != ' '))
    {
        spaces[0] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else if ((spaces[2] == spaces[4]) && (spaces[4] == spaces[6]) && (spaces[2] != ' '))
    {
        spaces[2] == player1 ? std::cout << "\nPLAYER1 WIN!\n" : std::cout << "\nPLAYER2 LOOSE!\n";
        return 1;
    }
    else
    {
        return false;
    }

    return true;
}