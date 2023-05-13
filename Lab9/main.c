#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // ������ ��� ����� ���������
    char output[100] = ""; // ������ ��� ������ ����������
    char *token; // ��������� �� ������� �����

    printf("������� ���������: ");
    fgets(input, 100, stdin); // ��������� ������ � �������

    token = strtok(input, "+- "); // �������� ������ �����

    // ��������� ������ ����� � ������ ������
    strcat(output, token);

    while (token != NULL) {
        token = strtok(NULL, "+- "); // �������� ��������� �����

        if (token != NULL) {
            // ���� ����� - �������� "+", "-", �� ��������� ������ � ��� �������� � ���������
            if (strcmp(token, "+") == 0) {
                strcat(output, " + ");
            } else if (strcmp(token, "-") == 0) {
                strcat(output, " - ");
            }
            // ����� ��������� ������ � �������
            else {
                strcat(output, " ");
                strcat(output, token);
            }
        }
    }

    printf("���������: %s\n", output);


	
	
	
	
	/*
    double result = 0; // ��������� ����������
    double operand; // ������� �������

    token = strtok(output, " "); // �������� ������ �����

    // �������������� ��������� ������ ���������
    sscanf(token, "%lf", &result);

    while (token != NULL) {
        token = strtok(NULL, " "); // �������� ��������� �����

        if (token != NULL) {
            // ���� ����� - �������� "+", �� ��������� ��������
            if (strcmp(token, "+") == 0) {
                token = strtok(NULL, " "); // �������� ��������� �����
                sscanf(token, "%lf", &operand);
                result += operand;
            }
            // ���� ����� - �������� "-", �� ��������� ���������
            else if (strcmp(token, "-") == 0) {
                token = strtok(NULL, " "); // �������� ��������� �����
                sscanf(token, "%lf", &operand);
                result -= operand;
            }
        }
    }

    printf("Result: %lf\n", result);
*/
    return 0;
}
