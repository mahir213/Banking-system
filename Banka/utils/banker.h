#ifndef BANKER_UTILS_H
#define BANKER_UTILS_H

void banker_menu();
void prijava();
int main();

void edit_user()
{

    vector<User> users = User::GetAllUsers();
    int id;
    int i;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        cout << "\nID: " << i << endl;
        cout << "Ime i prezime: " << users[i].GetFullName() << endl;
        cout << "Email:  " << users[i].GetEmail() << " "
             << "Password: "
             << " " << users[i].GetPassword() << endl;
        cout << "JMBG: " << users[i].GetJMBG() << endl;
        cout << "\n";
        cout << "Broj tekuceg racuna: " << users[i].TekuciRacun.Racun.Kartica.GetCardNumber() << endl;
        cout << "Stanje tekuceg racuna: " << users[i].TekuciRacun.Racun.GetAccountBalance() << endl;
        cout << "\n";
        cout << "Broj stednog racuna: " << users[i].StedniRacun.Racun.Kartica.GetCardNumber() << endl;
        cout << "Stanje stednog racuna: " << users[i].StedniRacun.Racun.GetAccountBalance() << endl;
        cout << "-------------------------------------------------------------" << endl;
    };

    do{
    cout << "Unesite ID korisnika kojeg želite urediti" << endl;
    cin >> id;}
    while(id >= users.size());

    int editOption;
    cout << "1. Ime\n 2. Prezime\n 3. JMBG\n 4. Broj tekuceg racuna\n 5. Stanje tekuceg racuna\n 6. Broj stednog racuna\n 7. Stanje stednog racuna\n 8. Nazad\n";

    cout << "Unesite broj podatka koji zelite promijeniti" << endl;
    cin >> editOption;

    switch (editOption)
    {
    case 1:
    {
        string NewName;
        cout << "Unesite novo ime (trenutno ime: " << users[id].GetName() << "): " << endl;

        cin >> NewName;
        users[id].SetName(NewName);
        cout << "Uspjesna izmjena imena korisnika." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 2:
    {
        cout << "Unesite novo prezime (trenutno prezime: " << users[id].GetSurname() << ")" << endl;
        string NewSurname;
        cin >> NewSurname;
        users[id].SetSurname(NewSurname);
        cout << "Uspjesna izmjena prezimena korisnika." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 3:
    {
        cout << "Umesite novi JMBG (trenutni JMBG: " << users[id].GetJMBG() << ")" << endl;
        string NewJMBG;
        cin >> NewJMBG;
        users[id].SetJMBG(NewJMBG);
        cout << "Uspjesna izmjena  jedinstvenog maticnog broja korisnika." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }
    case 4:
    {
        cout << "Unesite novi broj tekuceg racuna (trenutni broj: " << users[id].TekuciRacun.Racun.GetAccountNumber() << ")" << endl;
        string NewDebitAccNumber;
        cin >> NewDebitAccNumber;
        users[id].TekuciRacun.Racun.Kartica.SetCardNumber(NewDebitAccNumber);
        cout << "Uspjesna izmjena broja tekuceg racuna." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 5:
    {
        cout << "Unesite novo stanje racuna (trenutno stanje: " << users[id].TekuciRacun.Racun.GetAccountBalance() << ")" << endl;
        double NewBalance;
        cin >> NewBalance;
        users[id].TekuciRacun.Racun.SetBalance(NewBalance);
        cout << "Uspjesna izmjena stanja tekuceg racuna." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 6:
    {

        cout << "Unesite novi broj stednog racuna (trenutni broj: " << users[id].StedniRacun.Racun.GetAccountNumber() << ")" << endl;
        string NewSavingsAccNumber;
        cin >> NewSavingsAccNumber;
        users[id].StedniRacun.Racun.Kartica.SetCardNumber(NewSavingsAccNumber);
        cout << "Uspjesna izmjena broja stednog racuna." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 7:
    {

        cout << "Unesite novo stanje stednog racuna (trenutno stanje: " << users[id].StedniRacun.Racun.GetAccountBalance() << ")" << endl;
        double NewBalance;
        cin >> NewBalance;
        users[id].StedniRacun.Racun.SetBalance(NewBalance);
        cout << "Uspjesna izmjena stanja stednog racuna." << endl;
        User::SaveUsers(users);
        banker_menu();
        break;
    }

    case 8:
    {
        banker_menu();
    }

    default:
        cout << "ERROR: Unijeli ste pogresnu opciju!" << endl;
    }

    User::SaveUsers(users);
};

void delete_user()
{
    vector<User> users = User::GetAllUsers();
    int id;
    int i;
    cout << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < users.size(); i++)
    {

        cout << "\nID: " << i << endl;
        cout << "Ime i prezime: " << users[i].GetFullName() << endl;
        cout << "Email:  " << users[i].GetEmail() << " "
             << "Password: "
             << " " << users[i].GetPassword() << endl;
        cout << "JMBG: " << users[i].GetJMBG() << endl;
        cout << "\n";
        cout << "Broj tekuceg racuna: " << users[i].TekuciRacun.Racun.Kartica.GetCardNumber() << endl;
        cout << "Stanje tekuceg racuna: " << users[i].TekuciRacun.Racun.GetAccountBalance() << endl;
        cout << "\n";
        cout << "Broj stednog racuna: " << users[i].StedniRacun.Racun.Kartica.GetCardNumber() << endl;
        cout << "Stanje stednog racuna: " << users[i].StedniRacun.Racun.GetAccountBalance() << endl;
        cout << "-------------------------------------------------------------" << endl;
    }

    do{
    cout << "Unesite ID korisnika kojeg želite ukloniti: " << endl;
    cin >> id;}
    while(id >= users.size());

    if (id >= 0 && id < users.size())
    {

        users.erase(users.begin() + id);
        cout << "Korisnik je uspješno obrisan." << endl;
        User::SaveUsers(users);
    }
    else
    {
        cout << "Neispravan ID korisnika. Korisnik nije obrisan." << endl;
    }
};

void banker_menu()
{
    int opcija2;
    do
    {

        cout << "\t \t \t \t \t \t \t \t------------------------ \n";
        cout << "\t \t \t \t \t \t \t \t ****Menu zaposlenih**** \n";
        cout << "\t \t \t \t \t \t \t \t------------------------ \n";

        cout << "\t \t  Izaberite opciju: ";
        cout << "\t 1. Uredi korisnike";
        cout << "\t 2. Ukloni korisnika  ";
        cout << "\t 3. Odjava.\n";
        cin >> opcija2;

        switch (opcija2)
        {
        case 1:
            edit_user();
            break;
        case 2:
            delete_user();
            break;
        case 3:
            main();

        default:
            cout << "Nevažeća opcija. Pokušajte ponovo." << endl;
        }
    } while (opcija2 != 1 && opcija2 != 2);
};

#endif