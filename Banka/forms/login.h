#include <iostream>
#include <vector>

#ifndef LOGIN_H
#define LOGIN_H
int main();
void make_transaction();
void podigni_kredit();
void otplati_kredit();

void user_menu()
{
    int opcija3;
    do
    {
        cout<<endl;
        cout << "\t \t \t \t \t \t \t \t------------------------ \n";
        cout << "\t \t \t \t \t \t \t \t ****Korisnički Meni**** \n";
        cout << "\t \t \t \t \t \t \t \t------------------------ \n";

        cout << "\t \t \t \t Izaberite opciju: ";
        cout << "\t \t 1. Podaci računa";
        cout << "\t \t 2. Izvrši transakciju\n \n ";
        cout << "\t \t \t \t \t \t \t \t 3. Podigni kredit";
        cout << "\t \t 4. Otplati kredit";
        cout << "\t \t 5. Odjava \n ";
        cin >> opcija3;
        switch (opcija3)
        {
        case 1:
            account_info(loggedUser);
            break;
        case 2:
            make_transaction();
            break;
        case 3:
            podigni_kredit();
            break;
        case 4:
           otplati_kredit();
           break;
        case 5:
            main();
            break;

        default:
            break;
        }
    } while (opcija3 != 5);
};

void prijava()
{
    vector<User> users = User::GetAllUsers();
    vector<Banker> bankers = Banker::GetAllBankers();

    string email, password;
    cout<<endl;
    cout << "Unesite vaš email: " << endl;
    cin >> email;
    cout << "Unesite vašu šifru" << endl;
    cin >> password;
    bool user_found, banker_found = false;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].GetEmail() == email && users[i].GetPassword() == password)
        {
            loggedUser = users[i];
            user_menu();
            user_found = true;
            break;
        }
    }
    if (!user_found)
    {
        for (int i = 0; i < bankers.size(); i++)
        {
            if (bankers[i].GetEmail() == email && bankers[i].GetPassword() == password)
            {
                banker_menu();
                banker_found = true;
                break;
            }
        }
    }

    if (!user_found && !banker_found)
    {
        cout << "ERROR: Ne postoji takav račun u bazi podataka!" << endl;
        return;
    }
}

#endif