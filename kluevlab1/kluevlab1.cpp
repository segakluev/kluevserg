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

void SaveInfo(Truba& truba, KS& ks) {
    ofstream fout;
    if (truba.flag_tr == 1 && ks.flag_ks == 1) {
        fout.open("save_info.txt", ios::out);
        if (fout.is_open()) {
            fout << "�����" << endl;
            fout << truba.name_tr << endl << truba.dlina_tr << endl << truba.diameter_tr << endl << truba.in_remont_tr << endl;
            fout << "KS" << endl;
            fout << ks.name_ks << endl << ks.kolvo_tzehov_ks << endl << ks.tzeh_rabota_ks << endl << ks.effect_ks << endl;
            fout.close();
        }
    }
    else{
        cout << "�� �������� �� ��� �������" << endl;
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
        cout << "������ ���������" << endl;
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
        cout << "�� ��� �� ��������� ������" << endl;
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



