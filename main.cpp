#include <iostream>
#include <fstream>
//libreria para unir chars con strings
#include <sstream>

#include <vector>

#include "B_M.hpp"
#include "match.hpp"

using namespace std;

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
}
}
