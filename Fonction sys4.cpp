// Systeme 4 : Scrutin proportionnel

#include <iostream>
#include <fstream>
using namespace std;

int voteProportionnel (const vector<string> & vectorOptions, ifstream & ifs)
{
    vector<string> vectorCpt {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    string optVote;
    while (ifs.eof() == false){
        getline(ifs, optVote);
        switch (optVote)
        {
            case "1":
                ++vectorCpt[0];
                break;
            case "2":
                ++vectorCpt[1];
                break;
            case "3":
                ++vectorCpt[2];
                break;
            case "4":
                ++vectorCpt[3];
                break;
        }
    }
    ofs.open("resultS4.txt");
    ofs << "Resultat du scrutin par systeme proportionnel" : << endl;
    for (unsigned i (0); i < vectorOptions.size(); ++i)
        ofs << i+1 << ". " << vectorOptions[i] << " : " << vectorCpt[i] << endl;
    return 4;
}