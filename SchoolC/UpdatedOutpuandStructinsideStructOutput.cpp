#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	int hours;
	int minutes;
	char shift[2];
}TIME;

typedef struct 
{
    int month;
    int day;
    int year;
}DATE;



typedef struct
{
	char firstName[20];
	char middleInitial[5];
	char lastName[20];
}NAME;

typedef struct
{
char compCode[20];
TIME timeIn;
TIME timeOut;
TIME duration;
TIME res;
DATE date;
float amount;
float temp;


}COMPRENTAL;

typedef struct
{   NAME name;
    char studentId[20];
    char clss[10];
    int year;
    int section;
    COMPRENTAL compRental[30];
    float total;
	
}PROFILE;



void ProfileInput(PROFILE* _profile, int timesRented);

COMPRENTAL ComputerRentalInput(COMPRENTAL _compRental);

COMPRENTAL ComputeTime(COMPRENTAL timeProfile);

COMPRENTAL ComputeDuration(COMPRENTAL duration);

void PrintSummaryOfComputerRental(PROFILE* _profile,int timesRented);

void PrintComputerUsage(COMPRENTAL _compRental);


int main(void)
{
    int timesRented;
    printf("Please enter the number of computer rentals: ");
    scanf("%d",&timesRented);
    PROFILE student;

    ProfileInput(&student,timesRented);
    PrintSummaryOfComputerRental(&student,timesRented);
}


void ProfileInput(PROFILE* _profile, int timesRented)
{
    printf("Enter student name: \n");

    printf("First Name: ");
    scanf(" %[^\n]s",&_profile->name.firstName);

        printf("Middle Initial: ");
    scanf(" %[^\n]s",&_profile->name.middleInitial);

        printf("Last Name: ");
    scanf(" %[^\n]s",&_profile->name.lastName);

        printf("Enter student ID: ");
    scanf(" %[^\n]s",&_profile->studentId);
        
        printf("Enter Class, Year, & Section: ");
    scanf(" %s %d %d",&_profile->clss,&_profile->year,&_profile->section);

        printf("\n\n\t\t Computer Rental Information");
   
   
    for(int i = 0; i <timesRented;i++)
    {
      _profile->compRental[i] =  ComputerRentalInput(_profile->compRental[i]);
      _profile->total = _profile->total + _profile->compRental[i].amount;
		
    }

    
    



}


COMPRENTAL ComputerRentalInput(COMPRENTAL _compRental)
{
    printf("\n\nEnter Computer Code: ");
    scanf(" %[^\n]s",&_compRental.compCode);

    printf("Enter Time In  (HH MM AM/PM): ");
    scanf(" %d %d %s",&_compRental.timeIn.hours, 
                      &_compRental.timeIn.minutes, &_compRental.timeIn.shift);
    
        printf("Enter Time Out (HH MM AM/PM): ");
    scanf(" %d %d %s",&_compRental.timeOut.hours, 
                      &_compRental.timeOut.minutes, &_compRental.timeOut.shift);

        printf("Enter Date  (MM DD YYYY): ");
    scanf(" %d %d %d",&_compRental.date.month,
                      &_compRental.date.day, &_compRental.date.year);

    _compRental = ComputeTime(_compRental);
    _compRental = ComputeDuration(_compRental);
                      

 return _compRental;

}

    //Time Computation Algo
COMPRENTAL ComputeTime(COMPRENTAL timeProfile)
{
	// if opening = 12
	if(timeProfile.timeIn.hours == 12)
		{
			timeProfile.timeIn.hours=0;
		}

    // if closing is PM
	if(strcmp(timeProfile.timeOut.shift,"PM")==0)
	{
		if(timeProfile.timeOut.hours  == 12)
		{
			timeProfile.timeOut.hours = 12;
		}
		else
		timeProfile.timeOut.hours += 12;
	}

    else if(strcmp(timeProfile.timeIn.shift,"PM")==0)
	{
		if(timeProfile.timeIn.hours  == 12)
		{
			timeProfile.timeIn.hours = 12;
		}
		else
		timeProfile.timeIn.hours += 12;
	}

      // Nilagay ko dito kasi i-military time muna then minus na etc.
	timeProfile.res.hours = timeProfile.timeOut.hours - timeProfile.timeIn.hours;

    // MIN opening < closing 60-closing
	if(timeProfile.timeIn.minutes < timeProfile.timeOut.minutes)
		{
			timeProfile.res.minutes = 60 - timeProfile.timeOut.minutes;
		}

	// MIN opening > closing 60-opening then minus 1 hr
	else if(timeProfile.timeIn.minutes > timeProfile.timeOut.minutes)
		{
			timeProfile.res.minutes = 60 - timeProfile.timeIn.minutes + timeProfile.timeOut.minutes;
			timeProfile.res.hours   = timeProfile.res.hours - 1;
		}
    else
		{
			timeProfile.res.minutes=0;
		}
    

        return timeProfile;
}

    //Amount Computation Algo
COMPRENTAL ComputeDuration(COMPRENTAL duration)
{
		//_profile->temp
    //1 hr = 15 pesos 30 mn add 10 pesos
    duration.amount = duration.res.hours * 15;
    if (duration.res.minutes>=30)
    	{
    		duration.temp=10;
		}
	else
		{
			duration.temp=0;
		}
		
	duration.amount = duration.amount + duration.temp;

    return duration;
}



//TODO: Edit parameters inside the Printfs
void PrintSummaryOfComputerRental(PROFILE* _profile,int timesRented)
{
    system("CLS");
    
    printf("\nComputer Rentals\n\n");
	for(int i = 0 ; i< timesRented;i++)
	{
		PrintComputerUsage(_profile->compRental[i]);
	}
    
    printf("\n\n\n\t\t\tSummary of Computer Usage\n\n");
    printf("Student Name: %s %s. %s\n",_profile->name.firstName,_profile->name.middleInitial,_profile->name.lastName);
    printf("Student Id  : %s\n",_profile->studentId);
    printf("Class, Year & Section: %s %d-%d\n",_profile->clss,_profile->year,_profile->section);

    printf("\n\tDate\t\tDuration\tAmount\n");

    for(int i = 0; i <timesRented;i++)
    {
        printf("\t%d-%d-%d\t%02d:%02d\t\t  %f\n",_profile->compRental[i].date.month,_profile->compRental[i].date.day,
                                               _profile->compRental[i].date.year,_profile->compRental[i].res.hours,
                                               _profile->compRental[i].res.minutes,_profile->compRental[i].amount);
    }    
      printf("\t_____________________________________\n");
    printf("\t\t\t\t   Total: %f",_profile->total);
}

void PrintComputerUsage(COMPRENTAL _compRental)
{
	   
    
        printf("\nComputer Code: %s\n",_compRental.compCode);

        printf("Time in: %02d:%02d %s\n",_compRental.timeIn.hours, 
                                     _compRental.timeIn.minutes, _compRental.timeIn.shift);

        printf("Time Out: %02d:%02d %s\n",_compRental.timeOut.hours, 
                                      _compRental.timeOut.minutes, _compRental.timeOut.shift);
        
        printf("Date: %02d-%02d-%04d",_compRental.date.month,
                                _compRental.date.day, _compRental.date.year);
    
    
}


