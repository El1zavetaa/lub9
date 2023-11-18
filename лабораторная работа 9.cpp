#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    time_t currentTime = time(0);

    // открывает файл для записи логов
    ofstream logFile("log.txt");
    // проверяет, удалось ли открыть файл
    if (!logFile.is_open()) {
        cout << "Ошибка открытия файла логов!" << endl;
        return 1;
    }
    // генератор случайных чисел
    srand(time(0));
    // спрашиваем у пользователя число бочонков
    int N;
    cout << "Введите натуральное число N (число бочонков): ";
    cin >> N;
    char* timeString = ctime(&currentTime);
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1, '\n');
        cout << "Ошибка данных!" << endl << endl;
        logFile << "Ошибка данных!" << endl <<  "Время выполнения запроса: " << timeString << endl;
        return 0;
    }
    // выводим данные в лог файл
    logFile << "Введенное число бочонков: " << endl << N << endl << "Время выполнения запроса: " << timeString << endl;

    // создание массива чисел от 1 до N
    int* numbers = new int[N];
    for (int i = 0; i < N; i++) {
        numbers[i] = i + 1;
    }

    // пока есть элементы в массиве, вытаскиваем бочонки
    cout << "Последовательность выпавших чисел на бочонках: " << endl;
    logFile << "Последовательность выпавших чисел на бочонках: " << endl;
    while (N > 0) {
        int index = rand() % N;
        // выводит число и удаляет его из массива
        char* timeString = ctime(&currentTime);
        getchar();
        cout << numbers[index];
        logFile << numbers[index] << endl << "Время выполнение запроса: " << timeString << endl;
        // удаляет элемент из массива, сдвигая остальные элементы
        for (int i = index; i < N - 1; i++) {
            numbers[i] = numbers[i + 1];
        }
        N--;
    }
    cout << endl;

    // закрывает файл логов
    logFile.close();

    return 0;
}