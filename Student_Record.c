//Roll no. - 21CE10068
// Name - Sreyan Goswami

#include<stdio.h>
#include<string.h>
#include<ctype.h> // for using the tolower function

struct student
{
    unsigned int roll;
    char first[21];
    char last[21];
    char grades[5];
    float gpa;
}studArray[50];  //array of students

int nStuds;
int enrolStuds();
void enterGrades();
void displayStuds();
void searchStuds();
void editStudGrades();
void dispMeritList();

int main()
{
    int ch;
    nStuds = 0;
    start:
    printf("\n\n 1. Enroll Student");
    printf("\n 2. Enter grade");
    printf("\n 3. Display Students");
    printf("\n 4. Search Students");
    printf("\n 5. Edit student grades");
    printf("\n 6. Display merit list");
    printf("\n 7. Exit");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);
    if(ch<1 || ch>7) // check for correct choice
    {
        printf("\n Wrong Choice");
        goto start;
    }
    switch(ch)
    {
    case 1:
        nStuds = 0;
        enrolStuds();
        break;
    case 2:
        enterGrades();
        break;
    case 3:
        displayStuds();
        break;
    case 4:
        searchStuds();
        break;
    case 5:

        editStudGrades();
        break;
    case 6:
        dispMeritList();
        break;
    case 7:
        _Exit(0);
    }

    goto start;

    return 0;

}

int enrolStuds()
{
    int n;
    if(nStuds != 0)
        printf("\n Refreshing database");
    printf("\n Enter number of students to be entered: ");
    scanf("%d", &n); // taking number of students to be enrolled
    if(n<0 || n>50)
    {
        printf("\n Wrong Input");
        return 0;
    }
    nStuds = n;
    struct student temp;
    for(int i=0; i<n; i++)
    {
        printf("\n Credentials for student %d \n", (i+1));
        printf("Enter Roll : ");
        scanf("%d", &studArray[i].roll); // roll
        printf("Enter fist name : ");
        scanf("%s", studArray[i].first); // first
        printf("Enter last name : ");
        scanf("%s", studArray[i].last); // last
    }

    //Sorting of the array according to the roll
     for (int i = 0; i < n; i++)
        {

            for (int j = i + 1; j < n; j++)
            {

                if (studArray[i].roll > studArray[j].roll)  //sorting wrt the roll
                {

                    temp =  studArray[i];
                    studArray[i] = studArray[j];
                    studArray[j] = temp;
                }

            }

        }

        printf("\n The students entered are ");
        for(int i=0; i<n; i++)
        {
            printf("\n Student %d", (i+1));
            printf("\n\tRoll no. - %d", studArray[i].roll);
            printf("\n\tFirst name : %s", studArray[i].first);
            printf("\n\tLast Name : %s", studArray[i].last);
        }

    return n;
}

void enterGrades()
{
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    for(int i=0; i<nStuds; i++)
    {
        printf("\n Roll - %d\tFirst name: %s\tLastName: %s  \n", studArray[i].roll, studArray[i].first, studArray[i].last);
        studArray[i].gpa = 0.0;
        for(int j=0; j<5;j++)
        {
            printf(" Enter Grade in subject %d : ", j+1);
            studArray[i].grades[j] = '\0';
            char ch;
            scanf("\n %c", &ch);
            studArray[i].grades[j] = ch; // taking grades for each subject
            if((studArray[i].grades[j]>'F' && studArray[i].grades[j]!='P') || studArray[i].grades[j]<'A') // checking validity of entered grade
            {
                // giving wrong grade only once will revert the entire process for better security
                printf("\n Invalid Grades. You have to restart the grading process");
                return;
            }

            switch(studArray[i].grades[j])
            {
                case 'E':
                    studArray[i].gpa+=10;
                    break;
                case 'A':
                    studArray[i].gpa+=9;
                    break;
                case 'B':
                    studArray[i].gpa+=8;
                    break;
                case 'C':
                    studArray[i].gpa+=7;
                    break;
                case 'D':
                    studArray[i].gpa+=6;
                    break;
                case 'P':
                    studArray[i].gpa+=5;
                    break;
                case 'F':
                    studArray[i].gpa+=0;
                    break;
            }

        }
        studArray[i].gpa/=5.00;
    }

    //Displaying student data
    for(int i=0; i<nStuds; i++)
    {
        printf("\n\nRoll no. - %d", studArray[i].roll);
        printf("\nFull name: %s %s", studArray[i].first, studArray[i].last);
        printf("\nGrades: ");
        printf("\n\tSubject 1: %c", studArray[i].grades[0]);
        printf("\n\tSubject 2: %c", studArray[i].grades[1]);
        printf("\n\tSubject 3: %c", studArray[i].grades[2]);
        printf("\n\tSubject 4: %c", studArray[i].grades[3]);
        printf("\n\tStudent 5: %c", studArray[i].grades[4]);
        printf("\nGPA : %0.2f", studArray[i].gpa);
    }
}

void displayStuds()
{
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    struct student temp;
   for (int i = 0; i < nStuds; i++)
    {
          for (int j = i + 1; j < nStuds; j++)
            {

                if (strcmp(studArray[i].first, studArray[j].first)>0) // sorting according to first name
                {

                    temp =  studArray[i];
                    studArray[i] = studArray[j];
                    studArray[j] = temp;
                }
                else if(strcmp(studArray[i].first, studArray[j].first)==0) // else sorting according to last name
                {
                    if(strcmp(studArray[i].last, studArray[j].last)>0)
                    {
                        temp =  studArray[i];
                        studArray[i] = studArray[j];
                        studArray[j] = temp;
                    }
                }

            }
    }

    //Printing the students sorted alphabetically
    for(int i=0; i<nStuds; i++)
    {
        printf("\n\nRoll no. - %d", studArray[i].roll);
        printf("\nFirst name: %s ", studArray[i].first);
        printf("\nLast name: %s", studArray[i].last);
    }
}

