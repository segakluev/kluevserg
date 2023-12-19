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


void EditTruba(Truba& truba) {
    if (truba.name_tr.size() != 0) {
        bool inrep = false;
        cout << "Труба в ремонте? (0 - Нет, 1 - Да)";
        cin >> inrep;
        truba.in_remont_tr = inrep;
    }
    else {
        cout << "Трубы не найдены" << endl;

    }
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

void startWork(KS& ks) {
    if (ks.kolvo_tzehov_ks < ks.tzeh_rabota_ks) {
        ks.kolvo_tzehov_ks++;
        cout << "Цех успешно начал работать" << endl;
    }
    else {
        cout << "Все цехи уже в работе" << endl;
    }
}

void stopWork(KS& ks) {
    if (ks.kolvo_tzehov_ks > 0) {
        ks.kolvo_tzehov_ks--;
        cout << "Цех остановлен" << endl;
    }
    else {
        cout << "Нет цехов в работе" << endl;
    }
}

void SaveInfo(Truba& truba, KS& ks) {
    ofstream fout;
    //if (truba.flag_tr == 1 && ks.flag_ks == 1) {
        fout.open("save_info.txt", ios::out);
        if (fout.is_open()) {
            if (truba.name_tr.size() != 0) {
                fout << "Труба" << endl;
                fout << truba.name_tr << endl << truba.dlina_tr << endl << truba.diameter_tr << endl << truba.in_remont_tr << endl;
            }
            else {
                cout << "Не удалось открыть файл" << endl;
            }
            if (ks.name_ks.size() != 0) {
                fout << "KS" << endl;
                fout << ks.name_ks << endl << ks.kolvo_tzehov_ks << endl << ks.tzeh_rabota_ks << endl << ks.effect_ks << endl;
            }
            else {
                cout << "Не удалось открыть файл" << endl;
            }
        }
        fout.close();
        if (truba.name_tr.size() == 0 && ks.name_ks.size() == 0) {
            cout << "Введите данные для сохранения" << endl;
        }
        else {
            cout << "Данные успешно сохранены" << endl;
        }
}

void LoadInfo(Truba& truba, KS& ks) {
    string line;
    ifstream file("save_info.txt");
    if (file.is_open()) {
        getline(file, line);
        if (line == "Труба") {
            getline(file, truba.name_tr);

            getline(file, line);
            truba.dlina_tr = stoi(line);

            getline(file, line);
            truba.diameter_tr = stoi(line);

            getline(file, line);
            truba.in_remont_tr = stoi(line);

            getline(file, line);
            if (line == "KS") {
                getline(file, ks.name_ks);

                getline(file, line);
                ks.kolvo_tzehov_ks = stoi(line);

                getline(file, line);
                ks.tzeh_rabota_ks = stoi(line);

                getline(file, line);
                ks.effect_ks = stoi(line);
            }
            cout << "Данные успешно загружены" << endl;
        }
        else if (line == "KS") {
            getline(file, ks.name_ks);

            getline(file, line);
            ks.kolvo_tzehov_ks = stoi(line);

            getline(file, line);
            ks.tzeh_rabota_ks = stoi(line);

            getline(file, line);
            ks.effect_ks = stoi(line);
            cout << "Данные успешно загружены" << endl;
        }
        else {
            cout << "Не удалось открыть файл" << endl;
        }
        file.close();
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
        cout << "Вы ещё не сохранили/загрузили данные" << endl;
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
            case 4:
                EditTruba(truba);
                break;
            case 5:
                if (ks.name_ks.size() != 0) {
                    int choice;
                    cout << "1. Запустить цех" << endl;
                    cout << "2. Остановать цех" << endl;
                    cin >> choice;
                    Proverka(1, 2);
                    switch (choice) {
                    case 1: {
                        startWork(ks);
                        break;
                    }
                    case 2: {
                        stopWork(ks);
                        break;
                    }
                    }
                }
           case 6:
                SaveInfo(truba, ks);
                break;
           case 7:
               LoadInfo(truba,ks);
               break;
           case 0:
               return 0;
               break;

        }
    }
    return 0;
}



