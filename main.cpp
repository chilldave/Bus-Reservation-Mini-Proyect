#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int matriz[5][14];
int matriz2[5][14];

void showSeats();
void bookSeats(int x);
void cancelSeats(int num);
void copyMatriz();
void fillMatriz();
int main()
{

    // Declarar variables
    fillMatriz();
    copyMatriz();
    while (true)
    {

        system("clear");
        cout << "\t\t\tBienvenido transportes Express S.A." << endl
             << endl;
        int choice;
        cout << "\t++ [1] Reservar asiento" << endl;
        cout << "\t-- [2] Cancelar reserva" << endl;
        cout << "\t-+ [3] Visualizacion de los asientos" << endl;
        cout << "\t?? [0] Salir del programa" << endl;
        cout << "\n\tIngrese el numero de la opcion que deasea realizar [0-3] : ";
        cin >> choice;
        // Eleccion

        switch (choice)
        {
        case 0:
            system("clear");
            cout << "\n\tHasta luego... \n";

            return 0;
        case 1:
            system("clear");
            int value;
            cout << "\n\tIngrese el numero de asientos que sea reservar : ";
            cin >> value;

            for (int i = 0; i < value; i++)
            {

                system("clear");
                int n;
                cout << "\n\t\tASIENTOS DISPONIBLES\n\n";
                showSeats();
                cout << "\n   Asientos restantes a asignar : " << value - i << endl;
                cout << "\n  Escriba el numero de asiento que desea reservar : ";
                cin >> n;
                bool continu = true;
                while (continu)
                {
                    if (0 < n && n <= 24)
                    {
                        continu = false;
                    }
                    else
                    {
                        cout << "El valor esta fuera del rango";
                        cout << "\n  Escriba el numero de asiento a reservar de nuevo :";
                        cin >> n;
                    }
                }
                bookSeats(n);
                cout << "  Asiento Reservado ... " << n << endl
                     << endl;
                cout << "\nPresione enter para continuar... ";

                cin.get();
                cin.get();
            }

            /* code */
            break;
        case 2:
            system("clear");
            int n;
            cout << "\nEstas para cancelar reserva" << endl;
            showSeats();
            cout << "\n  Ingresa el numero de asiento que sea cancelar : ";
            cin >> n;
            cancelSeats(n);
            cout << "\n  Presione enter para continuar... ";
            cin.get();
            cin.get();
            break;
        case 3:
            system("clear");
            cout << "\n\t       VISUALIZACION DE ASIENTOS" <<endl<< endl;
            showSeats();

            // copyMatriz();
            cout << " \n  Reserva Cancelada \n";
            cout << "\n    Presione enter para continuar... ";
            cin.get();
            cin.get();

            break;

        default:
            cout << "\nOpcion no encontrada" << endl;
            break;
        }

        // option = 1;
    }

    return 0;
}

void cancelSeats(int num)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 3; j < 14; j += 2)
        {
            if (num == matriz2[i][j])
            {

                matriz[i][j] = num;
            }
        }
    }
}
void copyMatriz()
{
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            matriz2[i][j] = matriz[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 3; j < 14; j += 2)
        {
            cout << " [" << i << "][" << j << "] " << matriz2[i][j] << endl;
        }
        cout << endl;
    }
}

void bookSeats(int x)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 3; j < 14; j += 2)
        {
            if (x == matriz[i][j])
            {
                matriz[i][j] = 0;
            }
        }
    }
}

void fillMatriz()
{

    matriz[0][3] = 2;
    matriz[1][3] = 1;
    matriz[0][5] = 6;
    matriz[1][5] = 5;
    matriz[0][7] = 10;
    matriz[1][7] = 9;
    matriz[0][9] = 14;
    matriz[1][9] = 13;
    matriz[0][11] = 18;
    matriz[1][11] = 17;
    matriz[0][13] = 22;
    matriz[1][13] = 21;

    // segundos

    matriz[3][3] = 3;
    matriz[4][3] = 4;
    matriz[3][5] = 7;
    matriz[4][5] = 8;
    matriz[3][7] = 11;
    matriz[4][7] = 12;
    matriz[3][9] = 15;
    matriz[4][9] = 16;
    matriz[3][11] = 19;
    matriz[4][11] = 20;
    matriz[3][13] = 23;
    matriz[4][13] = 24;
}
void showSeats()
{
    // cout << "Asi se ve el bus" << endl;

    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 14; j++)
        {
            if (((i == 1) && (j == 0)) || ((i == 1) && (j == 1)) || ((i == 4) && (j == 0)) || ((i == 4) && (j == 1)) ||
                (((i == 2) && (j == 3 || j == 5 || j == 7 || j == 9 || j == 11 || j == 13))))
            {
                cout << "\t  ";
            }
            else if ((j == 0) || (j == 1))
            {
                // if ((j == 0 && (i == 1 || i == 4)) || (j == 1 && i != 1) || (j > 1 && i != 1))

                cout << "\t--";
            }
            else if ((j % 2 == 0))
            {

                cout << "  ";
            }
            else if (i == 1 && j == 7)
            {
                cout << "+ " << matriz[i][j];
            }
            else
            {
                cout << "+" << matriz[i][j];
            }
        }
        cout << endl;
    }
}
