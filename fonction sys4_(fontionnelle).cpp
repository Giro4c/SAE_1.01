// Systeme 4 : Scrutin proportionnel

#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;

void triDoubleVectAssocies (vector<string> & vectorOptions, vector<unsigned> & vectorCpt)
{
    unsigned tmpVal;
    string tmpStr;
    for (size_t i (0); i < vectorCpt.size(); ++i)
    {
        for (size_t j (0); j < vectorCpt.size()-1; ++j)
        {
            if (vectorCpt[j] < vectorCpt[j+1]){
                //Tri vectorCpt
                tmpVal = vectorCpt[j];
                vectorCpt[j] = vectorCpt[j+1];
                vectorCpt[j+1] = tmpVal;

                //Tri vectorOptions
                tmpStr = vectorOptions[j];
                vectorOptions[j] = vectorOptions[j+1];
                vectorOptions[j+1] = tmpStr;
            }
        }
    }
}

void afichVector (const vector<unsigned> & vectTab)
{
    for (size_t i (0); i < vectTab.size(); ++i)
        cout << vectTab[i] << endl;
}

int voteProportionnel (vector<string> & vectorOptions, ifstream & ifs)
{
    vector<unsigned> vectorCpt (4);
    string optVote;
    while (true){
        getline(ifs, optVote);
        // Equivalent switch/case
            if (optVote == "1")
                ++vectorCpt[0];
            else if (optVote == "2")
                ++vectorCpt[1];
            else if (optVote == "3")
                ++vectorCpt[2];
            else if (optVote == "4")
                ++vectorCpt[3];
            if ((ifs.eof() == true)) break;
        }
    // Verif de l'etat de vectorCpt
    //afichVector(vectorCpt);
    triDoubleVectAssocies(vectorOptions, vectorCpt);
    // Verif de l'etat de vectorCpt après appel de procedure
    //afichVector(vectorCpt);

    ofstream ofs ("resultS4.txt");
    if (ofs.fail() == true)
        cerr << "Impossible d'ouvrir/creer le fichier de sortie";
    ofs << "Resultat du scrutin par systeme proportionnel :" << endl;
    unsigned rank (1);
    for (size_t i (0); i < vectorOptions.size(); ++i)
    {
        ofs << rank << ". " << vectorOptions[i] << " : " << vectorCpt[i] << endl;
        if (i < vectorOptions.size() && vectorCpt[i+1] == vectorCpt[i]) continue;
        ++rank;
    }
    ofs.close();

    return 4;
}


int afichFich (ifstream & ifs)
{
    string line;
    while (true){
        getline(ifs, line);
        if (ifs.eof() == true) break;
        cout << line << endl;
    }
    return 2;
}

int main()
{
    vector<string> vectorOptions {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    ifstream ifs;
    ifs.open("vote_1.txt");
    if (ifs.fail() == true)
        cerr << "Impossible d'ouvrir le fichier";
    voteProportionnel(vectorOptions, ifs);
    //ifs.close();
    //afichFich(ifs);
    return 0;
}
