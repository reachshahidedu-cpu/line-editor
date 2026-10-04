#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char document[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

void insertLine()
{
    int lineNumber;
    char text[MAX_LENGTH];

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';

    for (int i = lineCount; i >= lineNumber; i--)
    {
        strcpy(document[i], document[i - 1]);
    }

    strcpy(document[lineNumber - 1], text);
    lineCount++;

    printf("Line inserted successfully.\n");
}

void deleteLine()
{
    int lineNumber;

    printf("Enter line number: ");
    scanf("%d", &lineNumber);

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(document[i], document[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}

void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n--- Document ---\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, document[i]);
    }

    printf("----------------\n");
}

int main()
{
    char command[20];

    printf("Simple Line Editor\n");
    printf("Commands: insert, delete, display, quit\n");

    while (1)
    {
        printf("\nEnter command: ");
        scanf("%19s", command);

        if (strcmp(command, "insert") == 0)
        {
            insertLine();
        }
        else if (strcmp(command, "delete") == 0)
        {
            deleteLine();
        }
        else if (strcmp(command, "display") == 0)
        {
            displayDocument();
        }
        else if (strcmp(command, "quit") == 0)
        {
            printf("Exiting editor.\n");
            break;
        }
        else
        {
            printf("Unknown command.\n");
        }
    }

    return 0;
}