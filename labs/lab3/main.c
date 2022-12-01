#include <stdio.h>
#include <string.h>

#include "lab3.h"

typedef enum
{
    E_INVALID = 0,
    E_ADD_GROUP,
    E_ADD_STUDENT,
    E_DEL_GROUP,
    E_DEL_STUDENT,
    E_PRINT_UNI,
    E_PRINT_GROUP,
    E_PRINT_STUDENT,
    E_END
} EAction;

const char *Enum2Str(EAction eAct)
{
    switch (eAct)
    {
        case E_INVALID:
            return "- Невалидная команда";
        case E_ADD_GROUP:
            return "- Добавить группу";
        case E_ADD_STUDENT:
            return "- Добавить студента";
        case E_DEL_GROUP:
            return "- Удалить группу";
        case E_DEL_STUDENT:
            return "- Удалить студента";
        case E_PRINT_UNI:
            return "- Напечатать информацию об университете";
        case E_PRINT_GROUP:
            return "- Напечатать информацию о группе";
        case E_PRINT_STUDENT:
            return "- Напечатать информацию о студенте";
        case E_END:
            return "- Окончание работы";
        default:
            return "? - Невалидная команда";
    }
}

int main(int argc, char* argv[])
{
    // Проверка аргументов командной строки, если не заданы - ввод с клавиатуры

    // Инициализация университета файлом с заданным путем

    EAction eAction = E_INVALID;
    while (eAction != E_END)
    {
        // вывод списка всех возможных команд - код команды и текст из Enum2Str

        // ввод кода команды пользователем

        switch (eAction)
        {
            // обработка каждой команды и действие по ней
            // при необходимости - получение данных от пользователя
        }
    }

    // сохранение данных в файл
    return 0;
}
