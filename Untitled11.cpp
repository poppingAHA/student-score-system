#include<stdio.h>
#include<stdlib.h>
#define N 100
#define M 10
struct student{
    int num;  //学号
    char name[30];   //姓名
    int score[M];   //成绩
    char course[M][20];//课程名称
    int total; //总分
};
int k=0,count=0;
void main(){
    struct student stu[N];
    int n,x;
    void myinput(struct student stu[]);
    void mydelete(struct student stu[],int x);
    void myamend(struct student stu[],int x);
    void myall(struct student stu[]);
    void mysort(struct student stu[]);
    int mylookup(struct student stu[],int x);
    void mysort2(struct student stu[]);
    void mysave(struct student stu[]);
    void myread(struct student stu[]);
    void mycourse(struct student stu[]);
    while(1){
        printf("------------主菜单------------\n");
        printf("1.学生成绩增加\n");
        printf("2.学生成绩删除\n");
        printf("3.学生成绩修改\n");
        printf("4.打印输出所有学生\n");
        printf("5.按学号排序显示\n");
        printf("6.按学号查询\n");
        printf("7.按总分排序显示\n");
        printf("8.数据保存\n");
        printf("9.数据读取\n");
        printf("10.课程自定义\n");
        printf("0.退出系统\n");
        printf("------------------------------\n");
        printf("请选择：");
        scanf("%d",&n);
        switch(n){
            case 1:
                myinput(stu);
                break;
            case 2:
                mydelete(stu,x);
                break;
            case 3:
                myamend(stu,x);
                break;
            case 4:
                myall(stu);
                break;
            case 5:
                mysort(stu);
                break;
            case 6:
                printf("请输入查找的学生学号：");
                int i,j;
                i=mylookup(stu,x);
                if(i!=-1){
                    printf("查找成功。该学生信息如下：\n");
                    printf("学号：%d 姓名：%s\n",stu[i].num,stu[i].name);
                    for(j=0;j<count;j++){
                        printf("第%d门课程:%d\t",j+1,stu[i].score[j]);
                    }
                    printf("\n");
                }else{
                    printf("查找不成功，请确认输入数据是否正确。\n");
                }
                break;
            case 7:
                mysort2(stu);
                break;
            case 8:
                mysave(stu);
                break;
            case 9:
                myread(stu);
                break;
            case 10:
                mycourse(stu);
                break;
            case 0:
                exit(0);
        }
    }
}
void myinput(struct student stu[]){
    int i;
    printf("请输入课程数量：\n");
    scanf("%d",&count);
    for(i=0;i<count;i++){
        printf("请输入课程名称：\n");
        scanf("%s",&stu[i].course);
    }
    printf("请输入学号：");
    scanf("%d",&stu[k].num);
    getchar();
    printf("请输入姓名：");
    gets(stu[k].name);
    for(i=0;i<count;i++){
        printf("请输入%s课程的成绩：",stu[i].course);
        scanf("%d",&stu[k].score[i]);
    }
    k++;
}
void mydelete(struct student stu[],int x){
    int i,indext;
    int mylookup(struct student stu[],int x);
    printf("请输入要删除的学生的学号：\n");
    indext=mylookup(stu,x);
    if(indext!=-1){
        for(i=indext;i<k;i++){
            stu[i]=stu[i+1];
        }
        k--;
        printf("删除成功。\n");
    }else{
        printf("删除失败，找不到该学生的信息。\n");
    }
}
void myamend(struct student stu[],int x){
    int i,indext;
    int mylookup(struct student stu[],int x);
    printf("请输入要修改的学生的学号：");
    indext=mylookup(stu,x);
    if(indext!=-1){
        printf("请重新输入学生的信息：\n请输入学生学号：");
        scanf("%d",&stu[indext].num);
        getchar();
        printf("请输入学生姓名：");
        gets(stu[indext].name);
        printf("请输入学生成绩，以空格隔开：");
        for(i=0;i<count;i++){
            scanf("%d",&stu[indext].score[i]);
        }
        printf("修改成功。\n");
    }else{
        printf("修改失败，找不到该学生的信息。\n");
    }
}
void myall(struct student stu[]){
    int i,j;
    printf("学号\t姓名\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}
void mysort(struct student stu[]){
    int i,j;
    struct student t;
    for(i=0;i<k-1;i++){
        for(j=0;j<k-i-1;j++){
            if(stu[j].num>stu[j+1].num){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    printf("学号\t姓名\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("\n");
    }
}
int mylookup(struct student stu[],int x){
    int i,indext=-1;
    scanf("%d",&x);
    for(i=0;i<N;i++){
       if(stu[i].num == x){
        indext=i;
        break;
       }
    }
    return indext;
}
void mysort2(struct student stu[]){
    int i,j,a;
    struct student t;
    for(i=0;i<k;i++){
        for(j=0;j<count;j++){
            stu[i].total+=stu[i].score[j];
        }
    }
    for(i=0;i<k-1;i++){
        for(j=0;j<k-i-1;j++){
            if(stu[j].total<stu[j+1].total){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    printf("学号\t姓名\t");
    for(i=0;i<count;i++){
        printf("%s\t",stu[i].course);
    }
    printf("总分\t名次\n");
    for(i=0;i<k;i++){
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            printf("%d\t",stu[i].score[j]);
        }
        printf("%d\t%d\t",stu[i].total,i+1);
        printf("\n");
    }
}
void mysave(struct student stu[]){
    FILE *fp;
    fp=fopen("output.txt","w");
    int i,j;
    for(i=0;i<k;i++){
        fprintf(fp,"%d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++){
            fprintf(fp,"%d\t",stu[i].score[j]);
        }
    }
    printf("数据保存成功！\n");
    fclose(fp);
}
void myread(struct student stu[]){
    FILE *fp;
    fp=fopen("output.txt","r");
    int i,j;
    if (!fp){
        printf("Cannot open such a file\n");
        exit(1);
    }
    while(!feof(fp)){
        fscanf(fp,"%d\t%s\t",&stu[i].num,&stu[i].name);
        printf("%d\t%s\t",stu[i].num,stu[i].name);
        for(i=0;i<k;i++){
            for(j=0;j<count;j++){
                fscanf(fp,"%d\t",&stu[i].score[j]);
                printf("%d\t",stu[i].score[j]);
            }
        }
        k++;
        i++;
    }
    fclose(fp);
    printf("\n数据读取成功！\n");
}
void mycourse(struct student stu[]){
    int count,i,j;
    char c[M][20];
    printf("输入课程数量<%d:\n",M);
    scanf("%d",&count);
    getchar();
    for(i=0;i<count;i++){
        printf("输入第%d门课程的名称：\n",i+1);
        gets(c[i]);
    }
    for(i=0;i<N;i++){
        printf("输入学号：\n");
        scanf("%d",&stu[i].num);
        getchar();
        printf("输入姓名：\n");
        scanf("%s",&stu[i].name);
        for(j=0;j<count;j++){
            strcpy(stu[i].course[j],c[j]);
        }
        for(j=0;j<count;j++){
            printf("请输入%s的成绩:",stu[i].course[j]);
            scanf("%d",&stu[i].score[j]);
        }
    }
    printf("学号\t姓名\t");
    for(j=0;j<count;j++){
        printf("%s\t",stu[0].course[j]);
    }
    printf("\n");
    for(i=0;i<N;i++){
        printf("%4d\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<count;j++)
            printf("%4d\t",stu[i].score[j]);
        printf("\n");
    }
}
