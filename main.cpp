#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>


using namespace std;

struct Adresat
{
    int id=0;
    string imie, nazwisko, email, adres, nrTel;
};

void wpiszOsobyDoKsiazki (vector<Adresat> &adresaci)
{
    system("cls");
    Adresat adresat;
    string imie, nazwisko, email,adres, nrTel;

    int IDkolejnejOsoby=1;
    if (adresaci.size()>0)
    IDkolejnejOsoby=(adresaci[adresaci.size()-1].id)+1;

    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj adres zamieszkania: ";
    cin.ignore();
    getline(cin,adres);
    cout<<"Podaj email: ";
    cin>>email;
    cout<<"Podaj numer telefonu: ";
    cin.sync();
    getline(cin,nrTel);

    adresat.id = IDkolejnejOsoby;
    adresat.imie = imie;
    adresat.nazwisko = nazwisko;
    adresat.adres = adres;
    adresat.email = email;
    adresat.nrTel = nrTel;
    adresaci.push_back(adresat);

        cout<<"Osoba zostala wpisana do ksiazki adresowej."<<endl;
        Sleep(1500);

    }


vector<Adresat>wczytajOsobyZPliku()
{
    vector<Adresat> adresaci;
    Adresat adresat;
    system("cls");
    string linia,zastepczy;
    unsigned char c;

    fstream plik;
    plik.open("Adresaci.txt", ios::in);

    if(plik.good()!=false)

    {
        zastepczy = "";

        while (getline(plik,linia))
        {
            int ileDanych=1;
            linia += " ";

            for(int i = 0; i < linia.size(); i++ )
            {
                c = linia[ i ];

                if( c != '|')
                    zastepczy += c;
                else if( zastepczy != "" )
                {
                    if(ileDanych==1)
                        adresat.id=atoi(zastepczy.c_str());
                    if(ileDanych==2)
                        adresat.imie=zastepczy;
                    if(ileDanych==3)
                        adresat.nazwisko=zastepczy;
                    if(ileDanych==4)
                        adresat.adres=zastepczy;
                    if(ileDanych==5)
                        adresat.email=zastepczy;
                    if(ileDanych==6)
                        adresat.nrTel=zastepczy;
                    ileDanych++;
                    zastepczy = "";
                }
            }
            adresaci.push_back(adresat);
        }

    }
plik.close();
 return adresaci;

}


void wyszukajPoImieniu (string wyszukiwaneImie, vector<Adresat> &adresaci)
{
    int iloscZnalezionychOsob=0;
    for(int i=0; i<adresaci.size(); i++)
    {
        size_t pozycja = adresaci[i].imie.find(wyszukiwaneImie);

        if(pozycja!= string::npos)
        {
            int ZnalezioneImie = pozycja;

            cout<<adresaci[i].imie<<endl;
            cout<<adresaci[i].nazwisko<<endl;
            cout<<adresaci[i].adres<<endl;
            cout<<adresaci[i].email<<endl;
            cout<<adresaci[i].nrTel<<endl;
            cout<<endl;
            iloscZnalezionychOsob++;
        }
    }
    if (iloscZnalezionychOsob==0)
        cout<<"Nie znaleziono osoby o podanym imieniu."<<endl;
    getch();
}

void wyszukajPoNazwisku (string wyszukiwaneNazwisko, vector<Adresat> &adresaci)
{
    int iloscZnalezionychOsob=0;
    for(int i=0; i<adresaci.size(); i++)
    {
        size_t pozycja = adresaci[i].nazwisko.find(wyszukiwaneNazwisko);

        if(pozycja!= string::npos)
        {
            int ZnalezioneNazwisko = pozycja;
            cout<<adresaci[i].imie<<endl;
            cout<<adresaci[i].nazwisko<<endl;
            cout<<adresaci[i].adres<<endl;
            cout<<adresaci[i].email<<endl;
            cout<<adresaci[i].nrTel<<endl;
            cout<<endl;
            iloscZnalezionychOsob++;
        }
    }
    if (iloscZnalezionychOsob==0)
        cout<<"Nie znaleziono osoby o podanym nazwisku."<<endl;
    getch();
}

