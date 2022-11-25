#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 1: CounterStrike
    // 2: StreetFighter
    // 3: Civilization
    // 4: MarioKart
    vector<string> tabJeux {"CounterStrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    vector<unsigned> tabVotes (tabJeux.size());
    string vote; // variable temporaire des votes
    unsigned nbVotants (0);
    while (true)
    {
        getline(cin,vote);
        if (vote == "1")
            ++tabVotes[0];
        else if (vote == "2")
            ++tabVotes[1];
        else if (vote == "3")
            ++tabVotes[2];
        else if (vote == "4")
            ++tabVotes[3];
        if (cin.eof() == true) break;
        ++nbVotants;
    }
    size_t indiceVoteMax(0);
    bool egalite = false;
    for (size_t i (0); i < tabVotes.size(); ++i)
    {
        if (tabVotes[i] > tabVotes[indiceVoteMax])
        {
            egalite = false;
            indiceVoteMax = i;
        }
        else if (tabVotes[i] > tabVotes[indiceVoteMax])
            egalite = false;
        else if (tabVotes[i] == tabVotes[indiceVoteMax])
            egalite = true;
        // cout << i << " " << egalite << endl; --> en cas de problème d'affichage pour vérifier valeur de egalite

    }
    cout << "Résultat du scrutin :" << endl;
    cout << "Nb Votants : " << nbVotants << endl;
    if (egalite == false)
    {
        cout << "Gagnant : " << tabJeux[indiceVoteMax] << " avec "<< tabVotes[indiceVoteMax] << " votes." << endl;
    }
    else
    {
        cout << "Il y a une égalité de " << tabVotes[indiceVoteMax] << " votes entre :" << endl;
        for (size_t i (0); i < tabVotes.size(); ++i){
            if (tabVotes[i] == tabVotes[indiceVoteMax])
                cout << tabJeux[i] << endl;
        }
    }

    return 0;
}
