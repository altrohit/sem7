#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
using namespace std;
int determinant(int key[3][3]){
	int det=0;
	int submat[2][2];
	int si,sj,k;
	si=0;sj=0;
	for(k=0;k<3;k++){
		si=0;
		sj=0;
		for(int i=1;i<3;i++){
			for(int j=0;j<3;j++){
				if(k==j)
					continue;
				submat[si][sj]=key[i][j];
				sj++;
				if(sj==2)
				{
					sj=0;
					si++;
					if(si==2)
						si=0;
				}
			}
		}
		det=det+ pow(-1,k+2)*key[0][k]*(submat[0][0]*submat[1][1]-submat[0][1]*submat[1][0]);
	}
	return det;
}
void fsubmat(int key[3][3],int submat[2][2],int p,int q)
{
	int l,m,i,j;
	l=0;m=0;
	for(i=0;i<3;i++)
	{
		if(i==p)
			continue;
		for(j=0;j<3;j++)
		{
			if(j==q)
				continue;
				submat[l][m++]=key[i][j];
				if(m==2)
				{
					m=0;
					l++;
					if(l==2)
						l=0;
					
				}
		}
	}
}
int mod26inverse(int det)
{
	for(int i=1;i<26;i++)
	{
		if((det*i)%26==1)
			return i;
	}
	return -1;
}
void finverse(int key[3][3],int inverse[3][3])
{
	int det=determinant(key);
	int d=mod26inverse(det);
	int submat[2][2],i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			fsubmat(key,submat,i,j);
			inverse[j][i]=d*pow(-1,(i+j+2))*(submat[0][0]*submat[1][1]-submat[0][1]*submat[1][0]);
			if(inverse[j][i]<0)
			{
				inverse[j][i]=inverse[j][i]%26 + 26;
			}
			else
				inverse[j][i]=inverse[j][i]%26;
		}
	}
}

int checkfactor(int a)
{
	for(int i=2;i<=26;i++)
	{
		if(a%i==0 && 26%i==0)
		return 1;
	}
	return -1;
}
int main()
{
	cout<<endl<<endl<<"      HILL CIPHER"<<endl<<endl;
	char mesg[100],enc[100],dec[100];
	cout<<"Enter the message :";
	gets(mesg);
	int l=strlen(mesg);
	int i,j,p,c,cf=1;
	int key[3][3];
	c=0;p=-1;
	while(c==0|| p==-1||cf==1)
	{
		cout<<"Enter the key matrix "<<endl;
		for(i=0;i<3;i++)
		{
			 
			for(j=0;j<3;j++)
			{
				cout<<i<<j<<" :";
				cin>>key[i][j];
			}
		}
		c=determinant(key);
		p=mod26inverse(c);
		cf=checkfactor(p);
		if(c==0)
			cout<<"The matrix you entered is not invertible"<<endl;
		if(p==-1)
			cout<<"The determinant mod 26 inverse of matrix don't exist "<<endl;
		if(cf==1)
			cout<<"Mod 26 inverse of determinant and 26 must not have any common factors"<<endl;
	}
	int inverse[3][3];
	finverse(key,inverse);
	cout<<"The matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		cout<<key[i][j]<<"  ";
		}
		cout<<endl;
	}
	cout<<"The determinant is :"<<c<<endl;
	cout<<"The inverse matrix is"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<inverse[i][j]<<"  ";
		}
		cout<<endl;
	}
	int m=l/3+(l%3==0?0:1);
	char mesmatrix[3][m];
	int k=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			if(k<l)
				mesmatrix[i][j]=mesg[k++];
			else
				mesmatrix[i][j]='x';
		}
	}
	cout<<"The message matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<mesmatrix[i][j]<<"  ";
			mesmatrix[i][j]=toupper(mesmatrix[i][j]);
		}
		cout<<endl;
	}
	int intmatrix[3][m];
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			 
				intmatrix[i][j]=(int)mesmatrix[i][j]-65;
		}
	}
	cout<<"The indexed matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<intmatrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	int sum=0;
	int mul[3][m];
	 for (i = 0; i< 3; i++) {
      for (j = 0; j < m; j++) {
        for (k = 0; k < 3; k++) {
          sum = sum + key[i][k]*intmatrix[k][j];
        }
		if(sum<0) 		
        mul[i][j] = sum%26+26;
        else
        mul[i][j]=sum%26;
        sum = 0;
      }
    }
    cout<<"The multiplied matrix is "<<endl;
    for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<mul[i][j]<<"  ";
		}
		cout<<endl;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
				mesmatrix[i][j]=(char)(mul[i][j]+65);
		}
	}
	cout<<"The encrypted matrix is "<<endl;
    for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<mesmatrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	k=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{	
			if(k<l)
			enc[k++]=mesmatrix[i][j];
		}
		cout<<endl;
	}
	enc[k]='\0';
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
				intmatrix[i][j]=(int)mesmatrix[i][j]-65;
		}
	}
	cout<<"The encrypted indexed matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<intmatrix[i][j]<<"  ";
		}
		cout<<endl;
	}
	sum=0;
	for (i = 0; i< 3; i++) {
      for (j = 0; j < m; j++) {
        for (k = 0; k < 3; k++) {
          sum = sum + inverse[i][k]*intmatrix[k][j];
        }
		if(sum<0) 		
        mul[i][j] = sum%26+26;
        else
        mul[i][j]=sum%26;
        sum = 0;
      }
    }
    cout<<"The decrypted indexed matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<mul[i][j]<<"  ";
		}
		cout<<endl;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
				mesmatrix[i][j]=(char)(mul[i][j]+65);
		}
	}
	cout<<"The message matrix is "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{
			mesmatrix[i][j]=tolower(mesmatrix[i][j]);
			cout<<mesmatrix[i][j]<<"  ";
		}
		cout<<endl;
	}	
	k=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<m;j++)
		{	
			if(k<l)
			dec[k++]=mesmatrix[i][j];
		}
		cout<<endl;
	}
	dec[k]='\0';
	cout<<"The encrypted message is "<<enc<<endl;
	cout<<"The decrypted message is "<<dec<<endl;
	getch();
	return 0;
}
