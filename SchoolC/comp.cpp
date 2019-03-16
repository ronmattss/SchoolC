#include <stdio.h>
#include <string.h>
#include <ctype.h>




typedef struct
{
    char code[20];
    int timeInHours;
    int timeInMinutes;
    int timeOutHours;
    int timeOutMinutes;
    int timeConsumedHours;
    int timeConsumedMinutes;

}PROPERTY;
//This program doesn't need array of structs since the data will be stored on a File.

const char format[100]  = " %s %02d %02d %02d %02d %02d %02d\n";
const char format2[100] = " %s %02d%02d %02d%02d %02d%02d\n";
int CheckIfHourIsCorrect(int timeH);
int CheckIfMinuteIsCorrect(int timeM);
PROPERTY ComputeTimeConsumed(PROPERTY prop);
PROPERTY AddRecords(PROPERTY prop);
void AddComps(PROPERTY compRent,FILE *comp,char path[50]);
void EditComputerRental(FILE *file,FILE *tfile,char path[50],char tPath[50]);
void EditRecord(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50]);
void DeleteRecord(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50]);
void SubMenu(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50]);
void EditRecords();
void DeleteRecords();
void MainMenu(int choice,PROPERTY prop,FILE *file,FILE *tFile,char path[50],char tPath[50],PROPERTY comp);


int main(void)
{
  FILE *comp;
  FILE *tComp;
  PROPERTY compRental;  
  int input;
  char path[50]  =  "Record.txt";
  char tPath[50] = "tRecord.txt";
 printf("Choose what to do: ");
 scanf("%d",&input);

  MainMenu(input,compRental,comp,tComp,path,tPath,compRental);


    //menu function
    //TODO: make a menu
}

PROPERTY AddRecords(PROPERTY prop)
{
    printf("Enter Record: \n");
    printf("Enter Computer Code: ");
    scanf("%s",&prop.code);
    printf("Enter Time In (HH MM): ");
    scanf("%d %d",&prop.timeInHours,&prop.timeInMinutes);
    prop.timeInHours = CheckIfHourIsCorrect(prop.timeInHours);
    prop.timeInMinutes = CheckIfMinuteIsCorrect(prop.timeInMinutes);
    printf("Enter Time Out (HH MM): ");
    scanf("%d %d",&prop.timeOutHours,&prop.timeOutMinutes);
    prop.timeOutHours = CheckIfHourIsCorrect(prop.timeOutHours);
    prop.timeOutMinutes = CheckIfMinuteIsCorrect(prop.timeOutMinutes);
    prop = ComputeTimeConsumed(prop);
    return prop;
}

PROPERTY EditRecords(PROPERTY prop)
{
    printf("Enter Record: \n");
    printf("Enter Computer Code: ");
    scanf("%s",&prop.code);
    printf("Enter Time In (HH MM): ");
    scanf("%d %d",&prop.timeInHours,&prop.timeInMinutes);
    prop.timeInHours = CheckIfHourIsCorrect(prop.timeInHours);
    prop.timeInMinutes = CheckIfMinuteIsCorrect(prop.timeInMinutes);
    printf("Enter Time Out (HH MM): ");
    scanf("%d %d",&prop.timeOutHours,&prop.timeOutMinutes);
    prop.timeOutHours = CheckIfHourIsCorrect(prop.timeOutHours);
    prop.timeOutMinutes = CheckIfMinuteIsCorrect(prop.timeOutMinutes);
    prop = ComputeTimeConsumed(prop);
    return prop;
}
// add time equation 
void AddComps(PROPERTY compRent,FILE *comp,char path[50])
{
    comp = fopen(path,"a");
    compRent = AddRecords(compRent);
    printf(format2,compRent.code,compRent.timeInHours,compRent.timeInMinutes,compRent.timeOutHours,compRent.timeOutMinutes,compRent.timeConsumedHours,compRent.timeConsumedMinutes);
    fprintf(comp,format,compRent.code,compRent.timeInHours,compRent.timeInMinutes,compRent.timeOutHours,compRent.timeOutMinutes,compRent.timeConsumedHours,compRent.timeConsumedMinutes);
    fclose(comp);
    //fprintf();   
}

