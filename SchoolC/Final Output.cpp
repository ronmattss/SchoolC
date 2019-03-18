/*
Pagulayan, John Clarence
Rivera, Ron Matthew
BSCS 1-1
Gr.3        3-18-19
Activity: Computer Record Rental


*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    char code[20];
    int timeInHours;
    int timeInMinutes;
    int timeOutHours;
    int timeOutMinutes;
    int timeConsumedHours;
    int timeConsumedMinutes;

} PROPERTY;
//This program doesn't need array of structs since the data will be stored on a File.

// constant variables for String formats only: Usage printf(format,.....); or fprintf(file,format,.....);
const char format[100] = " %s %02d %02d %02d %02d %02d %02d\n";  // for fprintf/fscanf
const char format2[100] = " %s %02d%02d %02d%02d %02d%02d\n";    // for monitor output
const char format3[100] = "  %s\t%02d%02d\t%02d%02d\t%02d%02d\n"; // for printing in a list

// As the description says
int CheckIfHourIsCorrect(int timeH);
int CheckIfMinuteIsCorrect(int timeM);

PROPERTY ComputeTimeConsumed(PROPERTY prop);
PROPERTY AddRecords(PROPERTY prop);
PROPERTY EditData(PROPERTY prop);

void AddData(PROPERTY compRent, FILE *comp, char path[50]);
void SearchRecord(FILE *file, FILE *tfile, char path[50], char tPath[50]);

void EditRecord(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50]);
void DeleteRecord(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50]);

// Menu for Edit/Delete and the Main Menu
void SubMenu(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50]);
void MainMenu(int choice, PROPERTY prop, FILE *file, FILE *tFile, char path[50], char tPath[50], PROPERTY comp);
//As The name says
void DisplayRecords();

int main(void)
{
    system("CLS");
    FILE *comp;
    FILE *tComp;
    PROPERTY compRental;

    int input;
    char path[50] = "Record.txt";
    char tPath[50] = "tRecord.txt";

    DisplayRecords();
    printf("\nMain Menu\n[1]Add Record\n[2]Search Record\n[3]Exit Program\n");
    printf("Choose what to do: ");
    scanf(" %d", &input);

    MainMenu(input, compRental, comp, tComp, path, tPath, compRental);

    //menu function
    //TODO: make a menu
    //Record List???
}

PROPERTY AddRecords(PROPERTY prop)
{
    printf("Enter Record: \n");
    printf("Enter Computer Code: ");
    scanf(" %s", &prop.code);
    printf("Enter Time In (HH MM): ");
    scanf(" %d %d", &prop.timeInHours, &prop.timeInMinutes);
    prop.timeInHours = CheckIfHourIsCorrect(prop.timeInHours);
    prop.timeInMinutes = CheckIfMinuteIsCorrect(prop.timeInMinutes);
    printf("Enter Time Out (HH MM): ");
    scanf(" %d %d", &prop.timeOutHours, &prop.timeOutMinutes);
    prop.timeOutHours = CheckIfHourIsCorrect(prop.timeOutHours);
    prop.timeOutMinutes = CheckIfMinuteIsCorrect(prop.timeOutMinutes);
    prop = ComputeTimeConsumed(prop);
    return prop;
}

PROPERTY EditData(PROPERTY prop)
{
    printf("Enter new Time In (HH MM): ");
    scanf(" %d %d", &prop.timeInHours, &prop.timeInMinutes);
    prop.timeInHours = CheckIfHourIsCorrect(prop.timeInHours);
    prop.timeInMinutes = CheckIfMinuteIsCorrect(prop.timeInMinutes);
    printf("Enter new Time Out (HH MM): ");
    scanf(" %d %d", &prop.timeOutHours, &prop.timeOutMinutes);
    prop.timeOutHours = CheckIfHourIsCorrect(prop.timeOutHours);
    prop.timeOutMinutes = CheckIfMinuteIsCorrect(prop.timeOutMinutes);
    prop = ComputeTimeConsumed(prop);
    return prop;
}
// add time equation
void AddData(PROPERTY compRent, FILE *comp, char path[50])
{
    comp = fopen(path, "a");
    char answer;
    compRent = AddRecords(compRent);
    printf(format2, compRent.code, compRent.timeInHours, compRent.timeInMinutes, compRent.timeOutHours, compRent.timeOutMinutes, compRent.timeConsumedHours, compRent.timeConsumedMinutes);
    fprintf(comp, format, compRent.code, compRent.timeInHours, compRent.timeInMinutes, compRent.timeOutHours, compRent.timeOutMinutes, compRent.timeConsumedHours, compRent.timeConsumedMinutes);
    fclose(comp);
    printf("Do you want to add another record? (y/n)");
    scanf(" %c", &answer);
    if (tolower(answer) == 'y')
    {
        AddData(compRent, comp, path);
    }
    else
    {
        main();
    }
    //fprintf();
}

int CheckIfHourIsCorrect(int timeH)
{
    if (timeH > 23 || timeH < 0)
    {
        printf("please Re-enter Hour: ");
        scanf(" %d", &timeH);
        if (timeH > 23 || timeH < 0)
        {
            CheckIfHourIsCorrect(timeH);
        }
        else
        {
            return timeH;
        }
    }
    else
    {
        return timeH;
    }
}

int CheckIfMinuteIsCorrect(int timeM)
{
    if (timeM > 59 || timeM < 0)
    {
        printf("please Re-enter Minutes: ");
        scanf("%d", &timeM);
        if (timeM > 59 || timeM < 0)
        {
            CheckIfMinuteIsCorrect(timeM);
        }
        else
        {
            return timeM;
        }
    }
    else
    {
        return timeM;
    }
}

PROPERTY ComputeTimeConsumed(PROPERTY prop)
{
    int tempValue;
    if (prop.timeInHours < prop.timeOutHours)
    {
        prop.timeConsumedHours = prop.timeOutHours - prop.timeInHours;
    }
    else
    {
        tempValue = prop.timeInHours - prop.timeOutHours;
        prop.timeConsumedHours = 24 - tempValue;
    }

    if (prop.timeInMinutes < prop.timeOutMinutes)
    {

        prop.timeConsumedMinutes = prop.timeOutMinutes - prop.timeInMinutes;
    }
    else
    {
        tempValue = prop.timeInMinutes - prop.timeOutMinutes;
        if (prop.timeOutMinutes != prop.timeInMinutes)
        {
            prop.timeConsumedMinutes = 60 - tempValue;
            prop.timeConsumedHours = prop.timeConsumedHours - 1;
        }
        else
        {
            prop.timeConsumedMinutes = prop.timeOutMinutes - prop.timeInMinutes;
        }
    }
    return prop;
}

void SearchRecord(FILE *file, FILE *tfile, char path[50], char tPath[50])
{
    system("CLS");
    DisplayRecords();
    char compCode[50];
    PROPERTY tProp;
    printf("Enter Computer Code:");
    scanf(" %s", &compCode);
    file = fopen(path, "r");
    tfile = fopen(tPath, "a");
    int choice;
    int counter = 0;
    char yn;

    while (fscanf(file, format, &tProp.code, &tProp.timeInHours, &tProp.timeInMinutes, &tProp.timeOutHours, &tProp.timeOutMinutes, &tProp.timeConsumedHours, &tProp.timeConsumedMinutes) != EOF)
    {

        if (strcmp(compCode, tProp.code) == 0)
        {

            printf("Computer Code Found!\n");
            printf("PC Code\tTimeIn\tTimeOut\tConsumed\n");
            printf(format3, tProp.code, tProp.timeInHours, tProp.timeInMinutes, tProp.timeOutHours, tProp.timeOutMinutes, tProp.timeConsumedHours, tProp.timeConsumedMinutes);
            printf("What do you want to do?\n");
            printf("[1]Edit Record\n[2]Delete Record\n[3]Main Menu");
            scanf(" %d", &choice);
            SubMenu(choice, file, tfile, path, tPath, tProp, compCode);
            counter = 1;
        }
        else
        {
        }
    }
    if (counter == 0)
    {
        printf("No Computer Code Found!\n");
        printf("Search for another Code? (y/n):");
        scanf(" %c", &yn);
        if (toupper(yn) == 'Y')
        {
            SearchRecord(file, tfile, path, tPath);
        }
        else
        {
            printf("Going back to menu");
            //getchar();
            //  delay(1000);
            main();
        }
    }

    //search
}

void SubMenu(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50])
{
    switch (choices)
    {
    case 1:
        EditRecord(choices, file, tfile, path, tPath, comp, code);
        break;
    case 2:
        DeleteRecord(choices, file, tfile, path, tPath, comp, code);
        break;
    case 3:
        main();
        break;
    default:
        SubMenu(choices, file, tfile, path, tPath, comp, code);
        break;
    }
}

void DeleteRecord(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50])
{
    char yn;
    fclose(file);
    fclose(tfile);
    file = fopen(path, "r");
    tfile = fopen(tPath, "w");
    while (fscanf(file, format, &comp.code, &comp.timeInHours, &comp.timeInMinutes, &comp.timeOutHours, &comp.timeOutMinutes, &comp.timeConsumedHours, &comp.timeConsumedMinutes) != EOF)
    {
        if (strcmp(comp.code, code) == 0)
        {

            printf(format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
            printf("\nDo you want to delete this record?(y/n)\n");
            scanf(" %c", &yn);
            if (tolower(yn) == 'y')
            {
                printf("\n deleting...\n");
                printf(format2, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
            }
            else
            {
                fprintf(tfile, format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
                printf("Search another Record?");
                scanf(" %c", &yn);
                if (tolower(yn))
                {
                    SubMenu(choices, file, tfile, path, tPath, comp, code);
                }
                else
                {
                    main();
                }
            }
        }
        else
        {
            fprintf(tfile, format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
        }
    }
    fclose(file);
    fclose(tfile);
    remove(path);
    rename(tPath, path);
    main();
}

void EditRecord(int choices, FILE *file, FILE *tfile, char path[50], char tPath[50], PROPERTY comp, char code[50])
{
    char yn;
    fclose(file);
    fclose(tfile);
    file = fopen(path, "r");
    tfile = fopen(tPath, "w");
    while (fscanf(file, format, &comp.code, &comp.timeInHours, &comp.timeInMinutes, &comp.timeOutHours, &comp.timeOutMinutes, &comp.timeConsumedHours, &comp.timeConsumedMinutes) != EOF)
    {
        if (strcmp(comp.code, code) == 0)
        {
            printf("Edit %s\n", code);
            comp = EditData(comp);
            printf("New Record\n");
            printf(format3, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
            getch();
            fprintf(tfile, format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
        }
        else
        {
            fprintf(tfile, format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
        }
    }

    fclose(file);
    fclose(tfile);
    remove(path);
    rename(tPath, path);
    main();
}

void DisplayRecords()
{
    PROPERTY tProp;
    FILE *file;
    char path[50] ="Record.txt";
    file = fopen(path, "r");
    printf("\n Computer Rental Records\n\n");
    printf("PC Code\tTimeIn\tTimeOut\tTime Consumed\n");
    while (fscanf(file, format, &tProp.code, &tProp.timeInHours, &tProp.timeInMinutes, &tProp.timeOutHours, &tProp.timeOutMinutes, &tProp.timeConsumedHours, &tProp.timeConsumedMinutes) != EOF)
    {
        printf(format3, tProp.code, tProp.timeInHours, tProp.timeInMinutes, tProp.timeOutHours, tProp.timeOutMinutes, tProp.timeConsumedHours, tProp.timeConsumedMinutes);
    }
    printf("\n\n");
    fclose(file);
}

void MainMenu(int choice, PROPERTY prop, FILE *file, FILE *tFile, char path[50], char tPath[50], PROPERTY comp)
{

    switch (choice)
    {
    case 1:
        AddData(prop, file, path);
        break;
    case 2:
        SearchRecord(file, tFile, path, tPath);
        break;
    case 3:
        exit(0);
        break;
    default:
        main();
        break;
    }
}
