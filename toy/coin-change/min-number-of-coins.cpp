#include <iostream>
#include <limits.h>

using namespace std;

// Given unlimited supply of coins in certain denominations (e.g. {1,2,5,10})
// and an amount of money V (e.g. 27), find the minimal number of coins needed
// to change V.

int minCoins(const int coins[], const int change, int numberOfDenominations) {
   int i,j;
   
   int dpArray[change+1][numberOfDenominations];
   int stepMinima[change+1];
   
   for (j=0; j<numberOfDenominations; j++) dpArray[0][j]=0;
   for (i=0; i<change+1; i++) stepMinima[i]=INT_MAX;
   stepMinima[0]=0;
   
   for (i=1; i<change+1; i++) {
	   int thisMin=INT_MAX;
	   for (j=0; j<numberOfDenominations; j++) {
		   if (i-coins[j]<0) { dpArray[i][j]=-1; continue; }
		   if (stepMinima[i-coins[j]]==INT_MAX) dpArray[i][j]=INT_MAX;
		   else dpArray[i][j] =  1 + stepMinima[i-coins[j]];
		   if (dpArray[i][j] < thisMin) thisMin=dpArray[i][j];
	   }
	   cout << "V=" << i << " #of coins=" << thisMin << endl;
	   stepMinima[i]=thisMin;
   }
   return stepMinima[change];
}
 
int main() {
    int coins[] =  {1,5,9,10};
    int change = 27;
    int result = minCoins(coins, change, sizeof(coins)/sizeof(int));
    if (result==INT_MAX) cout << "Cannot change " << change << " into coins with these denominations." << endl;
    else cout << "Minimum # of coins = " << result;
    
    
}
