#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

/* Funkcije */
#include "utils/functions.h"


/* Klase */
#include "classes_users.h" 
User loggedUser;
User recievingUser;


#include "utils/user.h"
#include "utils/banker.h"

/* Forme */
#include "forms/login.h"
#include "forms/register.h"
#include "forms/transactions.h"


int main()
{
    srand(time(0));
    int opcija;

    cout << "\t \t \t \t \t \t \t \t ------------------------ \n";
    cout << "\t \t \t \t \t \t \t \t ***Mobilno bankarstvo*** \n";
    cout << "\t \t \t \t \t \t \t \t ------------------------ \n";

    do
    {
        cout<<endl;
        cout << "\t \t \t Izaberite opciju:";
        cout << "\t  1. Prijava";
        cout << "\t \t 2. Registracija  ";
        cout << "\t \t 3. Registracija bankara  ";
        cout << "\t \t 4. Izlaz \n ";
        cin >> opcija;

        switch (opcija)
        {
        case 1:
            prijava();
            break;
        case 2:
            kreiraj_korisnika();
            break;
        case 3:
            create_banker();
            break;
        default:
            cout << "Nevažeća opcija. Pokušajte ponovo." << endl;
        }

    } while (opcija != 4);

    return 0;
}