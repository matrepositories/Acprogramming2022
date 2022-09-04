#include "project.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//adlwoq, mallocit, quit exit, tarkistus, 

Meeting* AddMeeting(Meeting* headnode, char* description, int month, int day, int hour)
{
    Meeting* temp = headnode;
    while(temp != NULL)
    {
        if((temp->day == day) && (temp->month == month) && (temp->hour == hour) && (strcmp(temp->description, description) == 0))
            {
                printf("ERROR - APPOINTMENT TIME ALREADY BOOKED\n");
            }
        temp = temp->next;
    } 
    Meeting* newmeeting = NULL;
    newmeeting = malloc(sizeof(Meeting));
    newmeeting->description = malloc((strlen(description) + 1) * sizeof(char));
    newmeeting->description = strcpy(newmeeting->description, description);
    newmeeting->next = NULL;
    newmeeting->month = month;
    newmeeting->day = day;
    newmeeting->hour = hour;
    return newmeeting;
}   

Meeting* DeleteMeeting(Meeting* deletenode, int month, int day, int hour)
{
    Meeting* current = deletenode; //allokoi?
    Meeting* previous = deletenode;
    int n = 0;
    while(current != NULL)
    {
        n++;
        if((current->month == month) && (current->day == day) && (current->hour == hour))
        {
            if(n == 1) //delete first linked list member
            {
                char* buffer = malloc((strlen(current->description) + 1) * sizeof(char));
                strncpy(buffer, deletenode->description, (strlen(current->description) + 1) * sizeof(char));
                deletenode = deletenode->next;
                free(current->description);
                free(current);
                current = NULL;
                printf("SUCCESS\n");
                return deletenode;
            }
            else if(current->next == NULL) //delete last member
            {
                char* buffer = malloc((strlen(current->description) + 1) * sizeof(char));
                strncpy(buffer, current->description, (strlen(current->description) + 1) * sizeof(char));
                previous->next = NULL;
                free(current->description);
                free(current);
                printf("SUCCESS\n");
                return previous;
            }
            else if(current->next != NULL) //delete from between
            {
                char* buffer = malloc((strlen(current->description) + 1) * sizeof(char));
                strncpy(buffer, current->description, (strlen(current->description) + 1) * sizeof(char));
                previous->next = current->next;
                free(current->description);
                free(current);
                printf("SUCCESS\n");
                return deletenode;
            }
            break;
        }
        previous = current;
        current = current->next;
    }
    return deletenode;
}

void swap(Meeting *a, Meeting *b) 
{
    //= malloc((strlen(a->description) + 1) * sizeof(char))
    char* tempdesc;
    tempdesc = a->description; 
    int tempmonth = a->month;
    int tempday = a->day;
    int temphour = a->hour;
    a->description = b->description; 
    a->month = b->month;
    a->day = b->day;
    a->hour = b->hour;
    b->description = tempdesc;
    b->month = tempmonth;
    b->day = tempday;
    b->hour = temphour;
    //free(tempdesc);

    /*int temp = a->data; 
    a->data = b->data; 
    b->data = temp;*/ 
} 

void SortAndPrint(Meeting *start)
{
    int swapped;
    Meeting *ptr1;
    Meeting *lptr = NULL;
    do //BUBBLE SORT: this do-while-loop iterates through members of the linked list swapping the data of contiguous members every time the appointment date of ptr1 is later than ptr1->next.   
    {  //On every iteration lptr moves back in the linked list one linked list member spot. One iteration stops once the next linked list spot is lptr. The do-while-loop stops once no swapping is necessary and the function moves on to printing.
        swapped = 0;
        ptr1 = start; 
        while(ptr1->next != lptr)  
        {
            if(ptr1->month > ptr1->next->month)  //this nested if-condition compares the dates 
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            if(ptr1->month == ptr1->next->month)
            {
                if(ptr1->day > ptr1->next->day)
                {
                    swap(ptr1, ptr1->next);
                    swapped = 1;
                }
                if(ptr1->day == ptr1->next->day)
                {
                    if(ptr1->hour > ptr1->next->hour)
                    {
                        swap(ptr1, ptr1->next);
                        swapped = 1;
                    }
                }
            }
            ptr1 = ptr1->next; //iterating through linked list members
        }
        lptr = ptr1; //setting lptr to the previous linked list spot starting from NULL
    }
    while(swapped);
    
    ptr1 = start;
    while(ptr1 != NULL)
    {
        printf("%s %02d.%02d at %02d\n", ptr1->description, ptr1->day, ptr1->month, ptr1->hour);
        ptr1 = ptr1->next;
    }
    printf("SUCCESS\n");
}

void SaveToTextfile(const char* filename, Meeting *start)
{
    char file_name[100];
    strcpy(file_name, filename);
    strcat(file_name, ".txt");
    FILE *f = fopen(filename, "w");
    if (!f)
	{
		printf("Cannot open file %s for reading.\n", filename);
	}
    Meeting *ptr1 = start;
    while(ptr1 != NULL)
    {
        fprintf(f, "%s %02d.%02d at %02d", ptr1->description, ptr1->day, ptr1->month, ptr1->hour);
        ptr1 = ptr1->next;
    }
    printf("SUCCESS\n");
    fclose(f);
}

