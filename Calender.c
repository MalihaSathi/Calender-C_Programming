#include<stdio.h>
int getFirstDayoftheYear(int year)
{
    int day=((year*365)+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;
return day;
}
int main()
{
    char *Month[]={"January","February","March","April","May","June","July"
                    ,"August","September","October","November","December"};
    int DaysInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int i,j,totaldays,weekday=0,spaceCounter=0,year;

    printf("Enter the year:");
    scanf("%d",&year);
    printf("\n ******* Welcome to %d Calendar *******",year);


    if((year%4==0 && year%100!=0) || (year%4==0 && year%100==0 && year%400==0))
    {
        DaysInMonth[1]=29;
    }

    weekday=getFirstDayoftheYear(year);

    for(i=0;i<12;i++)
    {
      printf("\n\n\n--------------%s---------------\n",Month[i]);
      printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");


      for(spaceCounter=1;spaceCounter<=weekday;spaceCounter++)
      {
          printf("     ");
      }

    totaldays=DaysInMonth[i];

      for(j=1;j<=totaldays;j++)
      {
          printf("%5i",j);
          weekday++;

          if(weekday>6)
          {
              weekday=0;
              printf("\n");
          }
      }
    }
return 0;
}
