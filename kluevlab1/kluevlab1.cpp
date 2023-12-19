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
        cout << "\n�������� ���� ������!" << endl;
        cout << "������� ����� �� " << x << " �� " << y << endl;
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

    cout << "������� �������� �����: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, truba.name_tr);

    cout << "������� ����� �����: ";
    truba.dlina_tr = Proverka(0, INT_MAX);

    cout << "������� ������� �����: ";
    truba.diameter_tr = Proverka(0, INT_MAX);

    cout << "�������� �����? (1-��, 0-���): " << endl;
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
        cout << "����� � �������? (0 - ���, 1 - ��)";
        cin >> inrep;
        truba.in_remont_tr = inrep;
    }
    else {
        cout << "����� �� �������" << endl;

    }
}

void KSInfo(KS& ks) {
    setlocale(LC_ALL, "ru");
    cout << "������� �������� ��: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, ks.name_ks);

    cout << "������� ���������� �����: ";
    ks.kolvo_tzehov_ks = Proverka(0, 50);

    cout << "������� ���������� �����, ������� ��������: ";
    ks.tzeh_rabota_ks = Proverka(0, 50);

    cout << "��������� ���������� ���? (0-33%,1-66%,2-100%) " << endl;
    ks.effect_ks = Proverka(0, 2);
    ks.flag_ks = 1;
    }

void startWork(KS& ks) {
    if (ks.kolvo_tzehov_ks < ks.tzeh_rabota_ks) {
        ks.kolvo_tzehov_ks++;
        cout << "��� ������� ����� ��������" << endl;
    }
    else {
        cout << "��� ���� ��� � ������" << endl;
    }
}

void stopWork(KS& ks) {
    if (ks.kolvo_tzehov_ks > 0) {
        ks.kolvo_tzehov_ks--;
        cout << "��� ����������" << endl;
    }
    else {
        cout << "��� ����� � ������" << endl;
    }
}

void SaveInfo(Truba& truba, KS& ks) {
    ofstream fout;
    //if (truba.flag_tr == 1 && ks.flag_ks == 1) {
        fout.open("save_info.txt", ios::out);
        if (fout.is_open()) {
            if (truba.name_tr.size() != 0) {
                fout << "�����" << endl;
                fout << truba.name_tr << endl << truba.dlina_tr << endl << truba.diameter_tr << endl << truba.in_remont_tr << endl;
            }
            else {
                cout << "�� ������� ������� ����" << endl;
            }
            if (ks.name_ks.size() != 0) {
                fout << "KS" << endl;
                fout << ks.name_ks << endl << ks.kolvo_tzehov_ks << endl << ks.tzeh_rabota_ks << endl << ks.effect_ks << endl;
            }
            else {
                cout << "�� ������� ������� ����" << endl;
            }
        }
        fout.close();
        if (truba.name_tr.size() == 0 && ks.name_ks.size() == 0) {
            cout << "������� ������ ��� ����������" << endl;
        }
        else {
            cout << "������ ������� ���������" << endl;
        }
}

void LoadInfo(Truba& truba, KS& ks) {
    string line;
    ifstream file("save_info.txt");
    if (file.is_open()) {
        getline(file, line);
        if (line == "�����") {
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
            cout << "������ ������� ���������" << endl;
        }
        else if (line == "KS") {
            getline(file, ks.name_ks);

            getline(file, line);
            ks.kolvo_tzehov_ks = stoi(line);

            getline(file, line);
            ks.tzeh_rabota_ks = stoi(line);

            getline(file, line);
            ks.effect_ks = stoi(line);
            cout << "������ ������� ���������" << endl;
        }
        else {
            cout << "�� ������� ������� ����" << endl;
        }
        file.close();
    }
}


void PrintTruba(Truba& truba) {
    cout << "�����: " << truba.name_tr << endl;
    cout << "�����: " << truba.dlina_tr << endl;
    cout << "�������: " << truba.diameter_tr << endl;
    cout << "������: " << (truba.in_remont_tr ? "true" : "false") << endl;
}

void PrintKS(KS& ks) {
    cout << "��: " << ks.name_ks << endl;
    cout << "���������� �����: " << ks.kolvo_tzehov_ks << endl;
    cout << "���������� ����� � ������: " << ks.tzeh_rabota_ks << endl;
    cout << "�������������: " << ks.effect_ks << endl;
}

void ViewAllObjects(Truba& truba,KS&ks) {
    if (truba.load_tr == 1 && ks.load_ks == 1) {
        while (true) {
            cout << "0. �����\n" <<
                "1. �������� �����\n" <<
                "2. �������� ��" << endl;
            switch (Proverka(0, 2)) {
            case 1: {
                if (truba.flag_tr == 1) {
                    PrintTruba(truba);
                    break;
                }
                else {
                    cout << "����� �� ���������" << endl;
                }
            case 2: {
                if (ks.flag_ks == 1) {
                    PrintKS(ks);
                    break;
                }
                else {
                    cout << "�� �� ���������" << endl;
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
        cout << "�� ��� �� ���������/��������� ������" << endl;
    }
 }
    




int main() {

    setlocale(LC_ALL, "ru");

    Truba truba;
    KS ks;

    while (true) {
        cout << "\n1. �������� �����\n" <<
            "2. �������� ��\n" <<
            "3. �������� ���� ��������\n" <<
            "4. ������������� �����\n" <<
            "5. ������������� ��\n" <<
            "6. ���������\n" <<
            "7. ���������\n" <<
            "0. �����\n" << endl;

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
                    cout << "1. ��������� ���" << endl;
                    cout << "2. ���������� ���" << endl;
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



