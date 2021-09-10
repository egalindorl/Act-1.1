#include <iostream>
#include <fstream>
//libreria para unir chars con strings
#include <sstream>

#include <vector>

#include "longestSubstring.hpp"
#include "B_M.hpp"
#include "match.hpp"

using namespace std;

// global variable para palindromos
int counter = 0;
int pos = 0;
int line = 0;

//variables para idenfitcacion de la subcadena mas larga
int maxLenSubstring = 0;
int posSubstring = 0;
int lineSubstring = 0;

void longestCommon(string X, string Y, int lineX, int lineY)
{
    int m = X.length();
    int n = Y.length();    
    
    //matriz para ir marcando longitud
    int LCSuff[m + 1][n + 1];
    //longitud max encontrada 
    int result = 0; 
    
    
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            //comparcion de combinaciones
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                //si la longitud es maxima se guarda en result
                result = max(maxLenSubstring, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;


            if ( maxLenSubstring < result) {
                maxLenSubstring = result;
                if(i < j){
                    posSubstring = i - result ;
                    lineSubstring = lineX;
                }else{
                    posSubstring = j - result ;
                    lineSubstring = lineY ;
                }

            }
           
        }
    } 

}
 
//s: string evaluada desde la mitad
int longestPalindromeMiddle(string s, int left, int right){
    //en caso de que no haya string
    if(s.empty()){return 0;}
    //checar si si es correcto acceder asi a un caracter
    //si left y right son espejos, se seguira recorreindo hacia afuera del centro
    while( (left >= 0) && (right < s.length()) && (s[left] == s[right])){
        left--; 
        right++;
    }
    //se regresara la longitud del palindromo y posicion inicial
    
    return right - left + 1;
}

//se le pasará cada linea y ¿¿¿numero de linea????
void longestPalindrome(string s, int lineNumber){
    
    int start = 0; 
    int end = 0;
    int len = 0;
    for(int i=0; i < s.length(); i++){

        int len1 = longestPalindromeMiddle(s,i,i);
        int len2 = longestPalindromeMiddle(s,i,i+1);
        
        len = max(len1,len2);
        if (len > end - start){
            //esto debe de devovler un numero entero y no decimal, checar
            //calcula la posicion 
            start = i - ((len-1)/2);
            end = i + (len/2);
        }

    }

    if (counter < end-start) {
        counter = end-start;
        pos = start;
        line = lineNumber;
    }

    //cout << lineNumber <<" " << start << " " << end-start << endl;

}
//se podria regresar vector con linea, posicion inicial (left) y tamaño
//o se puede hacer void y simplemente regresar esos 3 valores impresos
int main()
{
    vector<string> transmissions{"transmission1.txt","transmission2.txt"};
    vector<string> mcodes{"mcode1.txt","mcode2.txt","mcode3.txt"};

    for (int i=0;i<transmissions.size();i++)
    {
        int _temp_line=0;
        vector<string> transmission;
        ifstream file(transmissions[i]);

        string trans_line;
        if (file.is_open())
        {
            // mientras siga habiendo texto se sigue leyendo el archivo
            //instancia de stringstream para type-cast de char a string lo que se lea del archivo
            while ( file ) {
                getline(file,trans_line);
                // cout<<"line: "<<_temp_line<<endl;
                // cout<<trans_line<<endl<<endl;
                transmission.push_back(trans_line);

                _temp_line++;
            }
        }

        for (int j=0; j<mcodes.size(); j++) {
            vector<Match> matches;
            int finds=0;
            int line=0;
            string mcode;
            ifstream mcode_file(mcodes[j]);
            if (mcode_file.is_open()) {
                mcode_file >> mcode;
            }

            for (int k=0;k<transmission.size();k++) {
                vector<int> temp;
                temp= B_M(transmission[k], mcode);
                if (temp.size()>0){
                    for (int _t=0;_t<temp.size();_t++) {
                    matches.push_back(Match(line,temp[0]));}
                }
                line++;
                }

            if (matches.size()>0) {
                for (int _m=0;_m<matches.size();_m++) {
                    finds++;
                    cout<<matches[_m];
                    }
                }
            else
            cout<<"false"<<endl;

            
            // cout<<endl;

            }
            for (int j=0;j<transmission.size();j++) {
               
               longestPalindrome(transmission[j],j);
            }

            //checar orden 
            cout <<line <<" " << pos <<" "<< counter <<endl;

    }
    string X = "GeeksforGeeks";
    string y = "QuizGeeks";
    longestCommon(X, y, 1, 1);
    cout << "len :" << maxLenSubstring << endl;
    cout << "pos :" << posSubstring << endl;
    cout << "line :" << lineSubstring << endl;
}

