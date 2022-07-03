#include<iostream>
using namespace std;

void Mat(int d[],int n) //Function that calculates the minimum chain multiplication and finds the equation
{
  int a[n][n],b[n],min,count=0;
  bool var[n];
  string eq="(";

  for(int i=0;i<n;i++)
  {
    var[i]=false; //Sets all values in the array to false to prevent garbage values

    for(int j=0;j<n-i;j++)
    {
      a[j][j+i]=9999; //Sets the initial matrix cell to a large integer to get replaced by the calculated value on first run

      for(int k=j;k<j+i;k++)
      {
        min=a[j][k]+a[k+1][j+i]+(d[j]*d[k+1]*d[j+i+1]); //Finds the value for respective K value using the formula

        if(min<a[j][j+i]) //Replaces the stored value in matrix cell with a minimum value
        {
          a[j][j+i]=min;
          if(j==0)
            b[j+i]=k;
        }
      }

      if(i==0) //Used to set all diagonal matrix cells to 0
        a[j][j+i]=0;
    }
  }
