#ifndef STUDENT_H_H
#define STUDENT_H_H
#include <stdio.h>
#include <string.h>
#include <windows.h>
FILE *fp1,*fp2,*fp3,*fp4;
struct stu
    {
        long num;
        char name[10];
        int dormitory;
        char sex[5];
        int age;
        int totalpoint;
        int failcount;
        int scholarship;
        int markplacing;
        int flag;


    }a[50];
int stucount = 0;
struct sub
    {
        char num[15];
        char type[10];
        int term;
        char name[30];
        int credit;
        int failcount;


    }b[100];
int subcount = 0;
struct score
{
    long n;
    int term;
    char subname[50];
    char subnum[50];
    char stuname[15];
    int m;
    int f;
}c[1000];
int scorecount = 0;
struct be
{
    long num;
    int term;
    int mark1,mark2,mark3;
    int reward;
    int punishment;
    int behaviourplacing;


}d[1000];
int becount = 0;
void menu()
{
    system("cls");
        printf("\n");
    printf("\t\t\t\t�����ιܼ����\n\n");
    printf("----------------------------------------------------------------------------\n\n");
    printf("�밴��ʾ����\n");
    printf("1---¼����Ϣ\n");
    printf("2---�޸���Ϣ\n");
    printf("3---��ʾ��Ϣ\n");
    printf("4---����\n");
    printf("5---��ѧ������\n");
    printf("0---�˳�ϵͳ\n");
}
#endif // STUDENT_H_H

