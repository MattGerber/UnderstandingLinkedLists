#include "stdio.h"
#include "string.h"
#include "stdlib.h"
/*

    car 1 -> next is car 2
    car 2 -> next is car 3
    car 3 -> next is car 4
    car 4 -> next is NULL
 */
typedef struct s_racingCar
{
	char	name[12];
	int		speed;
    struct  s_racingCar *next;
    struct  s_racingCar *previous;

}	RacingCar;

void    Printlist(RacingCar *start)
{
    RacingCar   *currentCar = start;
    int         count = 0;

    RacingCar   *carhead = NULL;
    RacingCar   *carbehind = NULL;

    while (currentCar != NULL)
    {
        count++;

        carhead = currentCar->next;
        carbehind = currentCar->previous;

        printf("car:%d Name:%s Speed:%d Ahead:%s Behind:%s\n", count,
        currentCar->name, 
        currentCar->speed,
        (carhead == NULL)?"None" : carhead->name,
        (carbehind == NULL)?"None" : carbehind->name);
        currentCar = currentCar->next;
        carhead = NULL;
        carbehind = NULL;
    }
    printf("Total Cars:%d\n", count);
}

RacingCar    *MakeNewCar()
{
    printf("Enter Name and speed:");
	char input[16];
	fgets(input, 15, stdin);

    RacingCar *newCar = malloc(sizeof(RacingCar));
    sscanf(input, "%s %d", newCar->name, &newCar->speed);
    printf("Added:%s Speed:%d\n\n", newCar->name, newCar->speed);

    newCar->next = NULL;
    newCar->previous = NULL;

    return (newCar);
}

RacingCar *AddToStart(RacingCar *startPtr)
{
    RacingCar  *newCar = MakeNewCar();
    if (startPtr != NULL)
    {
        startPtr -> previous = newCar;
        newCar->next = startPtr;
    }
    return(newCar);
}

RacingCar *AddToEnd(RacingCar *startPtr)
{
    RacingCar *retptr = startPtr;
    RacingCar *newCar = NULL;
    RacingCar *indexcar = startPtr;
    
    if(startPtr == NULL)
    {
        newCar = AddToStart(startPtr);
        retptr = newCar;
    }
    else
    {
        while (indexcar->next != NULL)
            indexcar = indexcar->next;
        newCar = MakeNewCar();
        indexcar->next = newCar;
        newCar->next = NULL;
        newCar->previous = indexcar;
    }
    return (retptr);
}


void    CleanUp(RacingCar *start)
{
    RacingCar *freeme = start;
    RacingCar *Hold = NULL;

    while (freeme != NULL)
    {
        Hold = freeme->next;
        printf("Free Name:%s Speed:%d\n", freeme->name, freeme->speed);
        free(freeme);
        freeme = Hold;
    }
}

int		    main()
{
	char command[16];
	char input[16];

    RacingCar *start = NULL;
    // RacingCar *start = NULL; (heve end with big list)

	while (fgets(input, 15, stdin))
	{
		sscanf(input, "%s", command);
		if (strncmp(command, "quit", 4) == 0) 
		{
			printf("\n\nBreaking..\n");
			break ;
		}
		else if (strncmp(command, "print", 5) == 0)
        {
            Printlist(start);
        }
		else if (strncmp(command, "addstart", 8) == 0)
        {
            start = AddToStart(start);
        }	
        else if (strncmp(command, "addend", 6) == 0)
        {
            start = AddToEnd(start); 
        }	
	}
    CleanUp(start);
    /*
    add first
        start = Car1
        newest = Car1

    add 2nd
        start = Car1->next = Car2;
        newest = Car2
     */

	return 0;
}