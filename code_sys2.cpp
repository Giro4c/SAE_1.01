#include <iostream>
#include <vector>
using namespace std;

void triDoubleVectAssocies (vector<string> & tabOptions, vector<unsigned> & tabCpt)
{
    for (size_t i (0); i < tabCpt.size(); ++i)
    {
        for (size_t j (0); j < tabCpt.size()-1; ++j)
        {
            if (tabCpt[j] < tabCpt[j+1]){
                //Tri vectorCpt
                swap(tabCpt[j], tabCpt[j+1]);

                //Tri vectorOptions
                swap(tabOptions[j], tabOptions[j+1]);
            }
        }
    }
}

/* Le programme prends en compte les votes blancs et arrondi les calculs à l'entier inférieur pour les divisions
car les variables utilisées dans dans celles-ci sont de type entiers_naturels (unsigned).
Aussi, les égalités entre les 2e, 3e et 4e options ne sont pas prises en compte donc ce sera la première des ces options
lues qui sera retenue pour un deuxième tour*/

int main()
{
    string vote;
    vector<string> tabOptions {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    vector<unsigned> tabCpt (tabOptions.size());
    unsigned nbVotants (0);
    while (true)
    {
        getline(cin, vote);
        if (vote == "-") break;
        if (vote == "1")
            ++tabCpt[0];
        if (vote == "2")
            ++tabCpt[1];
        if (vote == "3")
            ++tabCpt[2];
        if (vote == "4")
            ++tabCpt[3];
        ++nbVotants;
    }
    triDoubleVectAssocies (tabOptions, tabCpt);
    if ( ((tabCpt[0]*100) / nbVotants) >= 50 && tabCpt[0] > tabCpt[1]) // Permet de détecter s'il y a ou non une égalitée non détectée par la 1ere condition
    {
        cout << "Victoire par majorité absolue : " << tabOptions[0] << " avec environ " << ((tabCpt[0]*100) / nbVotants) << " % " << "des votes";
    }
    else
    {
        // Deuxième tour
        //Réinitialisation des compteurs
        tabOptions.resize(2);
        tabCpt.resize(2);
        tabCpt[0] = 0;
        tabCpt[1] = 0;
        //Lecture des votes (choix entre 1 et 2 nouveaus nums des options retenues pour le tour)
        while (true)
        {
            getline(cin, vote);
            if (cin.eof()) break;
            if (vote == "1")
                ++tabCpt[0];
            if (vote == "2")
                ++tabCpt[1];
        }
        //Déclaration du gagnant en comparant les compteurs de 1 et 2
        if (tabCpt[0] > tabCpt[1])
            cout << "Victoire par deuxième tour : " << tabOptions[0] << " avec " << tabCpt[0] << " votes";
        else if (tabCpt[0] < tabCpt[1])
            cout << "Victoire par deuxième tour : " << tabOptions[1] << " avec " << tabCpt[1] << " votes";
        else
            cout << "Egalité entre " << tabOptions[0] << " et " << tabOptions[1] << ", pas de gagnant";
    }
    return 2;
}