void wyswietlWszystkieOsoby (vector<Adresat> &adresaci)
{
    system("cls");
    if (adresaci.size()==0)
    {
        cout<<"Ksiazka adresowa jest pusta";
        Sleep(1500);
    }
    else
    {
        for(int i=0; i<adresaci.size(); i++ )
    {
        cout<<"ID: "<<adresaci[i].id<<endl;
        cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
        cout<<"Adres: "<<adresaci[i].adres<<endl;
        cout<<"Email: "<<adresaci[i].email<<endl;
        cout<<"Telefon: "<<adresaci[i].nrTel<<endl;
        cout<<endl;
    }
    getch();
    }

}
void usunOsobe (int IDosobyDoUsuniecia, vector<Adresat> &adresaci)
{
    char wybor;
    int nrPozDoUsuniecia;
    system("cls");
    for(int i=0; i<adresaci.size(); i++ )
    {
        if (adresaci[i].id==IDosobyDoUsuniecia)
        {
            cout<<"ID: "<<adresaci[i].id<<endl;
            cout<<adresaci[i].imie<<" "<<adresaci[i].nazwisko<<endl;
            cout<<"Adres: "<<adresaci[i].adres<<endl;
            cout<<"Email: "<<adresaci[i].email<<endl;
            cout<<"Telefon: "<<adresaci[i].nrTel<<endl;
            cout<<endl;
            nrPozDoUsuniecia=i;

            cout<<"Potwierdz usuniecie: t"<<endl;
            cout<<"Anuluj: n"<<endl;
            cin>>wybor;
        }
    }
    if (wybor=='t')
    {
        adresaci.erase(adresaci.begin()+nrPozDoUsuniecia);
        system("cls");
        cout<<"Osoba zostala usunieta z ksiazki adresowej"<<endl;
        Sleep(1500);
    }
    if(wybor=='n')
    {
        system("cls");
        cout<<"Powrot do menu glownego"<<endl;
        Sleep(1500);
    }
}

void edytujOsobe (char wybor, vector<Adresat> &adresaci)
{
    int IDedytowanejOsoby,nrPozDoEdycji;
    string imieZmienione, nazwiskoZmienione, nrTelZmieniony,adresZmieniony,emailZmieniony;
    cout<<"Podaj ID edytowanej osoby: ";
    cin>>IDedytowanejOsoby;
    for(int i=0; i<adresaci.size(); i++ )
    {
        if (adresaci[i].id==IDedytowanejOsoby)
            nrPozDoEdycji=i;
    }
    if(wybor=='1')
    {
        system("cls");
        cout<<adresaci[nrPozDoEdycji].imie<<endl;
        cout<<"Zmien na: ";
        cin>>imieZmienione;
        adresaci[nrPozDoEdycji].imie=imieZmienione;
        system("cls");
        cout<<"Imie zostalo zmienione"<<endl;
        Sleep(1000);
    }
    if(wybor=='2')
    {
        system("cls");
        cout<<adresaci[nrPozDoEdycji].nazwisko<<endl;
        cout<<"Zmien na: ";
        cin>>nazwiskoZmienione;
        adresaci[nrPozDoEdycji].nazwisko=nazwiskoZmienione;
        system("cls");
        cout<<"Nazwisko zostalo zmienione"<<endl;
        Sleep(1000);
    }
    if(wybor=='3')
    {
        system("cls");
        cout<<adresaci[nrPozDoEdycji].nrTel<<endl;
        cout<<"Zmien na: ";
        cin>>nrTelZmieniony;
        adresaci[nrPozDoEdycji].nrTel=nrTelZmieniony;
        system("cls");
        cout<<"Numer telefonu zostal zmieniony"<<endl;
        Sleep(1000);
    }
    if(wybor=='4')
    {
        system("cls");
        cout<<adresaci[nrPozDoEdycji].email<<endl;
        cout<<"Zmien na: ";
        cin>>emailZmieniony;
        adresaci[nrPozDoEdycji].email=emailZmieniony;
        system("cls");
        cout<<"Email zostal zmieniony"<<endl;
        Sleep(1000);
    }
    if(wybor=='5')
    {
        system("cls");
        cout<<adresaci[nrPozDoEdycji].adres<<endl;
        cout<<"Zmien na: ";
        cin>>adresZmieniony;
        adresaci[nrPozDoEdycji].adres=adresZmieniony;
        system("cls");
        cout<<"Adres zostal zmieniony"<<endl;
        Sleep(1000);
    }
}

