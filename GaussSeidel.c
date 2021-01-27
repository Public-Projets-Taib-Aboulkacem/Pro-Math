#include <stdio.h>
#include <stdlib.h>
//3 3 2 -1 0 0 -1 2 -1 2 -1 1 1 0 0 0 0 0.1

int a,b,nb=1;
int Mat1[20][20],B[20],X[20];
double X0[20][20];float Up;

int func1(){
	int i,j;
	printf("\n3 3 2 -1 0 0 -1 2 -1 2 -1 1 1 0 0 0 0 0.1\ndonnees a et b taille de la matresse : \n");
	scanf("%d%d",&a,&b);system("cls");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			printf("\nMat[%d][%d]=: ",i,j);scanf("%d",&Mat1[i][j]);system("cls");
		}
	}printf("-----------------------------------------------------------");
	for(j=0;j<b;j++){
			printf("\nB[%d]=: ",j);scanf("%d",&B[j]);system("cls");
	}printf("-----------------------------------------------------------");
	for(j=0;j<b;j++){
			printf("\nX0[%d]=: ",j);scanf("%f",&X0[j][0]);system("cls");
	}
	printf("-----------------------------------------------------------");
	printf("\nEpsilon=: ");scanf("%f",&Up);system("cls");
}
int func2(){
	int i,j,go=0,l[b],Nl=0,sum=0,Con;
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(i==j){
				Con=Mat1[i][j];
			}else{
				sum=sum+Mat1[i][j];
			}
		}
		if( Con >= sum ){
			printf("\nLa ligne %d et Convergen ;",i);
		}else{
			printf("\nLa ligne %d et pas Convergen °?° ;",i);
			if(go == 0 ){go=1;l[Nl]=i;Nl++;}else{l[Nl]=i;Nl++;}
		}Con=0;sum=0;printf("\nGo=%d:Nl=%d:i=%d\n",go,Nl,i);
	}
	//for(i=0;i<a;i++){for(j=0;j<b;j++){printf("1[%d]",Mat1[i][j]);}printf("\n");}	printf("\n");
	if( go == 1 ){
		if(Nl == 2 ){
		    for(j=0;j<b;j++){
		       int ch=Mat1[l[0]][j];
		       Mat1[l[0]][j]=Mat1[l[1]][j];
		       Mat1[l[1]][j]=ch;
			}int chb=B[l[0]];B[l[0]]=B[l[1]];B[l[1]]=chb;
	      //for(i=0;i<a;i++){for(j=0;j<b;j++){printf("2[%d]",Mat1[i][j]);}printf("\n");}printf("\n");
		  func2();
		}
		if(Nl == 1 ){
		    for(j=0;j<b;j++){
		       int ch=Mat1[l[0]][j];
		       Mat1[l[0]][j]=Mat1[l[0]+1][j];
		       Mat1[l[1]][j]=ch;
			}int chb=B[l[0]];B[l[0]]=B[l[0]+1];B[l[0]+1]=chb;
	      //for(i=0;i<a;i++){for(j=0;j<b;j++){printf("2[%d]",Mat1[i][j]);}printf("\n");}printf("\n");
		  func2();
		}
	}
}
double sumvar(int K,int L){
	int j,i;
	//for(i=0;i<a;i++){for(j=0;j<nb;j++){printf("X0[%d-%d]=[%f]",i,j,X0[i][j]);}printf("\n");}printf("\n");
	//for(i=0;i<a;i++){for(j=0;j<b;j++){printf("[%d]",Mat1[i][j]);}printf("\n");}printf("\n");
	double ret=0;
	for(j=0;j<b;j++){
		if(j==L){
			//printf("\nL==j OUI %d=%d et Mat1[%d][%d]=%d et ret = %f\n",L,j,L,j,Mat1[L][j],ret);
		}else{
			if( j > L){
				ret=ret+Mat1[L][j]*X0[j][K];
			}else{
				if( j < L){
					ret=ret+Mat1[L][j]*X0[j][K+1];
				}
			}
			//printf("\nL=%d : j=%d : K=%d : Mat1[L][j]=%d : X0[j][k=%d]= %f :ret=%f\n",L,j,K,Mat1[L][j],K,X0[j][K],ret);
		}
	}
	return ret;
}
int condaret(int k){
	int ret=1,i;
	double tab[b];
	for(i=0;i<a;i++){
		if( (X0[i][k]-X0[i][k-1]) < 0 ){tab[i]=-(X0[i][k]-X0[i][k-1]);/*printf("\ntab[%d]=%f :-(%f-%f)=-%f:\n",i,tab[i],X0[i][k],X0[i][k-1],(X0[i][k]-X0[i][k-1]));*/}
		if( (X0[i][k]-X0[i][k-1]) > 0 ){tab[i]=(X0[i][k]-X0[i][k-1]);/*printf("\ntab[%d]=%f :(%f-%f)=%f:\n",i,tab[i],X0[i][k],X0[i][k-1],(X0[i][k]-X0[i][k-1]));*/}
		//printf("\nK=%d : |%d - %d| tab[%d]=%f :\n",k,X0[i][k],X0[i][k-1],i,tab[i]);
	}//printf("\ntab[%d]=%f :-(%f-%f)=-%f:\n",i,tab[i],X0[i][k+1],X0[i][k],(X0[i][k+1]-X0[i][k]));
	for(i=0;i<a;i++){
	   if(!(tab[i] <= Up )){//printf("\ntab[i] <= Up ===> != %f <= %f \n",tab[i],Up);
	   	 ret=0;
	   }
	}
	if(ret == 1 ) printf("\nfiiiiiiiiiiiiiiiiiiiinnnnnnnnnnnnn%d\n",k);
	return ret;
}
int func3(){system("cls");
	int i,j,K=0;
 //while(condaret(K) != 1 ){
 while(K != 5 ){
 //do{
 	for(i=0;i<a;i++){
	   //for(j=0;j<b;j++){
	      X0[i][K+1]=((B[i]-(sumvar(K,i)))/Mat1[i][i]);
	      //printf("\nX(%d) ^(%d)= ( %d - %f ) / %d  = %f\n",i,K+1,B[i],sumvar(K,i),Mat1[i][i],X0[i][K+1]);
	   //}printf("\n");
	}printf("\n");
	printf("----------------------------------------------------------\n"); condaret(K);	
    K++;nb=K;	
 //}while(condaret(K) == 0 );

 }for(i=0;i<a;i++){for(j=0;j<nb;j++){printf("~[%f]",X0[i][j]);}printf("\n");}printf("\n");
}

int main(){
	//func0();
	func1();
	func2();
	func3();
}
