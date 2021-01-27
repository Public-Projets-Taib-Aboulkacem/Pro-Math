#include <stdio.h>
#include <stdlib.h>
//3 3 1 3 0 6 7 -1 3 4 9 1 1 1 0 0 0 1

int a,b,nb=1;
int A[20][20],B[20],Gg[20][20],Hg[20][20],D[20][20],E[20][20],F[20][20],Gj[20][20],Hj[20][20];
double X[20][20],G_g[20][20],G_j[20][20],Mj[20][20],Nj[20][20],Mg[20][20],Ng[20][20];float Up;

int func1(){
	int i,j;
	printf("\n3 3 2 -1 0 0 -1 2 -1 2 -1 1 1 0 0 0 0 0.1\ndonnees a et b taille de la matresse : \n");
	scanf("%d%d",&a,&b);system("cls");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			printf("\nA[%d][%d]=: ",i,j);scanf("%d",&A[i][j]);system("cls");
		}
	}printf("-----------------------------------------------------------");
	for(j=0;j<b;j++){
			printf("\nB[%d]=: ",j);scanf("%d",&B[j]);system("cls");
	}printf("-----------------------------------------------------------");
	for(j=0;j<b;j++){
			printf("\nX0[%d]=: ",j);scanf("%f",&X[j][0]);system("cls");
	}
	printf("-----------------------------------------------------------");
	printf("\nEpsilon=: ");scanf("%f",&Up);system("cls");
}
int func2(){
	int i,j;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(i==j){D[i][j]=A[i][j];}else{D[i][j]=0;}
			if(i<j){F[i][j]=-(A[i][j]);}else{F[i][j]=0;}
			if(i>j){E[i][j]=-(A[i][j]);}else{E[i][j]=0;}
			Gj[i][j]=A[i][j];
			Gg[i][j]=(D[i][j]-E[i][j]);
			Hj[i][j]=(E[i][j]+F[i][j]);
			Hg[i][j]=(F[i][j]);
		}
	}/*int plu,j1,sum=0,i1=0;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
		 if(i==j) plu=1;else plu=0;
		  for(j1=0;j1<b;j1++){if(j!=j1){//sum=sum+Gg[i][j1]*G_g[j1][i];
		   printf("%d%d * %d%d + ",i,j1,j1,i1);
		  }}printf("\n");
           //G_g[i][j]=( plu - )/;
		i1++;}
	}*/
	int i1,plu;double sum=0.0;
	for(i=0;i<a;i++){
	   for(i1=0;i1<a;i1++){
		for(j=0;j<b;j++){
			if(i==i1) plu=1; else plu=0;
			if(j!=i){sum=sum+Gg[i][j]*G_g[j][i1];printf("\n%f= sum + | %d * %f |\n",sum,Gg[i][j],G_g[j][i1]);}
		    //printf("%d%d * %d%d + ",i,j,j,i1);
		    
		 }//printf("\n");
		 G_g[i][i1]=(( plu - sum )/Gg[i][i]);
		 printf("\nG_g[i][i1]=(( plu - sum )/Gg[i][i]);\n| %f =(( %d - %f )/ %d )|\n",G_g[i][i1],plu,sum,Gg[i][i]);sum=0;
	   }
	} sum=0.0;
	for(i=0;i<a;i++){
	   for(i1=0;i1<a;i1++){
		for(j=0;j<b;j++){
			if(i==i1) plu=1; else plu=0;
			if(j!=i){sum=sum+Gj[i][j]*G_j[j][i1];printf("\n%f= sum + | %d * %f |\n",sum,Gj[i][j],G_j[j][i1]);}
		    //printf("%d%d * %d%d + ",i,j,j,i1);
		    
		 }//printf("\n");
		 G_j[i][i1]=(( plu - sum )/Gj[i][i]);
		 printf("\nG_g[i][i1]=(( plu - sum )/Gg[i][i]);\n| %f =(( %d - %f )/ %d )|\n",G_j[i][i1],plu,sum,Gj[i][i]);sum=0;
	   }
	}
    sum=0.0;double sum1=0.0,sum2=0.0,sum3=0.0;
	for(i=0;i<a;i++){
	   for(i1=0;i1<a;i1++){
		for(j=0;j<b;j++){
			sum=sum+G_j[i][j]*Hj[j][i1];
			sum1=sum1+G_g[i][j]*Hg[j][i1];
			if(i1==0){sum2=sum2+G_g[i][j]*B[j];sum3=sum3+G_j[i][j]*B[j];}
		    printf("%d%d * %d%d + ",i,j,j,i1);
		 }printf("\n");
		 Mj[i][i1]=sum;sum=0;
		 Mg[i][i1]=sum1;sum1=0;
		 if(i1==0){Ng[i][i1]=sum2;sum2=0;Nj[i][i1]=sum3;sum3=0;}
	   }
	}
/*
	int i1;
	for(i=0;i<a;i++){
	   for(i1=0;i1<a;i1++){
		for(j=0;j<b;j++){
		    printf("%d%d * %d%d + ",i,j,j,i1);
		 }printf("\n");
	   }
	}
*/  system("cls");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("A[%d]",A[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("D[%d]",D[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("F[%d]",F[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("E[%d]",E[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Gj[%d]",Gj[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Gg[%d]",Gg[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Hj[%d]",Hj[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Hg[%d]",Hg[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("G_g[%f]",G_g[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("G_j[%f]",G_j[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Mj[%f]",Mj[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Mg[%f]",Mg[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Nj[%f]",Nj[i][j]);}printf("\n");}printf("\n");
	for(i=0;i<a;i++){for(j=0;j<b;j++){printf("Ng[%f]",Ng[i][j]);}printf("\n");}printf("\n");
    	
}
int main(){
	func1();
	func2();
}