int CheckIfHourIsCorrect(int timeH)
{
    if(timeH> 23 || timeH<0)
    {
      printf("please Re-enter Hour: ");
      scanf("%d",&timeH);
        if(timeH> 23 || timeH<0)
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
    if(timeM> 60 || timeM<0)
    {
      printf("please Re-enter Minutes: ");
      scanf("%d",&timeM);
        if(timeM> 60 || timeM<0)
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
    if(prop.timeInHours < prop.timeOutHours)
    {
      prop.timeConsumedHours = prop.timeOutHours - prop.timeInHours;
    }
    else
    {
        tempValue = prop.timeInHours - prop.timeOutHours;
        prop.timeConsumedHours = 24 - tempValue;
    }

    
    if(prop.timeInMinutes < prop.timeOutMinutes)
    {
        
      prop.timeConsumedMinutes = prop.timeOutMinutes - prop.timeOutMinutes;

    }
    else
    {
        tempValue = prop.timeInMinutes - prop.timeOutMinutes;
        if(prop.timeOutMinutes != prop.timeInMinutes)
        {
        prop.timeConsumedMinutes = 60 - tempValue;
        prop.timeConsumedHours   = prop.timeConsumedHours - 1;
             
        }
        else
        {
            prop.timeConsumedMinutes = prop.timeOutMinutes - prop.timeInMinutes;   
        }
    }    
return prop;
}


void EditComputerRental(FILE *file,FILE *tfile,char path[50],char tPath[50])
{ char compCode[50];
    PROPERTY tProp;
    printf("Enter Computer Code:");
    scanf(" %s",&compCode);
    file =fopen(path,"r");
    tfile=fopen(tPath,"a");
    int choice;
    int counter = 0;
    char yn; 

  



     while (fscanf(file, format, &tProp.code, &tProp.timeInHours, &tProp.timeInMinutes, &tProp.timeOutHours, &tProp.timeOutMinutes, &tProp.timeConsumedHours, &tProp.timeConsumedMinutes)!= EOF)
        {       	
                 
		  if(strcmp(compCode,tProp.code)== 0)
          {

            printf("Computer Code Found!\n");
            printf("What do you want to do?\n");
            printf("[1] Edit Record\n[2]Delete Record");
            scanf("%d",&choice);
            SubMenu(choice,file,tfile,path,tPath,tProp,compCode);
          	counter = 1;
		  }
          else
          {

          }

                
        }
         if(counter == 0)
         {
            printf("No Computer Code Found!\n");
            printf("Search for another Code? (y/n):");
            scanf("%c",&yn);
            if(toupper(yn)=='Y')
            {
                EditComputerRental(file,tfile,path,tPath);
            }
            else
            {
                printf("Going back to menu");
               //getchar();
                main();
            }
            
         }
   


    //search
}



void SubMenu(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50])
{
    switch (choices)
    {
        case 1:
          EditRecord(choices,file,tfile,path,tPath,comp,code);  
            break;
        case 2:
          DeleteRecord(choices,file,tfile,path,tPath,comp,code); 
        break;
        default:
            break;
    }
    
}

void DeleteRecord(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50])
{   char yn;
    fclose(file);
    fclose(tfile);
    file = fopen(path,"r");
    tfile = fopen(tPath,"w");
      while(fscanf(file, format, &comp.code, &comp.timeInHours, &comp.timeInMinutes, &comp.timeOutHours, &comp.timeOutMinutes, &comp.timeConsumedHours, &comp.timeConsumedMinutes)!= EOF)
  {
      if(strcmp(comp.code,code)== 0)
      {
          
          printf(format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
           printf("\nDo you want to delete this record?\n"); 
           scanf(" %c",&yn);
           if(yn == 'y')
           {
             printf("\n deleting...");
           }
           else
           {
            fprintf(tfile,format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
           }
           
      }
    else
      {
          fprintf(tfile,format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
      }      
  }
fclose(file);
fclose(tfile);
remove(path);
rename(tPath,path);
    
}

void EditRecord(int choices,FILE *file,FILE *tfile,char path[50],char tPath[50],PROPERTY comp,char code[50])
{   fclose(file);
    fclose(tfile);
    file = fopen(path,"r");
    tfile = fopen(tPath,"w");
  while(fscanf(file, format, &comp.code, &comp.timeInHours, &comp.timeInMinutes, &comp.timeOutHours, &comp.timeOutMinutes, &comp.timeConsumedHours, &comp.timeConsumedMinutes)!= EOF)
  {
      if(strcmp(comp.code,code)== 0)
      {
        printf("Edit %s\n",code);
        printf("Enter new Time In (HH MM): ");
        scanf("%d %d",&comp.timeInHours,&comp.timeInMinutes);
        comp.timeInHours = CheckIfHourIsCorrect(comp.timeInHours);
        comp.timeInMinutes = CheckIfMinuteIsCorrect(comp.timeInMinutes);
        printf("Enter new Time Out (HH MM): ");
        scanf("%d %d",&comp.timeOutHours,&comp.timeOutMinutes);
        comp.timeOutHours = CheckIfHourIsCorrect(comp.timeOutHours);
        comp.timeOutMinutes = CheckIfMinuteIsCorrect(comp.timeOutMinutes);
        comp = ComputeTimeConsumed(comp);
        fprintf(tfile,format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
      }
      else
      {
          fprintf(tfile,format, comp.code, comp.timeInHours, comp.timeInMinutes, comp.timeOutHours, comp.timeOutMinutes, comp.timeConsumedHours, comp.timeConsumedMinutes);
      }      
  }

  fclose(file);
  fclose(tfile);
 remove(path);
  rename(tPath,path);
}

void MainMenu(int choice,PROPERTY prop,FILE *file,FILE *tFile,char path[50],char tPath[50],PROPERTY comp)
{
    

    switch (choice)
    {
        case 1:
       AddComps(prop,file,path);
            break;
        case 2:
        EditComputerRental(file,tFile,path,tPath);
        break;
        case 3:
        // function Delete;
        break;
        case 4:
        // function exit;
        break;    
        default:
        // function reenter
            break;
    }
}



