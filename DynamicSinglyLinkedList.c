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

}	RacingCar;

void    Printlist(RacingCar *start)
{
    RacingCar   *currentCar = start;
    int         count = 0;

    while (currentCar != NULL)
    {
        count++;
        printf("car:%d Name:%s Speed:%d\n", count,
        currentCar->name, currentCar->speed);
        currentCar = currentCar->next;
    }
    printf("Total Cars:%d\n", count);
}

RacingCar    *AddCar(RacingCar *previous)
{
    printf("Enter Name and speed:");
	char input[16];
	fgets(input, 15, stdin);

    RacingCar *newCar = malloc(sizeof(RacingCar));
    sscanf(input, "%s %d", newCar->name, &newCar->speed);
    printf("Added:%s Speed:%d\n\n", newCar->name, newCar->speed);

    if (previous != NULL)
        previous->next = newCar;

    return (newCar);
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
    RacingCar *newest = NULL;

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
		else if (strncmp(command, "add", 3) == 0)
        {
            if(start == NULL)
            {
                start = AddCar(NULL);
                newest = start;
            }
            else
            {
                newest = AddCar(newest);
            }
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
