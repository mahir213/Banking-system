#ifndef CLASSES_H
#define CLASSES_H

struct IBanker
{
    string name;
    string surname;
    string email;
    string jmbg;
    string password;
};

struct IUser
{
    string name;
    string surname;
    string email;
    string jmbg;
    string password;

    string savingsAccountCardNumber;
    string debitAccountCardNumber;
    string expirationDateSavingsAccount;
    string expirationDateDebitAccount;

    string ccvSavingsAccount;
    string ccvDebitAccount;
};




class Kartica
{
    string BrojKartice;
    string DatumIsteka;
    string CCV;
    // getter za datum isteka

public:
    Kartica()
    {
    }

    void SetCardNumber(string brojKartice)
    {
        this->BrojKartice = brojKartice;
    }

    void SetExpirationDate(string datumIsteka)
    {
        this->DatumIsteka = datumIsteka;
    }

    void SetCCV(string ccv)
    {
        this->CCV = ccv;
    }

    string GetCardNumber() const
    {
        return this->BrojKartice;
    }

    string GetExpirationDate() const
    {
        return this->DatumIsteka;
    }

    string GetCCV() const
    {
        return this->CCV;
    }
};



class Racun
{
    string BrojRacuna;
    double BalansRacuna;


public:
    Kartica Kartica;

    Racun()
    {
        this->SetBalance(0);
    }

    string GetAccountNumber()
    {
        return this->BrojRacuna;
    }


    double GetAccountBalance() const
    {
        return this->BalansRacuna;
    }

    void SetBalance(double noviBalans)
    {
        this->BalansRacuna = noviBalans;
    }

};




class StedniRacun
{
    double KamatnaStopa;
    // getter za kamatnu stopu
    // setter za kamatnu stopu

public:
    Racun Racun;
    StedniRacun()
    {
        this->KamatnaStopa = 0.0;
    }

    double GetInterestRate() const
    {
        return this->KamatnaStopa;
    }

    void SetInterestRate(double kamatnaStopa)
    {
        this->KamatnaStopa = kamatnaStopa;
    }
};




class TekuciRacun
{
    double Limit;

public:
    Racun Racun;
    // setter za limit
};




class Banker
{
    string Name;
    string Surname;
    string JMBG;
    string Email;
    string Password;

public:
    Banker()
    {
        this->Name = "undefined";
        this->Surname = "undefined";
    }

    Banker(IBanker data)
    {
        this->Name = data.name;
        this->Surname = data.surname;
        this->JMBG = data.jmbg;
        this->Email = data.email;
        this->Password = data.password;
    }

    string GetName()
    {
        return this->Name;
    }

    string GetSurname()
    {
        return this->Surname;
    }

    string GetJMBG()
    {
        return this->JMBG;
    }

    string GetEmail()
    {
        return this->Email;
    }

    string GetPassword()
    {
        return this->Password;
    }

    static vector<Banker> GetAllBankers()
    {
        vector<Banker> bankers;

        ifstream database("database/data/bankers.dat", ios::binary | ios::in);

        if (!database.is_open())
        {
            return bankers;
        }

        Banker banker;
        while (true)
        {
            banker.Deserialize(database);
            if (!database)
            {
                break;
            }
            bankers.push_back(banker);
        }

        database.close();
        return bankers;
    }




    static void SaveBankers(const std::vector<Banker> &bankers)
    {
        ofstream database("database/data/bankers.dat", ios::binary | ios::out | ios::trunc);

        if (!database.is_open())
        {
            return;
        }

        for (const auto &banker : bankers)
        {
            banker.Serialize(database);
        }

        database.close();
    }

    void Serialize(std::ostream &outfile) const;
    void Deserialize(std::istream &inFile);
};





class User
{
    string Name;
    string Surname;
    string JMBG;
    string Email;
    string Password;
    string iznosKreditaStr;
    double iznosKredita = 0;

    public:
    StedniRacun StedniRacun;
    TekuciRacun TekuciRacun;

    User()
    {
        this->Name = "undefined";
        this->Email = "undefined";
    }

    User(IUser data)
    {
        this->Name = data.name;
        this->Surname = data.surname;
        this->Email = data.email;
        this->JMBG = data.jmbg;
        this->Password = data.password;

        this->StedniRacun.Racun.Kartica.SetCardNumber(data.savingsAccountCardNumber);
        this->TekuciRacun.Racun.Kartica.SetCardNumber(data.debitAccountCardNumber);

        this->StedniRacun.Racun.Kartica.SetExpirationDate(data.expirationDateSavingsAccount);
        this->TekuciRacun.Racun.Kartica.SetExpirationDate(data.expirationDateDebitAccount);

        this->StedniRacun.Racun.Kartica.SetCCV(data.ccvSavingsAccount);
        this->TekuciRacun.Racun.Kartica.SetCCV(data.ccvDebitAccount);
    }


    void setIznosKredita(const double& iznos) {
        iznosKredita += iznos;
        return;
    }

    double getIznosKredita() const {
        return iznosKredita;
    }

    
    void Send(double moneyToSend)
    {
        double noviBalans = this->TekuciRacun.Racun.GetAccountBalance() - moneyToSend; 
        this->TekuciRacun.Racun.SetBalance(noviBalans);
    };

    
    void recieve(double moneyToSend)
    {
        double noviBalans = this->TekuciRacun.Racun.GetAccountBalance() + moneyToSend;  
        this->TekuciRacun.Racun.SetBalance(noviBalans);
    };


