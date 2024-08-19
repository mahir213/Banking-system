#ifndef REGISTER_H
#define REGISTER_H

void kreiraj_korisnika()
{
    vector<User> users = User::GetAllUsers();
    string 
        email,
        password,
        jmbg,
        name,
        surname;
    

    cout << "Unesite Vaše ime " << endl;
    cin >> name; 
    cout << "Unesite Vaše prezime" << endl;
    cin >> surname;
    cout << "Unesite željeni email: " << endl;
    cin >> email;
    cout << "Unesite željenu sifru" << endl;
    cin >> password;
    Unos:
    cout << "Unesite Vaš JMBG" << endl;
    cin >> jmbg;
    if(jmbg.length() != 13){
    cout << "JMBG mora imati 13 karaktera" << endl;
    goto Unos;}

    IUser data;
    
    data.name = name;
    data.surname = surname;
    data.email = email;
    data.password = password;
    data.jmbg = jmbg;
   
    data.debitAccountCardNumber = kreirajRandomVisaCardKarticu();
    data.expirationDateDebitAccount = kreirajDatumIsteka();
    data.ccvDebitAccount = kreirajCCV();

    data.savingsAccountCardNumber = kreirajRandomMasterCardKarticu();
    data.expirationDateSavingsAccount = kreirajDatumIsteka();
    data.ccvSavingsAccount = kreirajCCV();

    cout << "Korisnik kreiran, CVV: "<< data.ccvDebitAccount <<endl;

    // ako User postoji u users vektoru izbaci gresku

    users.push_back(data);
    User::SaveUsers(users);
}

  
void create_banker()
{
    string lozinka="banka123";
    string unos;
    cout<<"Unesite pristupnu lozinku: ";
    cin>>unos;
    if(unos==lozinka){
    
    vector<Banker> bankers = Banker::GetAllBankers();
    string 
        email,
        password,
        jmbg,
        name,
        surname;
    
    cout << "Unesite Vase ime " << endl;
    cin >> name; 
    cout << "Unesite Vas prezime" << endl;
    cin >> surname;
    cout << "Unesite zeljeni email: " << endl;
    cin >> email;
    cout << "Unesite zeljenu sifru" << endl;
    cin >> password;
    Unos1:
    cout << "Unesite Vaš JMBG" << endl;
    cin >> jmbg;
    if(jmbg.length() != 13){
    cout << "JMBG mora imati 13 karaktera" << endl;
    goto Unos1;}
    

    IBanker data;
    
    data.name = name;
    data.surname = surname;
    data.email = email;
    data.password = password;
    data.jmbg = jmbg;

    bankers.push_back(data);
    Banker::SaveBankers(bankers);
    }
    else {
        cout<<"Netačna pristupna šifra!"<<endl;
        main();
    }
};
 
#endif