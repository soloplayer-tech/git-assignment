#include <iostream>
using namespace std;

// 포션 세팅 (call by pointer)
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main() {
    const int SIZE = 4;
    int status[SIZE] = { 0 }; // [0]=HP, [1]=MP, [2]=공격력, [3]=방어력
    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    // HP, MP 입력
    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];
        if (status[0] > 50 && status[1] > 50) break;
        cout << "HP나 MP가 50 이하입니다. 다시 입력해주세요." << endl;
    }

    // 공격력, 방어력 입력
    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];
        if (status[2] > 0 && status[3] > 0) break;
        cout << "공격력이나 방어력이 0 이하입니다. 다시 입력해주세요." << endl;
    }

    // 포션 지급
    setPotion(5, &HPPotion, &MPPotion);
    cout << "* HP, MP 포션 각각 5개 지급되었습니다." << endl;

    // 스탯 관리 시스템
    while (true) {
        cout << "\n<스탯 관리 시스템>" << endl;
        cout << "1. HP 회복 (포션 사용)" << endl;
        cout << "2. MP 회복 (포션 사용)" << endl;
        cout << "3. HP 강화 (2배 증가)" << endl;
        cout << "4. MP 강화 (2배 증가)" << endl;
        cout << "5. 공격 스킬 사용 (MP 50 소모)" << endl;
        cout << "6. 필살기 사용 (현재 MP 50% 소모)" << endl;
        cout << "7. 프로그램 종료" << endl;

        cout << "번호 선택: ";
        cin >> choice;

        if (choice == 7) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        switch (choice) {
        case 1: // HP 회복
            if (HPPotion <= 0) {
                cout << "HP 포션이 없습니다!" << endl;
            }
            else {
                status[0] += 20;
                HPPotion--;
                cout << "* HP가 20 회복되었습니다. 남은 HP 포션: " << HPPotion << endl;
                cout << "현재 HP: " << status[0] << endl;
            }
            break;

        case 2: // MP 회복
            if (MPPotion <= 0) {
                cout << "MP 포션이 없습니다!" << endl;
            }
            else {
                status[1] += 20;
                MPPotion--;
                cout << "* MP가 20 회복되었습니다. 남은 MP 포션: " << MPPotion << endl;
                cout << "현재 MP: " << status[1] << endl;
            }
            break;

        case 3: // HP 강화
            status[0] *= 2;
            cout << "* HP가 2배로 강화되었습니다. 현재 HP: " << status[0] << endl;
            break;

        case 4: // MP 강화
            status[1] *= 2;
            cout << "* MP가 2배로 강화되었습니다. 현재 MP: " << status[1] << endl;
            break;

        case 5: // 공격 스킬
            if (status[1] < 50) {
                cout << "MP가 부족하여 공격 스킬을 사용할 수 없습니다!" << endl;
            }
            else {
                status[1] -= 50;
                cout << "* 공격 스킬 사용! MP 50 소모. 남은 MP: " << status[1] << endl;
            }
            break;

        case 6: // 필살기
            if (status[1] <= 0) {
                cout << "MP가 부족하여 필살기를 사용할 수 없습니다!" << endl;
            }
            else {
                int usedMP = status[1] / 2;
                status[1] -= usedMP;
                cout << "* 필살기 사용! MP " << usedMP << " 소모. 남은 MP: " << status[1] << endl;
            }
            break;

        default:
            cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
            break;
        }
    }

    return 0;
}