void zapisDoPliku (vector<Adresat> &adresaci)
{
    ofstream plik;
    plik.open("Adresaci.txt", ios::out);
    if (plik.good()==true)
    {
        for (int i=0; i<adresaci.size(); i++)
        {
            plik<<adresaci[i].id<<"|";
            plik<<adresaci[i].imie<<"|";
            plik<<adresaci[i].nazwisko<<"|";
            plik<<adresaci[i].adres<<"|";
            plik<<adresaci[i].email<<"|";
            plik<<adresaci[i].nrTel<<"|"<<endl;
        }
        plik.close();
    }
}

struct Uzytkownik
{
    int id=0;
    string nazwa, haslo;
};

vector<Uzytkownik>wczytajUzytkownikowZPliku()
{
    vector<Uzytkownik> uzytkownicy;
    Uzytkownik uzytkownik;
    system("cls");
    string linia,zastepczy;
    unsigned char c;

    fstream plik;
    plik.open("Uzytkownicy.txt", ios::in);

    if(plik.good()!=false)
    {
        zastepczy = "";

        while (getline(plik,linia))
        {
            int ileDanych=1;
            linia += " ";

            for(int i = 0; i < linia.size(); i++ )
            {
                c = linia[ i ];

                if( c != '|')
                    zastepczy += c;
                else if( zastepczy != "" )
                {
                    if(ileDanych==1)
                        uzytkownik.id=atoi(zastepczy.c_str());
                    if(ileDanych==2)
                        uzytkownik.nazwa=zastepczy;
                    if(ileDanych==3)
                        uzytkownik.haslo=zastepczy;
                    ileDanych++;
                    zastepczy = "";
                }
            }
            uzytkownicy.push_back(uzytkownik);
        }
    }
    plik.close();
    return uzytkownicy;
}

void zarejestrujUzytkownika (vector<Uzytkownik> &uzytkownicy)
{
    system("cls");
    Uzytkownik uzytkownik;
    string nazwa, haslo;

    int IDuzytkownika=1;
    if (uzytkownicy.size()>0)
        IDuzytkownika=uzytkownicy.size()+1;

    cout<<"Podaj nazwe uzytkownika: ";
    cin>>nazwa;

    cout<<"Podaj haslo: ";
    cin>>haslo;

    uzytkownik.id = IDuzytkownika;
    uzytkownik.nazwa = nazwa;
    uzytkownik.haslo = haslo;
    uzytkownicy.push_back(uzytkownik);

    cout<<"Uzytkownik zostal zarejestrowany."<<endl;
    Sleep(1500);
}

int zalogujUzytkownika (vector<Uzytkownik> &uzytkownicy)
{
    system("cls");
    string nazwa, haslo;
    cout<<"Podaj nazwe: ";
    cin>>nazwa;
    for(int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].nazwa==nazwa)
        {
            for (int j=0; j<3; j++)
            {
                cout<<"Podaj haslo: ";
                cin>>haslo;
                if (uzytkownicy[i].haslo==haslo)
                {
                    cout<<"Zalogowales sie."<<endl;
                    Sleep(1000);
                    return uzytkownicy[i].id;
                }
            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed nastepna probe.";
            Sleep(3000);
            return 0;
        }
    }
    cout<<"Nie ma uzytkownika z takim loginem."<<endl;
    Sleep(1500);
    return 0;
}

void zapisDoPliku (vector<Uzytkownik> &uzytkownicy)
{
    ofstream plik;
    plik.open("Uzytkownicy.txt", ios::out);
    if (plik.good()==true)
    {
        for (int i=0; i<uzytkownicy.size(); i++)
        {
            plik<<uzytkownicy[i].id<<"|";
            plik<<uzytkownicy[i].nazwa<<"|";
            plik<<uzytkownicy[i].haslo<<"|"<<endl;
        }
        plik.close();
    }
}

