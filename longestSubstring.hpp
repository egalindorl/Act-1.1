
#include <iostream>
#include <string.h>
using namespace std;
 

//x y y son strings, m y n longitud de de cada string
// void longestCommon(string X, string Y, int lineX, int lineY)
// {
//     int m = X.length();
//     int n = Y.length();    
    
//     //matriz para ir marcando longitud
//     int LCSuff[m + 1][n + 1];
//     //longitud max encontrada 
//     int result = 0; 
    
    
//     for (int i = 0; i <= m; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
            
//             if (i == 0 || j == 0)
//                 LCSuff[i][j] = 0;

//             //comparcion de combinaciones
//             else if (X[i - 1] == Y[j - 1]) {
//                 LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
//                 //si la longitud es maxima se guarda en result
//                 result = max(maxLenSubstring, LCSuff[i][j]);
//             }
//             else
//                 LCSuff[i][j] = 0;


//             if ( maxLenSubstring < result) {
//                 maxLenSubstring = result;
//                 if(i < j){
//                     posSubstring = i;
//                     lineSubstring = lineX;
//                 }else{
//                     posSubstring = j;
//                     lineSubstring = lineY;
//                 }

//             }
           
//         }
//     }
   
     

// }
 
