/****************************************************************************
**                          SAKARYA ÜNİVERSİTESİ
**                BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                      PROGRAMLAMAYA GİRİŞİ DERSİ
**
**                          ÖDEV NUMARASI…...:1
**                          ÖĞRENCİ ADI......:FURKAN KOÇ
**                          ÖĞRENCİ NUMARASI.:G171210303
**                          DERS GRUBU.......:1. ÖĞRETİM A GRUBU
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

//Urunlerin sayilarinin alindigi fonksiyon
int urunSayisiAl()
{
    int urunSayisi = 0;
    ifstream urunSayisiAl("Urunler.txt");
    string satir = "";
    //Eğer dosya açılabildiyse if'in içine gir yoksa girme.
    if (urunSayisiAl.is_open())
    {
        //Dosyada ki her bir satır için urun sayisini 1 arttir
        while (getline(urunSayisiAl, satir))
        {
            urunSayisi++;
        }
    }
    urunSayisiAl.close();
    return urunSayisi;
}
//Butun urunlerin listelendigi fonksiyon
void urunleriListele()
{
    int urunNo;
    string ad;
    string birim;
    int fiyat;
    string marka;
    ifstream dosyaOku;
    dosyaOku.open("Urunler.txt", ios::in);
    //Açılan dosyanın son satırına kadar okuma işlemine devam et.
    while (!dosyaOku.eof())
    {
        dosyaOku >> urunNo >> ad >> birim >> fiyat >> marka;
        cout << "Urun Numarasi : " << urunNo << " | Urun Adi : " << ad << " | Birimi : " << birim << " | Fiyat : " << fiyat << " | marka : " << marka << endl;
    }
    dosyaOku.close();
}

int projeSayisiAl()
{
    int projeSayisi = 0;
    ifstream projeSayisiAl("Projeler.txt");
    string satir = "";
    //Eğer dosya açılabildiyse if'in içine gir yoksa girme.
    if (projeSayisiAl.is_open())
    {
        //Dosyadaki her bir satir icin proje sayisini 1 arttir
        while (getline(projeSayisiAl, satir))
        {
            projeSayisi++;
        }
    }
    return projeSayisi;
}
//Butun projelerin listelendigi fonksiyon
void projeleriListele()
{
    int projeNo;
    string projeAdi;
    string yurutucuFirmaAdi;
    string projeSorumlusu;
    string projeKontroloru;
    bool hakedisVerildiMi;
    string hakedisKontrol;
    ifstream dosyaOku;
    dosyaOku.open("Projeler.txt", ios::in);
    //Acilan dosyanın son satirina kadar okuma islemi yap
    while (!dosyaOku.eof())
    {
        dosyaOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi;
        //Hakedis verildimi degiskeni 0 ise hakedisKontrol degiskenine "hayir" ata
        if (hakedisVerildiMi == 0)
        {
            hakedisKontrol = "Hayir";
        }
        //0 degil ise hakedisKontrol degiskenine "Evet" ata
        else
        {
            hakedisKontrol = "Evet";
        }
        cout << "Proje Numarasi : " << projeNo << " | Proje Adi : " << projeAdi << " | Yurutucu Firma Adi : " << yurutucuFirmaAdi << " | Proje Sorumlusu : " << projeSorumlusu << " | Hakedis Verildi Mi? : " << hakedisKontrol << endl;
    }
    dosyaOku.close();
}
//Hakedislerin sayisinin alindigi fonksiyon
int hakedisSayisiAl()
{
    int hakedisSayisi = 0;
    ifstream hakedisSayisiAl("Hakedisler.txt");
    string satir = "";
    //Eğer dosya açılabildiyse if'in içine gir yoksa girme.
    if (hakedisSayisiAl.is_open())
    {
        //Dosyadaki her bir satır için hakediş sayısını 1 arttır
        while (getline(hakedisSayisiAl, satir))
        {
            hakedisSayisi++;
        }
    }
    return hakedisSayisi;
}
//Program ilk baslatildigi zaman calisacak fonksiyon
int main()
{
    int secim = 0;
    //Program ilk acildiginda ekrana gelecek menu ve secim islemleri icin gerekli olan dongu
    do
    {
        system("cls");
        cout << "Hosgeldiniz. Ne yapmak istiyorsunuz?" << endl;
        cout << "1) Urunler Sayfasina Git" << endl;
        cout << "2) Projeler Sayfasina Git" << endl;
        cout << "3) Hakedis Sayfasina Git" << endl;
        cout << "4) Cikis" << endl;
        cout << "Seciminiz  :" << endl;
        cin >> secim;
        //Eger secim 1 ise urunler bloguna gir
        if (secim == 1)
        {
            int urunSayisi = urunSayisiAl();
            int urunNo;
            string ad;
            string birim;
            int fiyat;
            string marka;
            int urunSecim = 0;
            //Urunler blogundaki menuyu ve secim islemleri icin gerekli olan dongu
            do
            {
                cout << "Urunler Sayfasindasiniz. Ne yapmak istersiniz?" << endl;
                cout << "1) Urun Ekle" << endl;
                cout << "2) Urun Silme" << endl;
                cout << "3) Urun Arama" << endl;
                cout << "4) Raporlama" << endl;
                cout << "5) Geri Don" << endl;
                cout << "Seciminiz  :   ";
                cin >> urunSecim;
                // Eger urunSecim 1 ise urun ekleme kismina gir
                if (urunSecim == 1)
                {
                    bool urunKontrol = false;
                    int sayac = 0;
                    int *urunNumaralari = new int[urunSayisi];

                    ifstream dosyaOku;
                    dosyaOku.open("Urunler.txt", ios::in);
                    //Dosyanin sonuna kadar okuma islemi yap
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> urunNo >> ad >> birim >> fiyat >> marka;
                        urunNumaralari[sayac] = urunNo;
                        sayac++;
                    }
                    dosyaOku.close();
                    cout << "Urun numarasi giriniz  :   ";
                    cin >> urunNo;
                    cout << endl;
                    cout << "Urun Adi giriniz  :   ";
                    cin >> ad;
                    cout << endl;
                    cout << "Urun birimi giriniz  :   ";
                    cin >> birim;
                    cout << endl;
                    cout << "Urun birim fiyati giriniz  :   ";
                    cin >> fiyat;
                    cout << endl;
                    cout << "Urun markasi giriniz  :   ";
                    cin >> marka;
                    cout << endl;
                    //Girilin urun numarasi ile urunler dosyasindan alinan urun numaralarini karsilastirmak icin gerekli olan dongu
                    for (int i = 0; i < urunSayisi; i++)
                    {
                        //Eger girilen urunNo ile urun numalarindan birisi eslesirse bu urun numarasi kullanilmaktadir yazdiran kosul
                        if (urunNo == urunNumaralari[i])
                        {
                            cout << "Bu urun numarasi kullanilmaktadir lutfen baska bir urun numarasi deneyiniz!";
                            urunKontrol = true;
                        }
                    }
                    //urunKontrol degiskeni false ise urunu ekleme islemi yapiyoruz.
                    if (urunKontrol == false)
                    {
                        ofstream urunEkle("Urunler.txt", std::ios::app);
                        //Dosya acildi mi diye yapilan kontrol
                        if (urunEkle.is_open())
                        {
                            urunEkle << endl
                                     << urunNo << " " << ad << " " << birim << " " << fiyat << " " << marka;
                            urunEkle.close();
                            cout << endl
                                 << "Urun basariyla eklendi!" << endl;
                        }
                    }
                    delete urunNumaralari;
                }
                //Eger urunSecim 2 ise urun silme bloğuna gir
                else if (urunSecim == 2)
                {
                    int urunNo2 = 0;
                    int sayac = 0;
                    int *urunNumaralari = new int[urunSayisi];
                    cout << "Urunler : " << endl;
                    ifstream dosyaOku;
                    dosyaOku.open("Urunler.txt", ios::in);
                    //Dosyanin sonuna kadar okuma islemi yap
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> urunNo >> ad >> birim >> fiyat >> marka;
                        urunNumaralari[sayac] = urunNo;
                        cout << "Urun Numarasi : " << urunNo << " | Urun Adi : " << ad << " | Birimi : " << birim << " | Fiyat : " << fiyat << " | marka : " << marka << endl;
                        sayac++;
                    }
                    dosyaOku.close();

                    cout << "Hangi Urun Numarali Urunu Silmek Istersiniz? : ";
                    cin >> urunNo2;

                    ifstream urunleriOku("Urunler.txt");
                    ofstream geciciDosyaYaz("Urunler.tmp");
                    //Urunler dosyasindaki her bir urunu tek tek oku
                    while (urunleriOku >> urunNo >> ad >> birim >> fiyat >> marka)
                    {
                        //Eger girilen urunNo ile dosyadaki urunNo eslesirse bir sey yapma yani urunu sil
                        if (urunNo2 == urunNo)
                        {
                        }
                        //Eslesmezse urunleri aynı şekilde yazdırmaya devam et
                        else
                        {
                            geciciDosyaYaz << "\n"
                                           << urunNo << " " << ad << " " << birim << " " << fiyat << " " << marka;
                        }
                    }

                    urunleriOku.close();
                    geciciDosyaYaz.close();
                    remove("Urunler.txt");
                    rename("Urunler.tmp", "Urunler.txt");

                    cout << endl
                         << "Urun silindi" << endl;
                    delete urunNumaralari;
                }
                //Eger urunSecim 3 ise urun arama bloğuna gir
                else if (urunSecim == 3)
                {
                    string urunAdi;
                    bool urunVarmi = false;
                    cout << endl
                         << "Aramak istediginiz urun adini giriniz   :   ";
                    cin >> urunAdi;
                    ifstream urunleriOku("Urunler.txt");
                    //urunler dosyasindaki her bir satiri tek tek oku
                    while (urunleriOku >> urunNo >> ad >> birim >> fiyat >> marka)
                    {
                        //eger girilen ad ile urunler sayfasindan alinan ad eslesirse ekrana yazdir
                        if (urunAdi == ad)
                        {
                            cout << endl
                                 << "Urun Mevcuttur! " << endl;
                            cout << "Urun Numarasi : " << urunNo << endl;
                            cout << "Urun Adi : " << ad << endl;
                            cout << "Urun Birimi : " << birim << endl;
                            cout << "Urun Fiyati : " << fiyat << endl;
                            cout << "Urun Markasi : " << marka << endl;
                            urunVarmi = true;
                            break;
                        }
                    }
                    if (urunVarmi == false)
                    {
                        cout << endl << "Boyle bir urun bulunmamaktadir!" << endl;
                    }
                    
                    urunleriOku.close();
                }
                //Eger urunSecim 4 ise urunleri raporlama bloğuna gir
                else if (urunSecim == 4)
                {
                    //Butun urunleri yazdir
                    urunleriListele();
                }

            } while (urunSecim != 5);
        }
        //Eger secim 2 ise projeler bloguna giris yap
        else if (secim == 2)
        {
            int projeSecim = 0;
            int projeSayisi = projeSayisiAl();
            int projeNo;
            string projeAdi;
            string yurutucuFirmaAdi;
            string projeSorumlusu;
            string projeKontroloru;
            bool hakedisVerildiMi = false;
            //Projeler blogundaki menuyu gostermek ve secim islemini yapmak icin gerekli olan dongu
            do
            {
                cout << "Projeler Sayfasindasiniz. Ne yapmak istersiniz?" << endl;
                cout << "1) Proje Ekle" << endl;
                cout << "2) Proje Silme" << endl;
                cout << "3) Proje Arama" << endl;
                cout << "4) Raporlama" << endl;
                cout << "5) Geri Don" << endl;
                cout << "Seciminiz  :   ";
                cin >> projeSecim;
                //Eger projeSecim 1 ise proje ekleme bloguna giris yap
                if (projeSecim == 1)
                {
                    bool projeKontrol = false;
                    int sayac = 0;
                    int *projeNumaralari = new int[projeSayisi];

                    ifstream dosyaOku;
                    dosyaOku.open("Projeler.txt", ios::in);
                    //Dosya sonuna kadar okuma yap
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi;
                        projeNumaralari[sayac] = projeNo;
                        sayac++;
                    }
                    dosyaOku.close();
                    cout << "Proje numarasi giriniz  :   ";
                    cin >> projeNo;
                    cout << endl;
                    cout << "Proje adi giriniz  :   ";
                    cin >> projeAdi;
                    cout << endl;
                    cout << "Proje yurutucu firma adi giriniz   :   ";
                    cin >> yurutucuFirmaAdi;
                    cout << endl;
                    cout << "Proje sorumlusunu giriniz  :   ";
                    cin >> projeSorumlusu;
                    cout << endl;
                    cout << "Proje kontroloru giriniz  :   ";
                    cin >> projeKontroloru;
                    cout << endl;
                    //Girilen proje numarasinin eski projelerden birisi tarafından kullanilip kullanilmadigini gormek icin gerekli olan dongu
                    for (int i = 0; i < projeSayisi; i++)
                    {
                        //Eger proje numarasi kullaniliyorsa mesaji yazdir
                        if (projeNo == projeNumaralari[i])
                        {
                            cout << "Bu proje numarasi kullanilmaktadir lutfen baska bir proje numarasi deneyiniz!";
                            projeKontrol = true;
                        }
                    }
                    //Proje numarasi kullanilmiyorsa projeyi ekle
                    if (projeKontrol == false)
                    {
                        ofstream projeEkle("Projeler.txt", std::ios::app);
                        //Dosya acildi mi diye kontrol et
                        if (projeEkle.is_open())
                        {
                            projeEkle << endl
                                      << projeNo << " " << projeAdi << " " << yurutucuFirmaAdi << " " << projeSorumlusu << " " << projeKontroloru << " " << hakedisVerildiMi;
                            projeEkle.close();
                            cout << endl
                                 << "Proje basariyla eklendi!" << endl;
                        }
                    }
                    delete projeNumaralari;
                }
                //Eger projeSecim 2 ise proje silme bloguna gir
                else if (projeSecim == 2)
                {
                    int projeNo2 = 0;
                    int sayac = 0;
                    int *projeNumaralari = new int[projeSayisi];
                    string hakedisKontrol;
                    cout << "Projeler : " << endl;
                    ifstream dosyaOku;
                    dosyaOku.open("Projeler.txt", ios::in);
                    //Dosyayi sonuna kadar oku
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi;
                        projeNumaralari[sayac] = projeNo;
                        //Hakedis verildiyse evet eger verilmediyse hayir yazdirmak icin kullanilan kosulumuz
                        if (hakedisVerildiMi == 0)
                        {
                            hakedisKontrol = "Hayir";
                        }
                        else
                        {
                            hakedisKontrol = "Evet";
                        }
                        cout << "Proje Numarasi : " << projeNo << " | Proje Adi : " << projeAdi << " | Yurutu Firma Adi : " << yurutucuFirmaAdi << " | Proje Sorumlusu : " << projeSorumlusu << " | Hakedis Verildi Mi? : " << hakedisKontrol << endl;
                        sayac++;
                    }
                    dosyaOku.close();

                    cout << "Hangi Proje Numarali Projeyi Silmek Istersiniz? : ";
                    cin >> projeNo2;

                    ifstream projeleriOku("Projeler.txt");
                    ofstream geciciDosyaYaz("Projeler.tmp");
                    //Dosyayi satir satir oku
                    while (projeleriOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi)
                    {
                        //girilen proje no ile projeler dosyasindaki proje nolari karsilastir eger eslesirse if'in icine gir
                        if (projeNo2 == projeNo)
                        {
                            //Hakedis verildiyse proje silinemez uyarisi verdirmek icin kullanilan kosul
                            if (hakedisVerildiMi == 1)
                            {
                                cout << endl
                                     << "Hakedis verildigi icin bu proje silinemez!" << endl;
                                geciciDosyaYaz << "\n"
                                               << projeNo << " " << projeAdi << " " << yurutucuFirmaAdi << " " << projeSorumlusu << " " << projeKontroloru << " " << hakedisVerildiMi;
                            }
                            //hakedis verilmediyse bir sey yapma yani projeyi sil
                            else
                            {
                            }
                        }
                        //proje nolari eslesmezse ayni sekilde yazdir
                        else
                        {
                            geciciDosyaYaz << "\n"
                                           << projeNo << " " << projeAdi << " " << yurutucuFirmaAdi << " " << projeSorumlusu << " " << projeKontroloru << " " << hakedisVerildiMi;
                        }
                    }

                    projeleriOku.close();
                    geciciDosyaYaz.close();
                    remove("Projeler.txt");
                    rename("Projeler.tmp", "Projeler.txt");
                    delete projeNumaralari;
                }
                //Eger projeSecim 3 ise proje arama bloguna giris yap
                else if (projeSecim == 3)
                {
                    string projeAdi2;
                    string hakedisKontrol;
                    bool aramaKontrol = false;
                    cout << endl
                         << "Aramak istediginiz proje adini giriniz   :   ";
                    cin >> projeAdi2;
                    ifstream projeleriOku("Projeler.txt");
                    //Dosyayi satir satir oku
                    while (projeleriOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi)
                    {
                        //Hakedis verildiyse evet verilmediyse hayir yazdirmak icin kullanilan kosul
                        if (hakedisVerildiMi == 0)
                        {
                            hakedisKontrol = "Hayir";
                        }
                        else
                        {
                            hakedisKontrol = "Evet";
                        }
                        //Girilen proje adi ile projeler dosyasindaki proje adi eslesirse bilgileri yazdir
                        if (projeAdi2 == projeAdi)
                        {
                            cout << endl
                                 << "Proje Mevcuttur!" << endl;
                            cout << "Proje Numarasi : " << projeNo << endl;
                            cout << "Proje Adi : " << projeAdi << endl;
                            cout << "Proje Yurutucu Firmasi : " << yurutucuFirmaAdi << endl;
                            cout << "Proje Sorumlusu : " << projeSorumlusu << endl;
                            cout << "Proje Kontroloru : " << projeKontroloru << endl;
                            cout << "Hakedis Verildi Mi? : " << hakedisKontrol << endl;
                            aramaKontrol = true;
                        }
                    }
                    projeleriOku.close();
                    //Eger proje bulunamadiyse uyari ver
                    if (aramaKontrol == false)
                    {
                        cout << endl
                             << "Aranan Proje Bulunmamaktadir!" << endl;
                    }
                }
                //Eger projeSecim 4 ise projeleri raporlama kismina giris yap
                else if (projeSecim == 4)
                {
                    //Butun projelerin bilgilerini yazdir
                    projeleriListele();
                }

            } while (projeSecim != 5);
        }
        //Eger secim 3 ise hakedisler bloguna gir
        else if (secim == 3)
        {
            int hakedisSecim = 0;
            int projeSayisi = projeSayisiAl();
            //Hakedisler menusunu yazdirmak ve secim islemini yaptirmak icin gerekli olan dongu
            do
            {
                cout << "Hakedis Sayfasindasiniz. Ne yapmak istersiniz?" << endl;
                cout << "1) Hakedis ekle" << endl;
                cout << "2) Hakedis bilgilerini gormek istediginiz projeyi seciniz.." << endl;
                cout << "3) Hakedis donemine gore toplam hakedis tutarlarini gor." << endl;
                cout << "4) Geri Don" << endl;
                cout << "Seciminiz  :   ";
                cin >> hakedisSecim;
                //Eger hakedisSecim 1 ise hakedis ekleme bloguna gir
                if (hakedisSecim == 1)
                {

                    system("cls");
                    int projeNo;
                    int hakedisDonemi;
                    int eklenecekUrunNo;
                    int eklenecekUrunFiyati;
                    int urunAdedi;
                    int *projeNumaralari = new int[projeSayisi];
                    bool projeKontrol = false;
                    int sayac = 0;

                    cout << "---Hakedis eklenebilecek projeler listesi---" << endl;
                    projeleriListele();

                    cout << endl
                         << "---Eklenebilecek urunler listesi---" << endl;
                    urunleriListele();

                    cout << "Proje numarasi giriniz  :   ";
                    cin >> projeNo;
                    cout << endl;
                    cout << "Urun numarasi giriniz  :   ";
                    cin >> eklenecekUrunNo;
                    cout << endl;
                    cout << "Urun adedi giriniz   :   ";
                    cin >> urunAdedi;
                    cout << endl;
                    cout << "Urun fiyati giriniz  :   ";
                    cin >> eklenecekUrunFiyati;
                    cout << endl;
                    cout << "Hakedis Donemini Giriniz(1,2,3)  :   ";
                    cin >> hakedisDonemi;
                    cout << endl;

                    // ! proje numalarini almak icin
                    int kontrolProjeNo;
                    string projeAdi;
                    string yurutucuFirmaAdi;
                    string projeSorumlusu;
                    string projeKontroloru;
                    int hakedisVerildiMi;

                    ifstream dosyaOku;
                    dosyaOku.open("Projeler.txt", ios::in);
                    //Dosyanin sonuna kadar okuma islemi yap
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> kontrolProjeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi;
                        projeNumaralari[sayac] = kontrolProjeNo;
                        sayac++;
                    }
                    dosyaOku.close();
                    //Girilen proje no ile projeler dosyasindaki proje nolari karsilastirmak icin kurulan dongu
                    for (int i = 0; i < projeSayisi; i++)
                    {
                        //Eger eslesme var ise projeKontrol degiskenini true yap
                        if (projeNo == projeNumaralari[i])
                        {
                            projeKontrol = true;
                        }
                    }
                    //Eger projeKontrol true ise hakedis'i ekle
                    if (projeKontrol == true)
                    {
                        ofstream hakedisEkle("Hakedisler.txt", std::ios::app);
                        if (hakedisEkle.is_open())
                        {
                            hakedisEkle << endl
                                        << projeNo << " " << eklenecekUrunNo << " " << urunAdedi << " " << eklenecekUrunFiyati << " " << hakedisDonemi;
                            hakedisEkle.close();
                            cout << endl
                                 << "Hakedis basariyla eklendi!" << endl;
                        }
                        hakedisEkle.close();
                        int guncellemeProjeNo;
                        int kontrolHakedisVerildiMi;
                        int guncellemehakedisVerildiMi = 1;
                        ifstream projeleriOku("Projeler.txt");
                        ofstream geciciDosyaYaz("Projeler.tmp");
                        //Projeler dosyasindaki hakedis eklendi mi kismini eger hakedis eklendiyse hakedisverildimi kismini true yapmak icin kullanilan fonksiyon
                        while (projeleriOku >> guncellemeProjeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> kontrolHakedisVerildiMi)
                        {
                            //Eger hakedis verilen proje ile projeler dosyasindan okunan proje no eslesirse hakedisverildimi kismini true yap
                            if (projeNo == guncellemeProjeNo)
                            {
                                geciciDosyaYaz << "\n"
                                               << guncellemeProjeNo << " " << projeAdi << " " << yurutucuFirmaAdi << " " << projeSorumlusu << " " << projeKontroloru << " " << guncellemehakedisVerildiMi;
                            }
                            //eslesmezse ayni sekilde yazdir.
                            else
                            {
                                geciciDosyaYaz << "\n"
                                               << guncellemeProjeNo << " " << projeAdi << " " << yurutucuFirmaAdi << " " << projeSorumlusu << " " << projeKontroloru << " " << kontrolHakedisVerildiMi;
                            }
                        }

                        projeleriOku.close();
                        geciciDosyaYaz.close();
                        remove("Projeler.txt");
                        rename("Projeler.tmp", "Projeler.txt");

                        cout << endl
                             << "denemeee";
                    }
                    else // eger proje yoksa verilecek olan mesaj
                    {
                        cout << endl
                             << "Bu proje numarasi kullanilmamaktadir! Lutfen varolan projelerden birini seciniz!" << endl
                             << endl;
                    }
                    delete projeNumaralari;
                }
                //Eger hakedisSecim 2 ise projelerin hakedis islemleri ile ilgili bloga gir
                else if (hakedisSecim == 2)
                {
                    projeleriListele();
                    bool hakedisKontrol = false;
                    bool devamMi = true;
                    int projeNo;
                    int hakedisProjeNo;
                    string projeAdi;
                    string yurutucuFirmaAdi;
                    string projeSorumlusu;
                    string projeKontroloru;
                    int hakedisVerildiMi;
                    bool hakedisVerildiMiKontrol = false;
                    cout << endl
                         << "Hakedisini gormek istediginiz proje numarasini giriniz :   ";
                    cin >> hakedisProjeNo;

                    cout << endl;
                    ifstream projeleriOku("Projeler.txt");
                    //Butun projeleri tek tek oku
                    while (projeleriOku >> projeNo >> projeAdi >> yurutucuFirmaAdi >> projeSorumlusu >> projeKontroloru >> hakedisVerildiMi)
                    {
                        //Eger hakedisini gormek istedigimiz proje numarasi ile projeler dosyasindaki proje eslesirse if'in icine gir
                        if (hakedisProjeNo == projeNo)
                        {
                            //Eger secilen projenin hakedisi'i verildiyse bilgilerini yazdir
                            if (hakedisVerildiMi == 1)
                            {
                                cout << endl;
                                cout << "Projer Numarasi : " << projeNo << endl;
                                cout << "Proje Adi : " << yurutucuFirmaAdi << endl;
                                cout << "Proje Sorumlusu : " << projeSorumlusu << endl;
                                cout << "Proje Kontroloru : " << projeKontroloru << endl
                                     << endl;
                                devamMi = true;
                                hakedisKontrol = true;
                                hakedisVerildiMiKontrol = true;
                                break;
                            }
                            //hakedis verilmemisse
                            else
                            {
                                hakedisVerildiMiKontrol = false;
                                hakedisKontrol = true;
                                break;
                            }
                        }
                        else //proje numarasi kullanilmiyorsa
                        {
                            hakedisKontrol = false;
                            hakedisVerildiMiKontrol = true;
                        }
                    }
                    projeleriOku.close();
                    //Hakedisi verilmemisse ekrana uyari yazdir
                    if (hakedisVerildiMiKontrol == false)
                    {
                        cout << endl
                             << "Bu projenin hakedisi verilmemistir!" << endl
                             << endl;
                        devamMi = false;
                    }
                    // Proje numarasi kullaniilmiyorsa uyari yazdir
                    if (hakedisKontrol == false)
                    {
                        cout << endl
                             << "Bu proje numarasi kullanilmamaktadir lutfen baska bir proje numarasi giriniz" << endl
                             << endl;
                        devamMi = false;
                    }
                    
                    //Eger projenin hakedisi verildiyse devam et
                    if (devamMi == true)
                    {
                        int hakedisSecim2 = 0;
                        //Projenin hakedisi ile ilgili islemlerin yapilabilecegi menu ve secim islemi icin gerekli olan dongu
                        do
                        {
                            cout << "1) Kullanilan urunleri, adetlerini ve fiyatlarini listele" << endl;
                            cout << "2) Kullanilan urunleri sil" << endl;
                            cout << "3) Kullanilan urunleri guncelle" << endl;
                            cout << "4) Kullanilan urun ara" << endl;
                            cout << "5) Hakedis donemine gore kullanilan urunlerin listesi ve tutarini gor" << endl;
                            cout << "6) Geri Don" << endl;
                            cout << "Seciminiz  :   ";
                            cin >> hakedisSecim2;
                            cout << endl;
                            //Eger hakedisSecim2 1 ise projede kullanilan urunleri, adetlerini ve fiyatlarini listele
                            if (hakedisSecim2 == 1)
                            {
                                int kontrolIcinProjeNo;
                                int urunNo;
                                int urunAdedi;
                                int urunFiyati;
                                int hakedisDonemi;
                                cout << endl
                                     << hakedisProjeNo << " numarali proje icin kullanilan urunler listesi   :" << endl
                                     << endl;

                                ifstream dosyaOku;
                                dosyaOku.open("Hakedisler.txt", ios::in);
                                //Dosyanin sonuna kadar okuma yap
                                while (!dosyaOku.eof())
                                {
                                    dosyaOku >> kontrolIcinProjeNo >> urunNo >> urunAdedi >> urunFiyati >> hakedisDonemi;
                                    //Eger girilen proje no ile hakedisler dosyasindaki proje no eslesirse urunleri yazdir.
                                    if (hakedisProjeNo == kontrolIcinProjeNo)
                                    {
                                        cout << "Urun Numarasi : " << urunNo << " | Urun Adedi : " << urunAdedi << " | Urun Fiyati : " << urunFiyati << " | Hakedis Donemi : " << hakedisDonemi << endl;
                                    }
                                }
                                dosyaOku.close();
                            }
                            //Eger hakedisSecim2 2 ise kullanilan urunleri sil bloguna gir
                            else if (hakedisSecim2 == 2)
                            {
                                int kontrolIcinProjeNo;
                                int silinecekUrunNo;
                                int urunNo;
                                int urunAdedi;
                                int urunFiyati;
                                int hakedisDonemi;
                                cout << "Hakedisten silmek istediginiz urun numarasini giriniz  :   ";
                                cin >> silinecekUrunNo;

                                ifstream hakedisleriOku("Hakedisler.txt");
                                ofstream geciciDosyaYaz("Hakedisler.tmp");
                                //Dosyanin sonuna kadar okuma yap
                                while (hakedisleriOku >> kontrolIcinProjeNo >> urunNo >> urunAdedi >> urunFiyati >> hakedisDonemi)
                                {
                                    //Eger girilen proje no ile hakedisler dosyasindaki proje esleselirse if'in icine gir
                                    if (projeNo == kontrolIcinProjeNo)
                                    {
                                        //Eger girilen urunNo ile silinecek olan urun no eslesirse bir sey yapma yani sil
                                        if (urunNo == silinecekUrunNo)
                                        {
                                        }
                                        else //eslesmezse ayni sekilde yazdir
                                        {
                                            geciciDosyaYaz << "\n"
                                                           << kontrolIcinProjeNo << " " << urunNo << " " << urunAdedi << " " << urunFiyati << " " << hakedisDonemi;
                                        }
                                    }
                                    else //eslesmezse ayni sekilde yazdir
                                    {
                                        geciciDosyaYaz << "\n"
                                                       << kontrolIcinProjeNo << " " << urunNo << " " << urunAdedi << " " << urunFiyati << " " << hakedisDonemi;
                                    }
                                }

                                hakedisleriOku.close();
                                geciciDosyaYaz.close();
                                remove("Hakedisler.txt");
                                rename("Hakedisler.tmp", "Hakedisler.txt");

                                cout << endl
                                     << "Hakedisten urun silindi!" << endl;
                            }
                            //Eger hakedisSecim2 3 ise hakedis guncelleme bloguna gir
                            else if (hakedisSecim2 == 3)
                            {
                                int kontrolIcinProjeNo;
                                int guncellenecekUrunNo;
                                int urunNo;
                                int urunAdedi;
                                int urunFiyati;
                                int hakedisDonemi;
                                cout << "Hakedisten guncellemek istediginiz urun numarasini giriniz  :   ";
                                cin >> guncellenecekUrunNo;

                                ifstream hakedisleriOku("Hakedisler.txt");
                                ofstream geciciDosyaYaz("Hakedisler.tmp");
                                //Dosyayi sonuna kadar oku
                                while (hakedisleriOku >> kontrolIcinProjeNo >> urunNo >> urunAdedi >> urunFiyati >> hakedisDonemi)
                                {
                                    //eger girilen proje no ile hakedisler dosyasindaki proje no ayni ise if'in icine gir
                                    if (projeNo == kontrolIcinProjeNo)
                                    {
                                        //girilen urun no ile hakedisler dosyasindaki urun no eslesirse guncelleme yap
                                        if (urunNo == guncellenecekUrunNo)
                                        {
                                            cout << "Urun Adedi Giriniz     :   ";
                                            cin >> urunAdedi;
                                            cout << "Urun Fiyati Giriniz    :   ";
                                            cin >> urunFiyati;
                                            cout << "Hakedis Donemi Giriniz :   ";
                                            cin >> hakedisDonemi;
                                            geciciDosyaYaz << "\n"
                                                           << kontrolIcinProjeNo << " " << urunNo << " " << urunAdedi << " " << urunFiyati << " " << hakedisDonemi;
                                        }
                                        else //eslesmezse degistirmeden yazdir
                                        {
                                            geciciDosyaYaz << "\n"
                                                           << kontrolIcinProjeNo << " " << urunNo << " " << urunAdedi << " " << urunFiyati << " " << hakedisDonemi;
                                        }
                                    }
                                    else //eslesmezse degistirmeden yazdir
                                    {
                                        geciciDosyaYaz << "\n"
                                                       << kontrolIcinProjeNo << " " << urunNo << " " << urunAdedi << " " << urunFiyati << " " << hakedisDonemi;
                                    }
                                }

                                hakedisleriOku.close();
                                geciciDosyaYaz.close();
                                remove("Hakedisler.txt");
                                rename("Hakedisler.tmp", "Hakedisler.txt");

                                cout << endl
                                     << "Hakedisten urun guncellendi!" << endl;
                            }
                            //Eger hakedisSecim2 4 ise hakedisten urun arama bloguna gir
                            else if (hakedisSecim2 == 4)
                            {
                                int projeNo3;
                                int urunNo;
                                int urunAdedi;
                                int urunFiyati;
                                int hakedisDonemi;
                                int aranacakUrunNo;
                                bool aramaKontrol = false;
                                string urunAdi;
                                string urunBirimi;
                                int urunBirimFiyati;
                                string urunMarkasi;
                                cout << endl
                                     << "Aramak istediginiz urun numarasini giriniz   :   ";
                                cin >> aranacakUrunNo;
                                ifstream hakedisleriOku("Hakedisler.txt");
                                //Dosyayi sonuna kadar oku
                                while (hakedisleriOku >> projeNo3 >> urunNo >> urunAdedi >> urunFiyati >> hakedisDonemi)
                                {
                                    //Eger urunno ile aranan urunno eslesirse aramaKontrol'u true yap ve donguyu kir
                                    if (urunNo == aranacakUrunNo)
                                    {
                                        aramaKontrol = true;
                                        break;
                                    }
                                }
                                hakedisleriOku.close();

                                ifstream urunleriOku("Urunler.txt");
                                //Dosyayi sonuna kadar oku
                                while (urunleriOku >> urunNo >> urunAdi >> urunBirimi >> urunBirimFiyati >> urunMarkasi)
                                {
                                    //Eger aranan urunno ile urunler dosyasindaki urunno eslesirse donguyu kir
                                    if (urunNo == aranacakUrunNo)
                                    {
                                        break;
                                    }
                                }
                                urunleriOku.close();
                                //Arama kontrol true ise aranan urunun bilgilerini yazdir
                                if (aramaKontrol == true)
                                {
                                    cout << "Urun No    :   " << urunNo << endl;
                                    cout << "Urun Adedi    :   " << urunAdedi << endl;
                                    cout << "Hakedisteki Urun Fiyati    :   " << urunFiyati << endl;
                                    cout << "Hakedis Donemi    :   " << hakedisDonemi << endl;
                                    cout << "Urun Adi    :   " << urunAdi << endl;
                                    cout << "Urun Birimi    :   " << urunBirimi << endl;
                                    cout << "Urun Birim Fiyati    :   " << urunBirimFiyati << endl;
                                    cout << "Urun Markasi    :   " << urunMarkasi << endl;
                                }
                                //Degilse urun bulunmamaktadir uyarisini yazdir
                                else
                                {
                                    cout << endl
                                         << "Bu urun numarasinda bir urun bulunmamaktadir!" << endl;
                                }
                            }
                            //Eger hakedisSecim2 5 ise projenin hakedis donemine gore kullanilan urunleri ve fiyatlarini yazdiran bloga gir
                            else if (hakedisSecim2 == 5)
                            {
                                int kontrolProjeNo;
                                int urunNo;
                                int urunAdedi;
                                int urunFiyati;
                                int hakedisDonemi;
                                int birinciHakedisDonemi = 0;
                                int ikinciHakedisDonemi = 0;
                                int ucuncuHakedisDonemi = 0;
                                ifstream dosyaOku;
                                dosyaOku.open("Hakedisler.txt", ios::in);
                                //Dosyanin sonuna kadar okuma yap
                                while (!dosyaOku.eof())
                                {
                                    dosyaOku >> kontrolProjeNo >> urunNo >> urunAdedi >> urunFiyati >> hakedisDonemi;
                                    //Eger girilen projeno ile hakedisler dosyasindaki projeno eslesirse if'in icine gir
                                    if (hakedisProjeNo == kontrolProjeNo)
                                    {
                                        //Hakedis Donemi 1 olan urunleri yazdir ve toplam fiyatlarini hesapla
                                        if (hakedisDonemi == 1)
                                        {
                                            cout << "1. Hakedis doneminde " << urunNo << " numarali urun " << urunAdedi << " tane kullanilmistir ve birim fiyati " << urunFiyati << " birim fiyattir" << endl
                                                 << endl;
                                            birinciHakedisDonemi += (urunAdedi * urunFiyati);
                                        }
                                        //Hakedis Donemi 2 olan urunleri yazdir ve toplam fiyatlarini hesapla
                                        else if (hakedisDonemi == 2)
                                        {
                                            cout << "2. Hakedis doneminde " << urunNo << " numarali urun " << urunAdedi << " tane kullanilmistir ve birim fiyati " << urunFiyati << " birim fiyattir" << endl
                                                 << endl;
                                            ikinciHakedisDonemi += (urunAdedi * urunFiyati);
                                        }
                                        //Hakedis Donemi 3 olan urunleri yazdir ve toplam fiyatlarini hesapla
                                        else if (hakedisDonemi == 3)
                                        {
                                            cout << "3. Hakedis doneminde " << urunNo << " numarali urun " << urunAdedi << " tane kullanilmistir ve birim fiyati " << urunFiyati << " birim fiyattir" << endl
                                                 << endl;
                                            ucuncuHakedisDonemi += (urunAdedi * urunFiyati);
                                        }
                                    }
                                }
                                dosyaOku.close();
                                cout << endl
                                     << "1. Hakedis donemi toplam tutari    :   " << birinciHakedisDonemi;
                                cout << endl
                                     << "-------------";
                                cout << endl
                                     << "2. Hakedis donemi toplam tutari    :   " << ikinciHakedisDonemi;
                                cout << endl
                                     << "-------------";
                                cout << endl
                                     << "3. Hakedis donemi toplam tutari    :   " << ucuncuHakedisDonemi;
                                cout << endl
                                     << endl;
                            }

                        } while (hakedisSecim2 != 6);
                    }
                }
                //Eger hakedisSecim 3 ise butun projelerin secilen hakedis donemine gore toplam birim fiyatlarini yazdir.
                else if (hakedisSecim == 3)
                {
                    int hakedisSayisi = hakedisSayisiAl();
                    int projeNo;
                    int urunNo;
                    int urunAdedi;
                    int urunFiyati;
                    int hakedisDonemi;
                    int toplam = 0;
                    int kontrolIcinHakedisDonemi;

                    cout << endl
                         << "Hakedis donemi giriniz(1,2,3) :   ";
                    cin >> hakedisDonemi;

                    ifstream dosyaOku;
                    dosyaOku.open("Hakedisler.txt", ios::in);
                    //Dosyayi sonuna kadar oku
                    while (!dosyaOku.eof())
                    {
                        dosyaOku >> projeNo >> urunNo >> urunAdedi >> urunFiyati >> kontrolIcinHakedisDonemi;
                        //Eger hakedisdonemi aranan hakedis donemi ile eslesirse toplam fiyati hesaplayip arttir
                        if (hakedisDonemi == kontrolIcinHakedisDonemi)
                        {
                            toplam += (urunAdedi * urunFiyati);
                        }
                    }
                    dosyaOku.close();

                    cout << endl
                         << hakedisDonemi << ". hakedis donemi icin projelerin toplam hakedis tutari   : " << toplam << " birim fiyattir." << endl
                         << endl;
                }

            } while (hakedisSecim != 4);
        }
    } while (secim != 4);
}