int przejdzDoKsiazkiAdresowej (int IDzalogowanegoUzytkownika)
{
    vector <Adresat>adresaci;
    string wyszukiwaneImie, wyszukiwaneNazwisko;
    adresaci=wczytajOsobyZPliku();
    char wybor;

    while (1)
    {
        system("cls");

        cout<<"1.Dodaj adresata"<<endl;
        cout<<"2.Wyszukaj po imieniu"<<endl;
        cout<<"3.Wyszukaj po nazwisku"<<endl;
        cout<<"4.Wyswietl wszystkich adresatow"<<endl;
        cout<<"5.Usun adresata"<<endl;
        cout<<"6.Edytuj adresata"<<endl;
        cout<<"9.Zakoncz program"<<endl;
        cout<<"Twoj wybor: ";
        cin>>wybor;

        switch(wybor)
        {
        case '1':
        {
            wpiszOsobyDoKsiazki (adresaci);
            zapisDoPliku(adresaci);
        }
        break;
        case '2':
        {
            system("cls");
            cout<<"Wyszukiwanie po imieniu"<<endl;
            cout<<"Wpisz wyszukiwane imie: ";
            cin>>wyszukiwaneImie;

            wyszukajPoImieniu (wyszukiwaneImie,adresaci);

        }
        break;
        case '3':
        {
            system("cls");
            cout<<"Wyszukiwanie po nazwisku"<<endl;
            cout<<"Wpisz wyszukiwane nazwisko: ";
            cin>>wyszukiwaneNazwisko;

            wyszukajPoNazwisku (wyszukiwaneNazwisko,adresaci);
        }
        break;
        case '4':
        {
             wyswietlWszystkieOsoby (adresaci);
        }
        break;
        case '5':
        {
            int IDosobyDoUsuniecia;
            system("cls");
            cout<<"Usuwanie osoby z ksiazki"<<endl;
            cout<<"Wpisz ID osoby, ktora chcesz usunac: ";
            cin>>IDosobyDoUsuniecia;
            usunOsobe (IDosobyDoUsuniecia, adresaci);
            zapisDoPliku (adresaci);

        }
        break;
        case '6':
        {
            char wyborEdycji;
            system("cls");
            cout<<"Wybierz obszar edycji osoby:"<<endl;
            cout<<"1-imie"<<endl;
            cout<<"2-nazwisko"<<endl;
            cout<<"3-numer telefonu"<<endl;
            cout<<"4-email"<<endl;
            cout<<"5-adres"<<endl;
            cout<<"6-powrot do menu"<<endl;
            cin>>wyborEdycji;
            if(wyborEdycji=='6')
            {
                system("cls");
                cout<<"Powrot do menu glownego"<<endl;
                Sleep(1000);
            }
            else
                edytujOsobe (wyborEdycji, adresaci);
                zapisDoPliku (adresaci);
        }
        break;
        case '9':
        {
            return 0;
        }
        break;

        default:
            cout<<"Nie ma takiej opcji do wyboru!"<<endl;
            Sleep(1500);
        }
    }
}


int main()
{
    vector <Uzytkownik>uzytkownicy;
    uzytkownicy=wczytajUzytkownikowZPliku();
    int IDzalogowanegoUzytkownika=0;

    char wybor;

    while (1)
    {
        system("cls");
        cout<<"1.Rejestracja uzytkownika"<<endl;
        cout<<"2.Logowanie uzytkownika"<<endl;
        cout<<"3.Zakoncz program"<<endl;
        cout<<"Twoj wybor: ";
        cin>>wybor;

        switch(wybor)
        {
        case '1':
        {
            zarejestrujUzytkownika (uzytkownicy);
            zapisDoPliku(uzytkownicy);
        }
        break;

        case '2':
        {
            IDzalogowanegoUzytkownika=zalogujUzytkownika(uzytkownicy);
            if (IDzalogowanegoUzytkownika!=0)
            {
                przejdzDoKsiazkiAdresowej(IDzalogowanegoUzytkownika);
            }
        }
        break;

        case '3':
        {
            exit(0);
        }
        break;
        }
    }
    return 0;
}
