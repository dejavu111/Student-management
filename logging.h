#ifndef LOGGING_H_H
#define LOGGING_H_H
#include "student.h"
void menu1()
{
    printf("������Ϣ¼��---1\n");
    printf("�γ���Ϣ¼��---2\n");
    printf("Ʒ�б���¼��---3\n");
    printf("�γ̳ɼ�¼��---4\n");
    printf("������Ϣ¼��---5\n");
    printf("�������˵�---0\n");
}

void basic()
{
    int n,i;
    system("cls");
    if((fp1=fopen("basic.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fscanf(fp1,"%d",&stucount);
    for(i = 0; i< stucount;i++)
    {
        fread(&a[i],sizeof(struct stu),1,fp1);
    }
    printf("data is read\n");
    fclose(fp1);

    int temp = stucount;

    printf("������¼��������");
    scanf("%d",&n);
    printf("�����������Ϣ��\n");
    printf("ѧ��\t���� ����� �Ա� ����\n");
    for(i=temp;i<temp+n;++i)
    {
        scanf("%ld%s%d%s%d",&a[i].num,a[i].name,&a[i].dormitory,a[i].sex,&a[i].age);
        stucount++;

    }

    if((fp1=fopen("basic.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp1,"%d",stucount);

    for(i = 0 ; i < stucount;i++)
        {

            if(fwrite(&a[i],sizeof(struct stu),1,fp1)!=1)
            printf("file write error\n");
        }

    printf("data is saved\n");
    fclose(fp1);



    printf("--------------------------������Ϣ¼�����------------------------------------\n");
}
void subject()
{
    int n,i;
    system("cls");
    if((fp2=fopen("subject.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fscanf(fp2,"%d",&subcount);
    for(i = 0; i < subcount;i++)
    {
        fread(&b[i],sizeof(struct sub),1,fp2);
    }
    printf("data is read\n");
    fclose(fp2);

    int temp = subcount;
    printf("������¼��γ�����");

    scanf("%d",&n);
    printf("������γ���Ϣ��\n");

    for(i = temp; i < temp+n; ++i)
    {
        printf("�γ̺� �γ���� �γ�����ѧ�� �γ����� ѧ��\n");
        scanf("%s%s%d%s%d",b[i].num,b[i].type,&b[i].term,b[i].name,&b[i].credit);
        subcount++;

    }
    if((fp2=fopen("subject.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp2,"%d",subcount);
    for(i = 0; i < subcount;i++)
        if(fwrite(&b[i],sizeof(struct sub),1,fp2)!=1)
            printf("file write error\n");
    printf("data is saved\n");
    fclose(fp2);

    printf("--------------------------�γ���Ϣ¼�����------------------------------------\n");

}
void behaviour()
{
    system("cls");
    int i=0,k;
    printf("������¼��ѧ��������\n");
    scanf("%d",&k);
    printf("������Ʒ�з�����\n");
    printf("ѧ��\tѧ��\t����Ա\t������\t�༶����\n");
    if((fp3=fopen("behaviour.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fscanf(fp3,"%d",&becount);
    for(i = 0; i < becount;i++)
    {
        fread(&d[i],sizeof(struct be),1,fp3);
    }
    fclose(fp3);
    int temp = becount;
    for(i = temp; i < temp+k;i++)
    {
            scanf("%ld%d%d%d%d",&d[i].num,&d[i].term,&d[i].mark1,&d[i].mark2,&d[i].mark3);
            becount++;

    }
    if((fp3=fopen("behaviour.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp3,"%d",becount);
    for(i = 0; i < becount; i++)
    {
        if(fwrite(&d[i],sizeof(struct be),1,fp3)!=1)
            printf("file write error\n");
    }
    fclose(fp3);
    printf("--------------------------Ʒ�Ա���¼�����------------------------------------\n");

}
void mark()
{
    system("cls");
    int i,n;
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fscanf(fp4,"%d",&scorecount);
    for(i = 0; i < scorecount; i++)
    {
        fread(&c[i],sizeof(struct score),1,fp4);

    }
    fclose(fp4);
    int temp = scorecount;
    printf("������¼��ɼ�������");
    scanf("%d",&n);
    for(i = temp; i < temp+n; ++i)

    {
        scorecount++;
        printf("������γ̱��/�γ�����/�γ�ѧ��/ѧ��ѧ��/����/�ɼ�\n");
        scanf("%s%s%d%ld%s%d",c[i].subnum,c[i].subname,&c[i].term,&c[i].n,c[i].stuname,&c[i].m);
        if(c[i].m>=60)
            c[i].f=1;
        else
            c[i].f=0;

    }
    if((fp4=fopen("mark.dat","wb+"))==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    fprintf(fp4,"%d",scorecount);
    for(i = 0 ; i < scorecount;i++)
    {

         if(fwrite(&c[i],sizeof(struct score),1,fp4)!=1)
            printf("file write error\n");
    }

    printf("data is saved\n");
    fclose(fp4);
    printf("--------------------------�γ̳ɼ�¼�����------------------------------------\n");

}

void reward()
{
    system("cls");
    printf("�����뽱��ѧ��ѧ�ţ�(����0�˳�)");
    long n;
    int m;
    int p;
    int i;
     if((fp3=fopen("behaviour.dat","rb+"))==NULL)
        {
            printf("�ļ���ʧ��\n");
            exit(0);
        }
        fscanf(fp3,"%d",&becount);
        for(i = 0; i < becount;i++)
        {
            fread(&d[i],sizeof(struct be),1,fp3);
        }
        fclose(fp3);

    while(1)
    {
        scanf("%ld",&n);
        if(n==0)
            break;
        for(i = 0; i < becount; i++)
        {
            if(d[i].num==n)
                break;
        }

        printf("1---����\n");
        printf("2---�ͷ�\n");
        printf("0---�˳�\n");
        scanf("%d",&m);
        if(m==1)
        {
            printf("������ӷַ�����");
            scanf("%d",&p);
            d[i].reward+=p;

        }
        else
            if(m==2)
        {
            printf("��������ַ�����");
            scanf("%d",&p);
            d[i].punishment-=p;
        }

        else
            if(m==0)
            break;
        else
            printf("�����������������");


    }
     if((fp3=fopen("behaviour.dat","wb+"))==NULL)
        {
            printf("�ļ���ʧ��\n");
            exit(0);
        }
        fprintf(fp3,"%d",becount);
        for(i = 0; i < becount;i++)
        {
            if(fwrite(&d[i],sizeof(struct be),1,fp3)!=1)
                printf("file write error\n");
        }
        fclose(fp3);

    printf("--------------------------��������¼�����------------------------------------\n");

}

void logging()
{
    system("cls");
    int choice;
    menu1();
    while(1)
    {

        scanf("%d",&choice);
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:basic();printf("��������һ������\n");menu1();break;
            case 2:subject();printf("��������һ������\n");menu1();break;
            case 3:behaviour();printf("��������һ������\n");menu1();break;
            case 4:mark();printf("��������һ������\n");menu1();break;
            case 5:reward();printf("��������һ������\n");menu1();break;
            default:printf("�����������������\n");menu1();break;
        }

    }
}
#endif // LOGGING_H_H
