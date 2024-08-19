#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

void make_transaction()
{
    vector<User> users = User::GetAllUsers();

    string receivingAccountNumber;
    double moneyToSend;

    cout << "Unesite broj računa na koji šaljete novac" << endl;
    cout << "Unesite '-1' da se vratite nazad u meni" << endl;
    cin >> receivingAccountNumber;

    if(receivingAccountNumber == "-1")
    {
        return;
    }

    cout << "Unesite iznos novca koji šaljete" << endl;
    cin >> moneyToSend;

    bool found_receiver = false;
    int sender;
    for (int i = 0; i < users.size(); i++)
    { 
        if (users[i].GetJMBG() == loggedUser.GetJMBG())
        {
            sender = i; 
        }
        if (users[i].TekuciRacun.Racun.Kartica.GetCardNumber() == receivingAccountNumber)
        {
            found_receiver = true;
            if (loggedUser.TekuciRacun.Racun.GetAccountBalance() < moneyToSend)
            {
                cout << "Nemate dovoljno sredstava!" << endl;
                return;
            }
 
            if (sender)
            { 
                users[sender].Send(moneyToSend);
            }
            
            users[i].recieve(moneyToSend);
            cout << "Uspješno ste poslali " << moneyToSend << " KM korisniku " << users[i].GetFullName();
            return;
        }
    }

    if (!found_receiver)
    {
        cout << "ERROR: Korisnik sa unesenim brojem računa nije pronađen" << endl;
        return;
    }

    User::SaveUsers(users);
}

void podigni_kredit()
{
    vector<User> users = User::GetAllUsers();

    double iznos_kredita;

    cout << "Unesite iznos kredita koji želite podići: " << endl;
    cin >> iznos_kredita;

    int indeks_korisnika = -1;

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].GetJMBG() == loggedUser.GetJMBG())
        {
            indeks_korisnika = i;
            break;
        }
    }

    if (indeks_korisnika != -1)
    {

        double novi_balans = users[indeks_korisnika].TekuciRacun.Racun.GetAccountBalance() + iznos_kredita;
        users[indeks_korisnika].TekuciRacun.Racun.SetBalance(novi_balans);
        users[indeks_korisnika].setIznosKredita(iznos_kredita);
        cout<<"Ukupan iznos duga: "<<users[indeks_korisnika].getIznosKredita()<<endl;
        cout << "Uspješno ste podigli kredit od " << iznos_kredita << " KM." << endl;
        cout << "Novi balans na računu: " << novi_balans << " KM." << endl;
    }
    else
    {
        cout << "Greška: Korisnik nije pronađen." << endl;
    }

    User::SaveUsers(users);
}

void otplati_kredit() {
    vector<User> users = User::GetAllUsers();
    double iznos_otplate;
cout << "Unesite iznos kredita koji želite otplatiti: ";
cin >> iznos_otplate;
    
    int indeks_korisnika = -1;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].GetJMBG() == loggedUser.GetJMBG()) {
            indeks_korisnika = i;
            break;
        }
    }

    if (indeks_korisnika != -1) {
        double iznos_kredita = users[indeks_korisnika].getIznosKredita();
        cout << iznos_kredita <<endl;

        if (iznos_otplate <= iznos_kredita) {
          
            double trenutni_balans = users[indeks_korisnika].TekuciRacun.Racun.GetAccountBalance();
            users[indeks_korisnika].TekuciRacun.Racun.SetBalance(trenutni_balans - iznos_otplate);
            users[indeks_korisnika].setIznosKredita(-iznos_otplate);
            cout<<"Preostali iznos kredita: "<<users[indeks_korisnika].getIznosKredita()<< "KM."<<endl;
            cout << "Uspješno ste otplatili " << iznos_otplate << " KM kredita." << endl;
            cout << "Novi balans na računu: " << users[indeks_korisnika].TekuciRacun.Racun.GetAccountBalance() << " KM." << endl;
        } else {
            cout << "Greška: Nemate dovoljno kredita za otplatu." << endl;
        }
    } else {
        cout << "Greška: Korisnik nije pronađen." << endl;
    }

    
    User::SaveUsers(users);
}



#endif