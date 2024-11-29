#include <stdio.h>
#include <time.h>

int main(){

    time_t now;
    time(&now);
    struct tm *localTime = localtime(&now);

    char attendance_name[40];

    snprintf(attendance_name,sizeof(attendance_name), "attendance/%02d-%02d-%d.csv",
    localTime->tm_mday,
    localTime->tm_mon + 1,
    localTime->tm_year + 1900
    );

    FILE *data = fopen(attendance_name,"w");
    if (!data) {
        perror("Error opening file");
        return 0;
    }
    fprintf(data,"S.no , Name , RollNo , Attendance\n");

    const char *RollNo[] = {
        "124ad0001",
        "124ad0002",
        "124ad0003",
        "124ad0003",
        "124ad0004",
        "124ad0005",
        "124ad0006",
        "124ad0007",
        "124ad0008",
        "124ad0009",
        "124ad0010",
        "124ad0011",
        "124ad0012",
        "124ad0013",
        "124ad0014",
        "124ad0015",
        "124ad0016",
        "124ad0017"
    };

    const char *Names[17] = {
        "student1",
        "student2",
        "student3",
        "student4",
        "student5",
        "student6",
        "student7",
        "student8",
        "student9",
        "student10",
        "student11",
        "student12",
        "student13",
        "student14",
        "student15",
        "student16",
        "student17"
    };

    printf("enter 0 if the student is absent. if the student is present, dono't enter any thing or enter a non-zero number\n");
    
    int strength = sizeof(Names)/ sizeof(Names[0]);
    int count = 0;
    while (count <= strength) {
        int status = 1;
        printf("\n%s %s :- ",Names[count], RollNo[count]);
        scanf("%d",&status);

        if(status){
            fprintf(data,"%d, %s, %s, Present \n",count + 1, Names[count], RollNo[count]);
        }
        else{
            fprintf(data,"%d, %s, %s, Absent \n",count + 1,Names[count],RollNo[count]);
        }
        count += 1;
    }
    fclose(data);
    return 0;
}