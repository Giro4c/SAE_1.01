// Systeme 4 : Scrutin proportionnel

#include <iostream>
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
                swap(vectorCpt[j], vectorCpt[j+1]);

                //Tri vectorOptions
                swap(vectorOptions[j], vectorOptions[j+1]);
            }
        }
    }
}

/*
void afichVector (const vector<unsigned> & vectTab)
{
    for (size_t i (0); i < vectTab.size(); ++i)
        cout << vectTab[i] << endl;
}
*/

// Systeme vote proportionnel
int main()
{
    vector<string> vectorOptions {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    vector<unsigned> vectorCpt (vectorOptions.size);
    string optVote;
    while (true){
        getline(cin, optVote);
        // Equivalent switch/case
            if (optVote == "1")
                ++vectorCpt[0];
            else if (optVote == "2")
                ++vectorCpt[1];
            else if (optVote == "3")
                ++vectorCpt[2];
            else if (optVote == "4")
                ++vectorCpt[3];
            if ((cin.eof() == true)) break;
        }
    // Verif de l'etat de vectorCpt
    //afichVector(vectorCpt);
    triDoubleVectAssocies(vectorOptions, vectorCpt);
    // Verif de l'etat de vectorCpt après appel de procedure
    //afichVector(vectorCpt);

    cout << "Resultat du scrutin par systeme proportionnel :" << endl;
    unsigned rank (1);
    for (size_t i (0); i < vectorOptions.size(); ++i)
    {
        cout << rank << ". " << vectorOptions[i] << " : " << vectorCpt[i] << endl;
        if (i < vectorOptions.size() && vectorCpt[i+1] == vectorCpt[i]) continue;
        ++rank;
    }
    return 0;
}