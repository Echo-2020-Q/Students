#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define Z 30
# define Course 6
void DataRead(int iNumberofstudents);
void DataOutput(char cName[Z+2][30],int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents);
void LineSearch_Num(int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents,int Studentnumber);
void LineSearch_Nam(char cName[Z+2][30],int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents,char Studentname[30]);
void Datasort_name(char cName[Z+2][30],int iSumMarks[],int iStudent_number[],int iNumberofstudents);
void Datasort_order(int iSumMarks[],int iStudent_number[],int iNumberofstudents,int (*compare)(int a,int b));
void Sum_Avermarks(int iMarks[Z+1][7],int counter);
int Descending(int a,int b);
int Aescending(int a,int b);
int iStudent_number[31],iStudent_number0[31],iMarks[Z+1][7],iMarks0[Z+1][7],iSumMarks[Z+1],iSumMarks0[Z+1],iNumberofstudents,iNumberofcourses;
char cName[Z+2][30],cName0[Z+2][30];
float fAvemarks;//*全局变量：第一个是关于学生学号的一维数组、第二个是关于学生各科分数的二维数组。第三个是学生的总分的一维数组，第四个是学生总数的整型，第五个是考试科目数的整型，第六个是学生姓名的二位字符串数组，第七个是平均分的浮点数*//
int main()
{
    printf("Students performance management system(V3.0)\n");
    int iChoice,Counter3,Counter4,counter,iJudgment,Studentnumber;
    float A=0,B=0,C=0,D=0,E=0;//*学生考试成绩的五个等级*//
    do
    {
        printf("     MENU   \n");                                   //*输入初始的菜单界面*//
        printf("1. Input record\n");
        printf("2. List record\n");
        printf("3. Calculate total and average score of every course\n");
        printf("4. Calculate total and average score of every student\n");
        printf("5. Sort in descending order by total score of every student\n");
        printf("6. Sort in ascending order by total score of every student\n");
        printf("7. Sort in ascending order by StudentID\n");
        printf("8. Sort in dicitionary order by name\n");
        printf("9. Search by StudentID\n");
        printf("10.Search by name\n");
        printf("11.Statistic analysis for every course\n");
        printf("0. Exit\n");
        printf("Please enter your choice(according to number):");   //*提示输入用户选择选项，鲁棒：提示用户输入格式为数字*//
        scanf(" %d",&iChoice);
        if(iChoice==1)
        {
            printf("\nPlease input the number of ALL students:");   //*首先输入统计的所有的学生数目*//
            scanf("%d",&iNumberofstudents);
            if(0>=iNumberofstudents||Z<iNumberofstudents)          //*鲁棒：对用户非法输入检查，纠错*//
            {
                for(; iNumberofstudents>Z||iNumberofstudents<=0;)
                {
                    printf("\nPlease input the number of student:(0-%d):",Z);
                    scanf("%d",&iNumberofstudents);
                }
            }
            printf("\nPlease input the number of ALL courses:");      //*首先输入统计的所有的考试科目*//
            scanf("%d",&iNumberofcourses);
            if(0>=iNumberofcourses||iNumberofcourses>6)             //*鲁棒：对用户非法输入检查，纠错*//
            {
                for(; iNumberofcourses>Course||iNumberofcourses<=0;)
                {
                    printf("Please input the number of ALL course:(0-%d)",Course);
                    scanf("%d",&iNumberofcourses);
                }
            }
            DataRead(iNumberofstudents);
            printf("\n\n");
            iJudgment=1;                                           //*鲁棒：其他序号的程序，每次进入都有对用户是否首先经过“选项1”检查*//
        }
        else if(iChoice==2)
        {
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            printf("The name,number and every course marks information of students are as follows:\n");//*解释学生的各种信息，增加说明性、可读性*//
            printf("Student name\tStudent number\t");
            for(counter=1; counter<=iNumberofcourses; counter++)
            {
                printf("\tCourse %d",counter);
            }
            printf("\n");
            DataOutput(cName,iMarks,iStudent_number,iNumberofstudents);
            printf("\n\n");
        }
        else if(iChoice==3)
        {
            float sum=0;
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            for(counter=1; counter<=iNumberofcourses; counter++)        //*按课程计算总分，均分*//
            {
                for(Counter3=1,sum=0; Counter3<=iNumberofstudents; Counter3++)
                {
                    sum=sum+iMarks[Counter3][counter];
                }
                printf("Total marks of Course %d :%.0f ,Average marks of Course %d :%.2f\n",counter,sum,counter,sum/iNumberofstudents);
            }
        }
        else if(iChoice==4)
        {
            int counter=1;
            if(iJudgment!=1)
            {
                printf("Please first  enter the '1.Input record'\n");
                continue;
            }
            printf("The sum marks of all students and average marks are as follows:\n");
            for(counter=1; counter<=iNumberofstudents; counter++)
            {
                printf("Name:%s",cName[counter]);
                Sum_Avermarks(iMarks,counter);                                           //*按学生计算总分，均分的函数*//
            }                                                                            //*增强说明性、可读性*//
            //*增强说明性、可读性*//
        }
        else if(iChoice==5)
        {
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            printf("the rank is as follows\n");                                         //*增强说明性、可读性*//
            Datasort_order(iSumMarks,iStudent_number,iNumberofstudents,Descending);
            for(counter=1; counter<=iNumberofstudents; counter++)
            {
                printf("%d. %s %d\n",counter,cName[counter],iSumMarks[counter]);        //*输出名次表*//
            }
            printf("\n\n");
        }
        else if(iChoice==6)
        {
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            printf("the rank is as follows\n");                                         //*增强说明性、可读性*//
            Datasort_order(iSumMarks,iStudent_number,iNumberofstudents,Aescending);
            for(counter=1; counter<=iNumberofstudents; counter++)
            {
                printf("%d. %s %d\n",counter,cName[counter],iSumMarks[counter]);        //*输出名次表*//
            }
            printf("\n\n");
        }
        else if(iChoice==7)
        {
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            printf("the rank is as follows\n");                                         //*增强说明性、可读性*//
            Datasort_order(iStudent_number,iSumMarks,iNumberofstudents,Aescending);     //*按学号排序*//
            for(counter=1; counter<=iNumberofstudents; counter++)
            {
                printf("%d.  %d  %d\n",counter,iStudent_number[counter],iSumMarks[counter]); //*输出名次表*//
            }
        }
        else if(iChoice==8)
        {
            Datasort_name(cName,iSumMarks,iStudent_number,iNumberofstudents);          //*按姓名字典顺序排序*//
        }
        if(iChoice!=1&&iChoice!=2&&iChoice!=3&&iChoice!=4&&iChoice!=5&&iChoice!=6&&iChoice!=7&&iChoice!=8&&iChoice!=9&&iChoice!=10&&iChoice!=11&&iChoice!=0)
        {
            printf("Sorry,please input the number 0-11\n");                          //*鲁棒：对于用户非法输入检查，应输入0-11*//
            continue;
        }
        else if(iChoice==9)
        {

            printf("Please input the student number of student you want to search:");   //*增强说明性、可读性*//
            scanf("%d",&Studentnumber);
            LineSearch_Num(iMarks,iStudent_number,iNumberofstudents,Studentnumber);         //*增强说明性、可读性*//
        }
        else if(iChoice==10)
        {
            char search[30];
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");                    //*增强说明性、可读性*//
                continue;
            }
            printf("Please input the student name of student you want to search:");     //*输入想要查找的学生学号*//
            scanf("%s",search);
            LineSearch_Nam(cName,iMarks,iStudent_number,iNumberofstudents,search);
        }
        else if(iChoice==11)
        {
            if(iJudgment!=1)
            {
                printf("Please first enter the '1.Input record'\n");
                continue;
            }
            for(counter=1; counter<=iNumberofcourses; counter++)
            {
                for(Counter4=1,A=0,B=0,C=0,D=0,E=0; Counter4<=iNumberofstudents; Counter4++)//*对于不同的成绩分类*//
                {
                    if(90<=iMarks[Counter4][counter]&&iMarks[Counter4][counter]<=100)
                    {
                        A++;
                    }
                    else if(80<=iMarks[Counter4][counter]&&iMarks[Counter4][counter]<=89)
                    {
                        B++;
                    }
                    else if(70<=iMarks[Counter4][counter]&&iMarks[Counter4][counter]<=79)
                    {
                        C++;
                    }
                    else if(60<=iMarks[Counter4][counter]&&iMarks[Counter4][counter]<=69)
                    {
                        D++;
                    }
                    else if(0<=iMarks[Counter4][counter]&&iMarks[Counter4][counter]<=59)
                    {
                        E++;
                    }
                }
                printf("the COURSE %d rank is as follows:\n",counter);                                //*列成表格的形式，增强说明性、可读性*//
                printf("A\tB\tC\tD\tE\t\n");
                printf("%.0f\t%.0f\t%.0f\t%.0f\t%.0f\n",A,B,C,D,E);
                printf("%.2f%%\t%.2f%%\t%.2f%%\t%.2f%%\t%.2f%%\n\n",A*100/iNumberofstudents,B*100/iNumberofstudents,C*100/iNumberofstudents,D*100/iNumberofstudents,E*100/iNumberofstudents);
            }
        }
    }
    while(iChoice!=0);
    system("pause");
}
void DataRead(int iNumberofstudents)                                               //*功能：读取学生姓名、学号和成绩的数据*//
{
    int Counter1=1,Counter2;
    for(Counter1=1; Counter1<=iNumberofstudents; Counter1++)                        //*输入参数：学生总数*//
    {
        int i=1,j=1;
        printf("\n%d.Please input the student name:",Counter1);
        scanf("%s",cName[Counter1]);
        printf("  Please input the student number:");                               //*返回值：无*//
        scanf("%d",&iStudent_number[Counter1]);
        for(; i<=iNumberofcourses; i++)
        {
            printf("  Please input the student Course%d marks:",i);
            scanf("%d",&iMarks[Counter1][i]);

            if(iMarks[Counter1][i]>100||iMarks[Counter1][i]<0)                     //*鲁棒：对输入成绩（0-100）的合法性检查*//
            {
                printf("The marks should be in 0-100\n");
                printf("Please input the student marks:");
                scanf("%d",&iMarks[Counter1][i]);
            }
        }
        for(i=1; i<=iNumberofstudents; i++)
        {
            iSumMarks[i]=0;
            for(j=1; j<=iNumberofcourses; j++)
            {
                iSumMarks[i]=iSumMarks[i]+iMarks[i][j];
            }
        }
    }
    for(Counter1=1; Counter1<=iNumberofstudents; Counter1++)
    {
        strcpy(cName0[Counter1],cName[Counter1]);
        iSumMarks0[Counter1]=iSumMarks[Counter1];
        iStudent_number0[Counter1]=iStudent_number[Counter1];
        for(Counter2=1; Counter2<=iNumberofcourses; Counter2++)
        {
            iMarks0[Counter1][Counter2]=iMarks[Counter1][Counter2];
        }
    }
}
void LineSearch_Num(int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents,int Studentnumber)
{
    Datasort_order(iStudent_number,iSumMarks,iNumberofstudents,Aescending);                //*函数功能：根据学生学号查找学生成绩以及排名*//
    int k=0,high=iNumberofstudents,low=0,mid;
    mid=(high+low)/2;

    for(; low<=high;)                                                                      //*输入参数：学生成绩，学生学号，学生总数，要查找资料的学生学号*//
    {
        if(Studentnumber>iStudent_number[mid])                                             //*方法：折半查找*//
        {
            low=mid+1;                                                                     //*返回值：无*//
            mid=(high+low)/2;
        }
        else if(Studentnumber<iStudent_number[mid])
        {
            high=mid-1;
            mid=(high+low)/2;
        }
        else
        {
            k=1;
            break;
        }
    }
    if(k==1)
    {
        printf("the student data is as follows:\n");
        printf("Ranking:%d.   Student number:%d   Marks:%d\n",mid,iStudent_number[mid],iSumMarks[mid]);
    }
    if(k==0)                                                                         //*鲁棒：若数据未找到，则提示用户输入学号不存在*//
    {
        printf("Sorry,the student number you want to search dont exist.\n");
    }
}
void DataOutput(char cName[Z+2][30],int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents)             //*函数功能：输出学生的学号和成绩*/
{
    int Counter2,i;
    //*输入参数：学生学号，学生成绩，学生总数*//
    for(Counter2=1; Counter2<=iNumberofstudents; Counter2++)
    {
        //*返回值：无*//
        printf("%-8s",cName0[Counter2]);
        printf("\t\t%-8d",iStudent_number0[Counter2]);
        for(i=1; i<=iNumberofcourses; i++)
        {
            printf("\t%d\t",iMarks0[Counter2][i]);
        }
        Sum_Avermarks(iMarks0,Counter2);                                                                         //*根据学生计算总分，均分的函数*//
    }
}
void Datasort_name (char cName[Z+2][30],int iSumMarks[],int student_t_distribution[],int iNumberofstudents)
{
    int i,j,n,counter;                                                                          //*函数功能：根据字典顺序，排序学生姓名，成绩，学号*//
    char temp[30];
    for(i=1; i<=iNumberofstudents-1; i++)                                                       //*参数：姓名（数组），分数（数组），学号（数组）， 学生数*//
    {
        for(j=i+1; j<=iNumberofstudents; j++)                                                   //*返回值：无*//
        {
            if(strcmp(cName[i],cName[j])>0)
            {
                strcpy(temp,cName[i]);
                strcpy(cName[i],cName[j]);
                strcpy(cName[j],temp);
                for(counter=1; counter<=iNumberofcourses; counter++)
                {
                    n=iMarks[i][counter];
                    iMarks[i][counter]=iMarks[j][counter];
                    iMarks[j][counter]=n;
                }
                n=iSumMarks[i];
                iSumMarks[i]=iSumMarks[j];
                iSumMarks[j]=n;
                n=iStudent_number[i];
                iStudent_number[i]=iStudent_number[j];
                iStudent_number[j]=n;
            }
        }
    }
    printf("the rank is as follows:\n");
    printf("Name\tMarks\n");
    for(n=1; n<=iNumberofstudents; n++)
    {
        printf("%s\t%d\n",cName[n],iSumMarks[n]);
    }
}
void LineSearch_Nam(char cName[Z+2][30],int iMarks[Z+1][7],int iStudent_number[],int iNumberofstudents,char Studentname[30])
{
    Datasort_order(iSumMarks,iStudent_number,iNumberofstudents,Descending);                 //*函数功能：线性查找学生姓名*//
    int i,k;
    for(i=1; i<=iNumberofstudents; i++)                                                  //*输入参数：姓名（数组），分数（数组），学号（数组）， 学生数，要查找的学生姓名*//
    {
        if(strcmp(Studentname,cName[i])==0)                                              //*返回值：无*//
        {
            k=1;
            break;
        }

    }
    if(k==1)
    {
        printf("the details are as follows:\n");
        printf("Name:%s , Marks:%d , Ranking:%d\n",cName[i],iSumMarks[i],i);
    }
    if(k!=1)
    {
        printf("Sorry,the student you search dont exist!\n");                             //*鲁棒：若找不到，则返回不存在*//
    }
}
void Datasort_order(int iSumMarks[],int iStudent_number[],int iNumberofstudents,int (*compare)(int a,int b))
{
    //*函数功能：根据键值由高到低或由低到高排序一组数据*//
    int i,j,k,n,m,counter;
    char temp[30];                                                                      //*输入参数：多个个一一照样的数组，键值由第一个决定，整型变量iNumberofsutdents是每个数组元素的总数，函数指针是用来控制排序方法*//
    for(i=1; i<=iNumberofstudents-1; i++)
    {
        //*返回值：无*//
        k=i;
        for(j=i+1; j<=iNumberofstudents; j++)                                           //*排序方法：选择法*//
        {
            if((*compare)(iSumMarks[k],iSumMarks[j]))
            {
                k=j;
            }
        }
        if(i!=k)
        {
            n=iSumMarks[i];
            iSumMarks[i]=iSumMarks[k];
            iSumMarks[k]=n;
            m=iStudent_number[i];
            iStudent_number[i]=iStudent_number[k];
            iStudent_number[k]=m;
            for(counter=1; counter<=iNumberofcourses; counter++)
            {
                n=iMarks[i][counter];
                iMarks[i][counter]=iMarks[k][counter];
                iMarks[k][counter]=n;
            }
            strcpy(temp,cName[i]);
            strcpy(cName[i],cName[k]);
            strcpy(cName[k],temp);
        }
    }
}
int Descending(int a,int b)                                                         //*函数功能：决定排序函数的排序方式*//
{
    //*输入参数：整型数a、b*//
    return a<b;                                                                     //*返回值：a<b*//
}
int Aescending(int a,int b)                                                         //*函数功能：决定排序函数的排序方式*//
{
    //*输入参数：整型数a、b*//
    return a>b;                                                                     //*返回值：a>b*//
}
void Sum_Avermarks(int iMarks[Z+1][7],int counter)                                  //*函数功能：按学生计算总分和均分*//
{
    float sum=0;                                                                    //*输入参数：二维数组：各科分数；整型：第counter个学生的总分，均分*//
    int i;
    for(i=1; i<=iNumberofcourses; i++)                                              //*返回值：五*//
    {
        sum=sum+iMarks[counter][i];
    }
    printf("\tTotal marks:%.0f\tAverage marks:%.2f\n",sum,sum/iNumberofcourses);
}













