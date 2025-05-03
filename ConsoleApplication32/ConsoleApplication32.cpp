#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція логування
void log(const string& message) {
    ofstream file("game_log.txt", ios::app);
    file << "[LOG] " << message << endl;
}

int main() {
    system("chcp 1251>null");
    srand(time(0));
    int number = rand() % 100 + 1;
    string user_guess;

    cout << "🎲 Я загадав число від 1 до 100." << endl;
    cout << "Як ти думаєш, воно парне чи непарне? (введи: parne / neparne): ";
    cin >> user_guess;

    log("Користувач ввів: " + user_guess);
    try {
        if (user_guess != "parne" && user_guess != "neparne") {
            throw invalid_argument("Має бути 'parne' або 'neparne'.");
        }

        bool is_even = number % 2 == 0;
        bool user_is_right = (is_even && user_guess == "parne") || (!is_even && user_guess == "neparne");

        cout << "🔢 Загадане число: " << number << endl;
        if (user_is_right) {
            cout << "✅ Правильно! Ти вгадав!" << endl;
            log("Користувач вгадав.");
        }
        else {
            cout << "❌ Неправильно! Спробуй ще." << endl;
            log("Користувач не вгадав.");
        }

    }
    catch (const exception& e) {
        cout << "❌ Помилка: " << e.what() << endl;
        log("Помилка: " + string(e.what()));
    }

    log("Гра завершена.\n");
    return 0;
}
