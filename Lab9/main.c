#include <stdio.h>
#include <string.h>

int main() {
    char expression[100];
    printf("Insert: ");
    fgets(expression, 100, stdin);
    char new_expression[100] = "";
    int j = 0;
    int i = 0;
    
    for(i = 0; i < strlen(expression); i++) {
        if(expression[i] == '+') {
            if(i > 0 && expression[i-1] != ' ' && expression[i-1] != '+') {
                new_expression[j++] = ' ';
            }
            new_expression[j++] = '+';
            if(i < strlen(expression)-1 && expression[i+1] != ' ' && expression[i+1] != '+') {
                new_expression[j++] = ' ';
            }
        } else {
            new_expression[j++] = expression[i];
        }
    }

	char input[100] = "";
	j = 0;
    i = 0;
    
    for(i = 0; i < strlen(new_expression); i++) {
        if(new_expression[i] == '-') {
            if(i > 0 && new_expression[i-1] != ' ' && new_expression[i-1] != '-') {
                input[j++] = ' ';
            }
            input[j++] = '-';
            if(i < strlen(new_expression)-1 && new_expression[i+1] != ' ' && new_expression[i+1] != '-') {
                input[j++] = ' ';
            }
        } else {
            input[j++] = new_expression[i];
        }
    }
    
	if(input[0] == '-' || input[0] == '+') {
		i = 0;
    	for (i=strlen(input)-1;i>=0;i--)
    		input[i+1] = input[i];
		input[0]=' ';	
		i = 0;
    	for (i=strlen(input)-1;i>=0;i--)
    		input[i+1] = input[i];
		input[0]='0';	
		}	
		
	printf("Primer: %s\n", input);
	
	/*
		-125.6 +2 -2+4 - 2+ 2 +0.1 -2-6.7
	*/
	
	char *token;
    double result = 0;
    double operand;
	
 	token = strtok(input, " "); 
	sscanf(token, "%lf", &result);

    while (token != NULL) {
        token = strtok(NULL, " "); 

        if (token != NULL) {

            if (strcmp(token, "+") == 0) {
                token = strtok(NULL, " "); 
                sscanf(token, "%lf", &operand);
                result += operand;
            }
          
            else if (strcmp(token, "-") == 0) {
                token = strtok(NULL, " ");
                sscanf(token, "%lf", &operand);
                result -= operand;
            }

        }
    }

    printf("Answer: %lf\n", result);

    return 0;
}

