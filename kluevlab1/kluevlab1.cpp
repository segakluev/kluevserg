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
int flag_ks = 0;
int flag_tr = 0;

struct Truba {
    string name_tr;
    double dlina_tr;
    int diameter_tr;
    bool in_remont_tr;
};

struct KS {
    string name_ks;
    int kolvo_tzehov_ks;
    int tzeh_rabota_ks;
    int effect_ks;
};

int TrubaInfo(Truba& truba) {
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
    flag_tr = 1;
    return flag_tr;
}

int KSInfo(KS& ks) {
    setlocale(LC_ALL, "ru");
    cout << "������� �������� �����: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    getline(cin, ks.name_ks);

    cout << "������� ���������� �����: ";
    ks.kolvo_tzehov_ks = Proverka(0, 50);

    cout << "������� ���������� �����, ������� ��������: ";
    ks.tzeh_rabota_ks = Proverka(0, 50);

    cout << "��������� ���������� ���? (0-33%,1-66%,2-100%) " << endl;
    ks.effect_ks = Proverka(0, 2);
    flag_ks = 1;
    return flag_ks;
    }

void SaveInfo(Truba& truba, KS& ks) {
    ofstream fout;
    if (flag_tr == 1 && flag_ks == 1) {
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
            case 6:
                SaveInfo(truba, ks);
                break;

        }
    }
    return 0;
}



