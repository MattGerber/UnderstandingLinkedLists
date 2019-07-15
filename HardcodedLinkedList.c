
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

int main()
{
    RacingCar RedBull = { "RedBull", 100, NULL };
    RacingCar Ferrari = { "Ferrari", 100, NULL };
    RacingCar Mercedes = { "Mercedes", 100, NULL };
    RacingCar Lotus = { "Lotus", 100, NULL };
    RacingCar McLaren = { "McLaren", 100, NULL };

    RedBull.next = &Ferrari;
    Ferrari.next = &Mercedes;
    Mercedes.next = &Lotus;
    Lotus.next = &McLaren;

    Printlist(&RedBull);

    return 0;
}