void searchStuds()
{
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    char str[21];
    char name[21];
    int tag =0;
    char search[21];
    printf("\n Enter the searching name: ");
    scanf("%s", str);
    char *p = &str[0];
    while(*p!='\0')
        search[tag++] = (char)tolower(*p++); // changing to lower case
    for(int i=0; i<nStuds; i++)
    {
        tag =0;
        p = studArray[i].first;
        while(*p!='\0')
         name[tag++] = tolower(*p++);
        if(strcmp(name, search) == 0)
        {
            printf("\n\nRoll no. - %d", studArray[i].roll);
            printf("\nFirst name: %s ", studArray[i].first);
            printf("\nLast name: %s", studArray[i].last);
            printf("\nGPA:- %0.2f", studArray[i].gpa);
        }
        p = studArray[i].last;
        tag = 0 ;
        while(*p!='\0')
         name[tag++] = tolower(*p++);
        if(strcmp(name, search) == 0)
        {
            printf("\n\nRoll no. - %d", studArray[i].roll);
            printf("\nFirst name: %s ", studArray[i].first);
            printf("\nLast name: %s", studArray[i].last);
            printf("\nGPA:- %0.2f", studArray[i].gpa);
        }
    }
}

void editStudGrades()
{
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    int flag = 0 ;
    int roll;
    int k=0;
    printf("\n Enter the roll number of the student: ");
    scanf("%d", &roll);
    for(int i=0; i<nStuds; i++)
    {
        if(studArray[i].roll == roll)
        {
            flag++;
            k=i;
            printf("\nStudent first name: %s", studArray[i].first);
            printf("\nStudent last name: %s", studArray[i].last);
            printf("\nRecent Grades :");
            printf("\n\tSubject 1: %c", studArray[i].grades[0]);
            printf("\n\tSubject 2: %c", studArray[i].grades[1]);
            printf("\n\tSubject 3: %c", studArray[i].grades[2]);
            printf("\n\tSubject 4: %c", studArray[i].grades[3]);
            printf("\n\tStudent 5: %c", studArray[i].grades[4]);
            printf("\nGPA : %0.2f", studArray[i].gpa);

            printf("\n Enter the new grades: \n");
            studArray[i].gpa = 0.0;
            for(int j=0; j<5;j++)
        {
            printf(" Enter Grade in subject %d : ", j+1);
            scanf("\n %c", &studArray[i].grades[j]);
            if((studArray[i].grades[j]>'F' && studArray[i].grades[j]!='P') || studArray[i].grades[j]<'A')
            {
                printf("\n Invalid Grades. Updatation failed.");
                return;
            }

            switch(studArray[i].grades[j])
            {
                case 'E':
                    studArray[i].gpa+=10;
                    break;
                case 'A':
                    studArray[i].gpa+=9;
                    break;
                case 'B':
                    studArray[i].gpa+=8;
                    break;
                case 'C':
                    studArray[i].gpa+=7;
                    break;
                case 'D':
                    studArray[i].gpa+=6;
                    break;
                case 'P':
                    studArray[i].gpa+=5;
                    break;
                case 'F':
                    studArray[i].gpa+=0;
                    break;
            }

        }
        studArray[i].gpa/=5.00;
        break;

      }

    }
    if(flag ==0)
    {
        printf("\n No such student found.");
        return;
    }

    printf("\n New Data for the student.");
    printf("\nStudent first name: %s", studArray[k].first);
    printf("\nStudent last name: %s", studArray[k].last);
    printf("\n Grades :");
    printf("\n\tSubject 1: %c", studArray[k].grades[0]);
    printf("\n\tSubject 2: %c", studArray[k].grades[1]);
    printf("\n\tSubject 3: %c", studArray[k].grades[2]);
    printf("\n\tSubject 4: %c", studArray[k].grades[3]);
    printf("\n\tStudent 5: %c", studArray[k].grades[4]);
    printf("\nGPA : %0.2f", studArray[k].gpa);

}

void dispMeritList()
{
    if(nStuds == 0)
    {
        printf("\n Enter students first");
        return ;
    }
    struct student temp;
    for (int i = 0; i < nStuds; i++)
        {

            for (int j = i + 1; j < nStuds; j++)
            {

                if (studArray[i].gpa < studArray[j].gpa) // sorting according to gpa
                {

                    temp =  studArray[i];
                    studArray[i] = studArray[j];
                    studArray[j] = temp;
                }
                else if(studArray[i].gpa == studArray[j].gpa)
                {
                    if(strcmp(studArray[i].last, studArray[j].last)>0)
                    {
                        temp =  studArray[i];
                        studArray[i] = studArray[j];
                        studArray[j] = temp;
                    }
                }

            }

        }

    printf("\n Merit list: ");
    for(int i=0; i<nStuds; i++)
    {
        printf("\n%d. Roll no. - %d \tFull Name - %s %s", i+1, studArray[i].roll, studArray[i].first, studArray[i].last);
        printf("\n    GPA - %0.2f", studArray[i].gpa);
    }
}
