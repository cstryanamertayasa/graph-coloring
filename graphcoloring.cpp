#include <iostream>
#include<stdbool.h>
#include<stdlib.h>

#define max 25
using namespace std;
int n, v[max][max], a[max][max];

void input()
{
  int i,j;
  cout<<"Masukan Jumlah Vertex: ";
  cin>>n;
  cout<<"\n";

  cout<<"Jika Vertex Terhubung Tekan 1, Jika Tidak Tekan 0!\n\n";

  for (i=0;i<n;i++)
  {
    for (j=0;j<n;j++)
    {
      v[i][j]=-1;
    }
  }

  for(i=0;i<n;i++)
  {
    cout<<"Masukan Data Vertex "<<i+1<<": \n";
    for(j=0;j<n;j++)
    {
      if (i==j)
      {
        v[i][j]=0;
        v[j][i]=0;
      }

      else if (v[i][j]==1||v[i][j]==0)
      {
        continue;
      }

      else
      {
        cout<<"Apakah Vertex "<<i+1<<" Terhubung Dengan Vertex "<<j+1<<": ";
        cin>>v[i][j];
        v[j][i]=v[i][j];
      }
    }
    cout<<"\n";
  }

  cout<<"\n1. REPRESENTASI GRAF ANDA \n";
  for(i=0;i<80;i++)
  cout<<"=";
  cout<<"\n";
  for (i=0;i<n;i++)
  {
    for (j=0;j<n;j++)
    {
      cout<<v[i][j]<< "\t";
    }
    cout<<"\n";
  }
  cout<<"\n";
  for(i=0;i<80;i++)
  cout<<"=";
}


void countdegree()
{
  int i,j,m;
  cout<<"\n\n\n";
  cout<<"2. DERAJAT VERTEX \n";
  for(i=0;i<80;i++)
  cout<<"=";
  cout<<"\n";
  for (i=0;i<n;i++)
  {
    m=0;
    for (j=0;j<n;j++)
    {
      m=m+v[i][j];
    }
    a[0][i]=m;
    a[1][i]=i+1;
  }
  cout<<"Vertex :\t";
  for (i=0;i<n;i++)
  {
    cout<<a[1][i]<<"\t";
  }
  cout<<"\n";
  cout<<"Derajat:\t";
  for (i=0;i<n;i++)
  {
    cout<<a[0][i]<<"\t";
  }
  cout<<"\n";
  for(i=0;i<80;i++)
  cout<<"=";
}


void sorting()
{
  int temp,temp1,i,j;
  //using bubble sort
  for(i=0; i<n; i++)
  {
		for(j=0; j<n; j++)
    {
			if(a[0][j+1]>a[0][j])
      {
        //degree sorting
				temp=a[0][j];
				a[0][j]=a[0][j+1];
				a[0][j+1]=temp;
        //vertex sorting
        temp1=a[1][j];
				a[1][j]=a[1][j+1];
				a[1][j+1]=temp1;
      }
    }
  }
  cout<<"\n\n\n";
  cout<<"3. HASIL SORTING \n";
  for(i=0;i<80;i++)
  cout<<"=";
  cout<<"\n";
  cout<<"Vertex :\t";
  for (i=0;i<n;i++)
  {
    cout<<a[1][i]<<"\t";
  }
  cout<<"\n";
  cout<<"Derajat:\t";
  for (i=0;i<n;i++)
  {
    cout<<a[0][i]<<"\t";
  }
  cout<<"\n";
  for(i=0;i<80;i++)
  cout<<"=";
}


void printcolor()
{
  int i,krom;
  cout<<"\n\n\n";
  cout<<"4. PEWARNAAN GRAF \n";
  for(i=0;i<80;i++)
  cout<<"=";
  cout<<"\n";
  cout<<"Vertex :\t";
  for (i=0;i<n;i++)
  {
    cout<<a[1][i]<<"\t";
  }
  cout<<"\n";
  cout<<"Warna  :\t";
  for (i=0;i<n;i++)
  {
    cout<<a[2][a[1][i]-1]<<"\t";
  }

  krom=a[2][a[1][0]-1];
  for(i=0;i<n;i++)
  {
    if (krom<a[2][a[1][i]-1])
      krom = a[2][a[1][i]-1];
  }

  cout<<"\nBilangan Kromatik Adalah: "<<krom;
  cout<<"\n";
  for(i=0;i<80;i++)
  cout<<"=";
}

bool cancolor (int x, int k)
{
	for (int i = 0; i < n; i++)
  {
		if (v[a[1][x]-1][i] && k == a[2][i])
			return false;
  }
	return true;
}

bool coloringtest(int m, int x)
{
  int k;
	if (x == n)
		return true;

	for (k=1; k<=m; k++)
	{
		if (cancolor(x, k))
		{
		    a[2][a[1][x]-1] = k;

		    if (coloringtest (m, x+1) == true)
			     return true;

		    a[2][a[1][x]-1] = 0;
		}
	}

	return false;
}


bool coloring(int m)
{
	for (int i = 0; i < n; i++)
	 a[2][i] = 0;

	if (coloringtest(m, 0) == false)
	{
	cout<<"Tidak ada solusi";
	return false;
	}

	printcolor();
	return true;
}


int main()
{
  int m=100;
  char ans;
 	cout<<"\t ####  #####    ##   #####  #    #\n";
	cout<<"\t#    # #    #  #  #  #    # #    #\n";
	cout<<"\t#      #    # #    # #    # ######\n";
	cout<<"\t#  ### #####  ###### #####  #    #\n";
	cout<<"\t#    # #   #  #    # #      #    #\n";
	cout<<"\t ####  #    # #    # #      #    #\n\n\n";

	cout<<" ####   ####  #       ####  #####  # #    #  #### \n";
	cout<<"#    # #    # #      #    # #    # # ##   # #    #\n";
	cout<<"#      #    # #      #    # #    # # # #  # #     \n";
	cout<<"#      #    # #      #    # #####  # #  # # #  ###\n";
	cout<<"#    # #    # #      #    # #   #  # #   ## #    #\n";
	cout<<" ####   ####  ######  ####  #    # # #    #  #### n\n\n";


  cout<<" \n Tekan tombol apa saja untuk lanjut:";
	getchar();
  do
  {
  	system("clear");
    cout<<"\t\t*************************************************\n";
  	cout<<"\t\t*       -----------------------------           *\n";
  	cout<<"\t\t*               GRAPH COLORING                  *\n";
  	cout<<"\t\t*       -----------------------------           *\n";
  	cout<<"\t\t*************************************************\n\n\n";
    input();
    countdegree();
    sorting();
    coloring(m);
    cout<<"\n\nInput lagi?[y/n]: ";
    cin>>ans;
  } while(ans=='y');

  return 0;
}
