#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int Proverka(int x, int y) {
    int chislo;
    while ((cin >> chislo).fail()
        || cin.peek() != '\n'
        || chislo < x || chislo > y)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nНеверный ввод данных!" << endl;
        cout << "Введите число от " << x << " до " << y << endl;
    }
    return chislo;
}


struct Truba {
    string name_tr;
    double dlina_tr;
    int diameter_tr;
    bool in_remont_tr;
    int flag_tr;
    int load_tr;
};

struct KS {
    string name_ks;
    int kolvo_tzehov_ks;
    int tzeh_rabota_ks;
    int effect_ks;
    int flag_ks;
    int load_ks;
};

void TrubaInfo(Truba& truba) {
    setlocale(LC_ALL, "ru");

    cout << "Введите название трубы: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, truba.name_tr);

    cout << "Введите длину трубы: ";
    truba.dlina_tr = Proverka(0, INT_MAX);

    cout << "Введите диаметр трубы: ";
    truba.diameter_tr = Proverka(0, INT_MAX);

    cout << "Работает труба? (1-да, 0-нет): " << endl;
    if (Proverka(0, 1)) {
        truba.in_remont_tr = true;
    }
    else {
        truba.in_remont_tr = false;
    }
    truba.flag_tr = 1;
}

void KSInfo(KS& ks) {
    setlocale(LC_ALL, "ru");
    cout << "Введите название КС: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, ks.name_ks);

    cout << "Введите количество цехов: ";
    ks.kolvo_tzehov_ks = Proverka(0, 50);

    cout << "Введите количество цехов, которые работают: ";
    ks.tzeh_rabota_ks = Proverka(0, 50);

    cout << "Насколько эффективен цех? (0-33%,1-66%,2-100%) " << endl;
    ks.effect_ks = Proverka(0, 2);
    ks.flag_ks = 1;
    }

void SaveInfo(Truba& truba, KS& ks) {
    ofstream fout;
    if (truba.flag_tr == 1 && ks.flag_ks == 1) {
        fout.open("save_info.txt", ios::out);
        if (fout.is_open()) {
            fout << "Труба" << endl;
            fout << truba.name_tr << endl << truba.dlina_tr << endl << truba.diameter_tr << endl << truba.in_remont_tr << endl;
            fout << "KS" << endl;
            fout << ks.name_ks << endl << ks.kolvo_tzehov_ks << endl << ks.tzeh_rabota_ks << endl << ks.effect_ks << endl;
            fout.close();
        }
    }
    else{
        cout << "Вы добавили не все объекты" << endl;
    }
}

void LoadInfo(Truba& truba, KS& ks) {
    ifstream fin;
    if (truba.flag_tr == 1 && ks.flag_ks == 1) {
        fin.open("save_info.txt", ios::in);
        if (fin.is_open()) {
            fin >> truba.name_tr;

            fin >> truba.dlina_tr;
            fin >> truba.diameter_tr;
            fin >> truba.in_remont_tr;
            fin >> ks.name_ks;
            fin >> ks.kolvo_tzehov_ks;
            fin >> ks.tzeh_rabota_ks;
            fin >> ks.effect_ks;
            fin.close();
            truba.load_tr = 1;
            ks.load_ks = 1;
        }

    }
    else {
        cout << "Нечего загружать" << endl;
    }
    
}


void PrintTruba(Truba& truba) {
    cout << "Труба: " << truba.name_tr << endl;
    cout << "Длина: " << truba.dlina_tr << endl;
    cout << "Диаметр: " << truba.diameter_tr << endl;
    cout << "Работа: " << (truba.in_remont_tr ? "true" : "false") << endl;
}

void PrintKS(KS& ks) {
    cout << "КС: " << ks.name_ks << endl;
    cout << "Количество цехов: " << ks.kolvo_tzehov_ks << endl;
    cout << "Количество цехов в работе: " << ks.tzeh_rabota_ks << endl;
    cout << "Эффективность: " << ks.effect_ks << endl;
}

void ViewAllObjects(Truba& truba,KS&ks) {
    if (truba.load_tr == 1 && ks.load_ks == 1) {
        while (true) {
            cout << "0. Назад\n" <<
                "1. Просмотр трубы\n" <<
                "2. Просмотр КС" << endl;
            switch (Proverka(0, 2)) {
            case 1: {
                if (truba.flag_tr == 1) {
                    PrintTruba(truba);
                    break;
                }
                else {
                    cout << "Труба не добавлена" << endl;
                }
            case 2: {
                if (ks.flag_ks == 1) {
                    PrintKS(ks);
                    break;
                }
                else {
                    cout << "КС не добавлена" << endl;
                    break;
                }
            case 0:
                return;
            }

            }
            }


        }
    }
    else {
        cout << "Вы ещё не сохранили данные" << endl;
    }
 }
    




int main() {

    setlocale(LC_ALL, "ru");

    Truba truba;
    KS ks;

    while (true) {
        cout << "\n1. Добавить трубу\n" <<
            "2. Добавить КС\n" <<
            "3. Просмотр всех объектов\n" <<
            "4. Редактировать трубу\n" <<
            "5. Редактировать КС\n" <<
            "6. Сохранить\n" <<
            "7. Загрузить\n" <<
            "0. Выход\n" << endl;

        switch (Proverka(0, 7)) {

            case 1:
                TrubaInfo(truba);
                break;
            case 2:
                KSInfo(ks);
                break;
            case 3:
                ViewAllObjects(truba,ks);
                break;
           case 6:
                SaveInfo(truba, ks);
                break;
           case 7:
               LoadInfo(truba,ks);
               break;

        }
    }
    return 0;
}