    string GetName()
    {
        return this->Name;
    }

    string GetSurname()
    {
        return this->Surname;
    }

    string GetEmail()
    {
        return this->Email;
    }

    string GetPassword()
    {
        return this->Password;
    }

    string GetJMBG()
    {
        return this->JMBG;
    }

    string GetFullName()
    {
        return this->Name + " " + this->Surname;
    }

    static vector<User> GetAllUsers()
    {
        vector<User> users;

        ifstream database("database/data/users.dat", ios::binary | ios::in);

        if (!database.is_open())
        {
            return users;
        }

        User user;
        while (true)
        {
            user.Deserialize(database);
            if (!database)
            {
                break;
            }
            users.push_back(user);
        }

        database.close();
        return users;
    }

    static void SaveUsers(const std::vector<User> &users)
    {
        ofstream database("database/data/users.dat", ios::binary | ios::out | ios::trunc);

        if (!database.is_open())
        {
            return;
        }

        for (const auto &user : users)
        {
            user.Serialize(database);
        }

        database.close();
    }

    void Serialize(std::ostream &outfile) const;
    void Deserialize(std::istream &inFile);
    // getteri za : getanje prezimena, emaila, jmbg, passworda, punog imena i prezimena

    void SetName(string NewName)
    {
        this->Name = NewName;
    }

    void SetSurname(string NewSurname)
    {
        this->Surname = NewSurname;
    }

    void SetPassword(string NewPassword)
    {
        this->Password = NewPassword;
    }

    void SetEmail(string NewEmail)
    {
        this->Email = NewEmail;
    }

    void SetJMBG(string NewJMBG)
    {
        this->JMBG = NewJMBG;
    }

};


void User::Serialize(std::ostream &outFile) const
{
    outFile << Name << '|'
            << Surname << '|'
            << Email << '|'
            << JMBG << '|'
            << Password << '|'
            << iznosKredita << '|'
            << TekuciRacun.Racun.Kartica.GetCardNumber() << '|'
            << TekuciRacun.Racun.Kartica.GetExpirationDate() << '|'
            << TekuciRacun.Racun.Kartica.GetCCV() << '|'
            << TekuciRacun.Racun.GetAccountBalance() << '|'

            << StedniRacun.Racun.Kartica.GetCardNumber() << '|'
            << StedniRacun.Racun.Kartica.GetExpirationDate() << '|'
            << StedniRacun.Racun.Kartica.GetCCV() << '|'
            << StedniRacun.Racun.GetAccountBalance() << '|'
            << StedniRacun.GetInterestRate() << '|' << endl;
}

void Banker::Serialize(std::ostream &outFile) const
{
    outFile << Name << '|'
            << Surname << '|'
            << Email << '|'
            << JMBG << '|'
            << Password << '|';
};

void Banker::Deserialize(std::istream &inFile)
{
    getline(inFile, Name, '|');
    getline(inFile, Surname, '|');
    getline(inFile, Email, '|');
    getline(inFile, JMBG, '|');
    getline(inFile, Password, '|');
};

void User::Deserialize(std::istream &inFile)
{
    getline(inFile, Name, '|');
    getline(inFile, Surname, '|');
    getline(inFile, Email, '|');
    getline(inFile, JMBG, '|');
    getline(inFile, Password, '|');
    getline(inFile, iznosKreditaStr, '|');
    if(iznosKreditaStr.size()>0){
    iznosKredita = std::stod(iznosKreditaStr); };

    string debitCardNumber,
        debitCardExpirationDate,
        debitCardCCV,
        debitCardBalance,

        savingsCardNumber,
        savingsCardExpirationDate,
        savingsCardCCV,
        savingsCardBalance,
        savingsAccountInterestRate;

    getline(inFile, debitCardNumber, '|');
    getline(inFile, debitCardExpirationDate, '|');
    getline(inFile, debitCardCCV, '|');
    getline(inFile, debitCardBalance, '|');

    getline(inFile, savingsCardNumber, '|');
    getline(inFile, savingsCardExpirationDate, '|');
    getline(inFile, savingsCardCCV, '|');
    getline(inFile, savingsCardBalance, '|');
    getline(inFile, savingsAccountInterestRate, '|');

    try
    {
        TekuciRacun.Racun.Kartica.SetCardNumber(debitCardNumber);
        TekuciRacun.Racun.Kartica.SetExpirationDate(debitCardExpirationDate);
        TekuciRacun.Racun.Kartica.SetCCV(debitCardCCV);
        TekuciRacun.Racun.SetBalance(stod(debitCardBalance));

        StedniRacun.Racun.Kartica.SetCardNumber(savingsCardNumber);
        StedniRacun.Racun.Kartica.SetExpirationDate(savingsCardExpirationDate);
        StedniRacun.Racun.Kartica.SetCCV(savingsCardCCV);
        StedniRacun.SetInterestRate(stod(savingsAccountInterestRate));
        StedniRacun.Racun.SetBalance(stod(savingsCardBalance));
    }
    catch (const std::invalid_argument &e)
    {
    }

    inFile.ignore(10000, '\n');
}

#endif
