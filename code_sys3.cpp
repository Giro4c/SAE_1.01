#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//Declaration du struct pour creer des objets possedant les memes proprietes.
struct jeux
{
    unsigned position_1 = 0;
    unsigned position_2 = 0;
    unsigned position_3 = 0;
    unsigned position_4 = 0;
    unsigned rang = 1;
    string nom;
};

//Declaration d'une fonction pour trier un tableau de "jeux"
bool ordreRang (const jeux & j1, const jeux & j2)
{
    return j1.rang < j2.rang || j1.rang == j2.rang;
}



int main()
{
    //Creation des differents objets "jeux"
    jeux CounterStrike; // jeu 1
    CounterStrike.nom = "CounterStrike";
    jeux StreetFighter; // jeu 2
    StreetFighter.nom = "StreetFighter";
    jeux CivilizationVI; // jeu 3
    CivilizationVI.nom = "CivilizationVI";
    jeux MarioKart; // jeu 4
    MarioKart.nom = "MarioKart";
    string str;
    unsigned compteur = 0;

    cout << "Lecture du fichier..." << endl;

    while(true){
        getline(cin, str);
        if (str[0] == '1')
           ++CounterStrike.position_1;
        else if (str[0] == '2')
           ++StreetFighter.position_1;
        else if (str[0] == '3')
           ++CivilizationVI.position_1;
        else if (str[0] == '4')
           ++MarioKart.position_1;

        if (str[1] == '1')
           ++CounterStrike.position_2;
        else if (str[1] == '2')
           ++StreetFighter.position_2;
        else if (str[1] == '3')
           ++CivilizationVI.position_2;
        else if (str[1] == '4')
           ++MarioKart.position_2;

        if (str[2] == '1')
           ++CounterStrike.position_3;
        else if (str[2] == '2')
           ++StreetFighter.position_3;
        else if (str[2] == '3')
           ++CivilizationVI.position_3;
        else if (str[2] == '4')
           ++MarioKart.position_3;

        if (str[3] == '1')
           ++CounterStrike.position_4;
        else if (str[3] == '2')
           ++StreetFighter.position_4;
        else if (str[3] == '3')
           ++CivilizationVI.position_4;
        else if (str[3] == '4')
           ++MarioKart.position_4;

        if (cin.eof() == true) break;

        ++compteur;
    }

    cout << "Fin de lecture du fichier." <<"\n"<<endl;
    cout << "Nombre de votes: " << compteur <<endl;
    cout << "Nombre de position 1 pour CounterStrike : " << CounterStrike.position_1 <<endl;
    cout << "Nombre de position 1 pour StreetFighter : " << StreetFighter.position_1 <<endl;
    cout << "Nombre de position 1 pour CivilizationVI : " << CivilizationVI.position_1 <<endl;
    cout << "Nombre de position 1 pour MarioKart : " <<MarioKart.position_1 <<"\n"<<endl;

    if (CounterStrike.position_1 > compteur/2){
        cout << "CounterStrike est le gagnant !"<< endl;
    }
    else if (StreetFighter.position_1 > compteur/2){
        cout << "StreetFighter est le gagnant !"<< endl;
    }
    else if (CivilizationVI.position_1 > compteur/2){
        cout << "CivilizationVI est le gagnant !"<< endl;
    }
    else if (MarioKart.position_1 > compteur/2){
        cout << "MarioKart est le gagnant !"<< endl;
    }
    else
        cout << "Il n'y a pas de gagnant !"<<endl;

    vector <jeux> nbrPosJeux = {CounterStrike, StreetFighter, CivilizationVI, MarioKart};   //Creation d'un tableau de jeux
    for (unsigned i(0); i < nbrPosJeux.size(); ++i){    //Attribution des rangs
        for (unsigned j (i+1); j < nbrPosJeux.size(); ++j){
            if (nbrPosJeux[j].position_1 == nbrPosJeux[i].position_1) continue;
            if (nbrPosJeux[j].position_1 > nbrPosJeux[i].position_1){
                ++nbrPosJeux[i].rang;
            }
           else{
                ++nbrPosJeux[j].rang;
           }
        }
    }
    CounterStrike.rang = nbrPosJeux[0].rang;
    StreetFighter.rang = nbrPosJeux[1].rang;
    CivilizationVI.rang = nbrPosJeux[2].rang;
    MarioKart.rang = nbrPosJeux[3].rang;

    cout <<"\n"<< "Rang de CounterStrike: " << CounterStrike.rang << endl;
    cout << "Rang de StreetFighter: " << StreetFighter.rang << endl;
    cout << "Rang de CivilizationVI: " << CivilizationVI.rang << endl;
    cout << "Rang de MarioKart: " << MarioKart.rang << endl;

    vector<jeux> vJeux = {CounterStrike, StreetFighter, CivilizationVI, MarioKart};
    sort(vJeux.begin(), vJeux.end(), ordreRang);    //Appel de la fonction "odreRang" pour trier le tableau vJeux

    cout <<"\n"<< "Classement des jeux : "<<endl;
    cout << "Position "<< vJeux[0].rang <<": "<< vJeux[0].nom <<endl;
    cout << "Position "<< vJeux[1].rang <<": "<< vJeux[1].nom<<endl;
    cout << "Position "<< vJeux[2].rang <<": "<< vJeux[2].nom<<endl;
    cout << "Position "<< vJeux[3].rang <<": "<< vJeux[3].nom<<endl;

    return 0;
}