void FreeMemory(Meeting* start)
{
    Meeting* curr = start;
    Meeting* del;
    while(curr != NULL)
        {
            del = curr;
            curr = curr->next;
            free(del->description);
            free(del);
        }
}

Meeting* LoadFromTextfile(const char* filename, Meeting *start)
{
    char file_name[100];
    strcpy(file_name, filename);
    strcat(file_name, ".txt");
    FILE *f = fopen(filename, "r");
    int month, day, hour = 0;
    int bignumber = 100;
    char strfile[100];
    char description[100];
	if (!f)
	{
		printf("Cannot open file %s for reading.\n", filename);
        return start;
	}
    FreeMemory(start);
    Meeting* current;
    fgets(strfile, bignumber, f);
    sscanf(strfile,"%s %d.%d at %d", description, &day, &month, &hour);
    current = AddMeeting(start, description, month, day, hour);
    Meeting* newstart = current;
    while(fgets(strfile, bignumber, f) != NULL)
    {
        sscanf(strfile,"%s %d.%d at %d", description, &day, &month, &hour);
        current->next = AddMeeting(start, description, month, day, hour);
        current = current->next;
    }
    fclose(f);
    printf("SUCCESS\n");
    return newstart;
}



int main(void)
{
    int quitprogram = 0;
    while(quitprogram != 1)
    {
        Meeting *first = NULL;
        Meeting *added = NULL;
        Meeting *temp0 = malloc(sizeof(Meeting));
        int bignumber = 100;
        int month, day, hour, n, del = 0;
        char invalidcommand;
        //char* description = malloc(bignumber * sizeof(char)); 
        //char* filename = malloc(bignumber * sizeof(char)); 
        //char* s1 = calloc(1, bignumber); 
        char description[60]; 
        char filename[60]; 
        char s1[60]; 
        while(fgets(s1, bignumber, stdin)) 
        {
            switch (s1[0])
            {
            case 'A':
                sscanf(s1,"%s %s %d %d %d", &invalidcommand, description, &month, &day, &hour);
                    if((month > 0) && (month <= 12))//checks whether the linked list data acquired from input is within the assignment requirement specified range
                    {
                        if((day > 0) && (day <= 31))
                        {
                            if((hour >= 0) && (hour < 24))
                            {
                                if (first == NULL)
                                {
                                    first = AddMeeting(first, description, month, day, hour); //adds the first appointment in the linked list
                                    if (first != NULL)
                                        {
                                            added = first;
                                        }
                                    printf("SUCCESS\n");
                                    break;
                                }
                                else
                                {
                                    added->next = AddMeeting(first, description, month, day, hour); //from the first onwards
                                    if (added->next != NULL)
                                        {
                                            added = added->next;
                                        }
                                    printf("SUCCESS\n");
                                    break;
                                }
                            }
                            else
                            {
                                printf("Hour cannot be negative or greater than 23.");
                                break;
                            }
                        }
                        else
                        {
                            printf("Day cannot be less than 1 or greater than 31.");
                            break;
                        }
                    }
                    else
                    {
                        printf("Month cannot be less than 1 or greater than 12.");
                        break;
                    }
            case 'D':
                sscanf(s1,"%s %d %d %d", &invalidcommand, &month, &day, &hour);
                temp0 = first;
                while(temp0 != NULL)
                {
                    n++;
                    if((temp0->month == month) && (temp0->day == day) && (temp0->hour == hour))
                    {
                        if(n == 1)
                        {
                            first = DeleteMeeting(first, month, day, hour);
                            del = 1;
                            n = 0;
                            break;
                        }
                        else if(temp0->next == NULL)
                        {
                            added = DeleteMeeting(first, month, day, hour);
                            del = 1;
                            n = 0;
                            break;
                        }
                        else if(temp0->next != NULL)
                        {
                            first = DeleteMeeting(first, month, day, hour);
                            del = 1;
                            n = 0;
                            break;
                        }
                        
                    }
                    temp0 = temp0->next;
                }
                if(del == 0)
                {
                    printf("The time slot %02d.%02d at %02d is not in the calendar.\n", day, month, hour);
                }
                n = 0;
                del = 0;
                break;
            case 'L':
                SortAndPrint(first);
                break;
            case 'W':
                sscanf(s1,"%s %s", &invalidcommand, filename);
                SaveToTextfile(filename, first);
                break;
            /*case 'O':
                sscanf(s1,"%s %s", &invalidcommand, filename);
                first = LoadFromTextfile(filename, first);
                added = first;
                while(added->next != NULL)
                {
                    added = added->next;
                }
                break;*/
            case 'Q':
                FreeMemory(first);
                quitprogram = 1;
                break;
            default:
                sscanf(s1,"%c", &invalidcommand);
                printf("Invalid Command %c\n", invalidcommand);
                break;
            }
        }
    }
}



