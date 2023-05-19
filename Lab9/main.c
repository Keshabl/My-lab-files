#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // строка для ввода выражения
    char output[100] = ""; // строка для вывода результата
    char *token; // указатель на текущий токен

    printf("Введите выражение: ");
    fgets(input, 100, stdin); // считываем строку с консоли

    token = strtok(input, "+- "); // получаем первый токен

    // добавляем первый токен в строку вывода
    strcat(output, token);

    while (token != NULL) {
        token = strtok(NULL, "+- "); // получаем следующий токен

        if (token != NULL) {
            // если токен - оператор "+", "-", то добавляем пробел и сам оператор с пробелами
            if (strcmp(token, "+") == 0) {
                strcat(output, " + ");
            } else if (strcmp(token, "-") == 0) {
                strcat(output, " - ");
            }
            // иначе добавляем пробел и операнд
            else {
                strcat(output, " ");
                strcat(output, token);
            }
        }
    }

    printf("Результат: %s\n", output);


	
	
	
	
	/*
    double result = 0; // результат вычислений
    double operand; // текущий операнд

    token = strtok(output, " "); // получаем первый токен

    // инициализируем результат первым операндом
    sscanf(token, "%lf", &result);

    while (token != NULL) {
        token = strtok(NULL, " "); // получаем следующий токен

        if (token != NULL) {
            // если токен - оператор "+", то выполняем сложение
            if (strcmp(token, "+") == 0) {
                token = strtok(NULL, " "); // получаем следующий токен
                sscanf(token, "%lf", &operand);
                result += operand;
            }
            // если токен - оператор "-", то выполняем вычитание
            else if (strcmp(token, "-") == 0) {
                token = strtok(NULL, " "); // получаем следующий токен
                sscanf(token, "%lf", &operand);
                result -= operand;
            }
        }
    }

    printf("Result: %lf\n", result);
*/
    return 0;
}
