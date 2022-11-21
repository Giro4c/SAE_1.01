// Systeme 4 : Scrutin proportionnel

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void triDoubleVectAssocies (vector<string> & vectorOptions, vector<unsigned> & vectorCpt)
{
    unsigned tmpVal;
    string tmpStr;
    for (unsigned i (0); i < vectorCpt.size(); ++i)
    {
        for (unsigned j (0); j < vectorCpt.size(); ++j)
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

int voteProportionnel (vector<string> & vectorOptions, ifstream & ifs)
{
    vector<unsigned> vectorCpt (4);
    string optVote;
    while (ifs.eof() == false){
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
        }
    triDoubleVectAssocies(vectorOptions, vectorCpt);
    ofstream ofs;
    ofs.open("resultS4.txt");
    ofs << "Resultat du scrutin par systeme proportionnel :" << endl;
    unsigned rank (1);
    for (size_t i (0); i < vectorOptions.size(); ++i)
    {
        ofs << rank << ". " << vectorOptions[i] << " : " << vectorCpt[i] << endl;
        if (i < vectorOptions.size() && vectorCpt[i+1] == vectorCpt[i]) continue;
        ++rank;
    }
    return 4;
}

int main()
{
    vector<string> vectorOptions {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    ifstream ifs;
    ifs.open("vote.txt");
    voteProportionnel(vectorOptions, ifs);
    return 0;
}
