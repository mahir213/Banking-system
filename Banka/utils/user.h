#ifndef USER_UTILS_H
#define USER_UTILS_H

void account_info(User user)
{ 
    cout << "---------------------------------------------- \n";
    cout << "Informacije o Debitnoj Kartici:" << endl;
    cout << "  Broj Kartice: " << user.TekuciRacun.Racun.Kartica.GetCardNumber() << endl;
    cout << "  Datum Isteka: " << user.TekuciRacun.Racun.Kartica.GetExpirationDate() << endl;
    cout << "  CCV: " << user.TekuciRacun.Racun.Kartica.GetCCV() << endl;
    cout << "  Stanje na Računu: " << user.TekuciRacun.Racun.GetAccountBalance() << endl;

    cout << "Informacije o Štednom Računu:" << endl;
    cout << "  Broj Kartice: " << user.StedniRacun.Racun.Kartica.GetCardNumber() << endl;
    cout << "  Datum Isteka: " << user.StedniRacun.Racun.Kartica.GetExpirationDate() << endl;
    cout << "  CCV: " << user.StedniRacun.Racun.Kartica.GetCCV() << endl;
    cout << "  Stanje na Računu: " << user.StedniRacun.Racun.GetAccountBalance() << endl;
    cout << "  Kamatna Stopa: " << user.StedniRacun.GetInterestRate() << endl; 
    cout << "------------------------------------------------\n";
};

#endif