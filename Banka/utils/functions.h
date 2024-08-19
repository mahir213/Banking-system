#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void make_transaction();

string kreirajRandomMasterCardKarticu() {
    string pocetnaCifra = "5"; 

    for (int i = 1; i <= 15; ++i) {
        pocetnaCifra += to_string(rand() % 10);
    }

    return pocetnaCifra;
}

string kreirajRandomVisaCardKarticu() {
    string pocetnaCifra = "4"; 

    for (int i = 1; i <= 15; ++i) {
        pocetnaCifra += to_string(rand() % 10);
    }

    return pocetnaCifra;
}

string kreirajDatumIsteka() {
   
    time_t now = time(0);
    tm* current_time = localtime(&now);

    int current_year = current_time->tm_year + 1900;
    int current_month = current_time->tm_mon + 1; 
    int current_day = current_time->tm_mday;

   
    int expiration_year = current_year + 5;

    
    string expiration_date = std::to_string(current_day) + '/' +
                                std::to_string(current_month) + '/' +
                                std::to_string(expiration_year);

    return expiration_date;
}

string kreirajCCV() {
    int ccv = 100 + rand() % 900;
    return std::to_string(ccv);
}

#endif