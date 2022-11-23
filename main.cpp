#include <iostream>
#include <vector>
using namespace std;

size_t voteGagnant(const vector<unsigned> & tabVotes)
{
    unsigned indiceVoteMax(0);
    for (size_t i (0); i < tabVotes.size()-1; ++i)
    {
        if (tabVotes[i] == tabVotes[indiceVoteMax]){

        }
        if (tabVotes[i] > tabVotes[indiceVoteMax])
            indiceVoteMax = i;
    }
    return indiceVoteMax;
}

int main()
{
    // 1: CounterStrike
    // 2: StreetFighter
    // 3: Civilization
    // 4: MarioKart
    vector<string> tabJeux {"CounterStrike", "StreetFighter II", "Civilization VI", "Mario Kart"};
    vector<unsigned> tabVotes (tabJeux.size());
    string vote; // variable temporaire des votes
    unsigned nbVotants (0);
    while (true)
    {
        getline(cin,vote);
        if (vote == "1")
        {
            ++tabVotes[0];
        }
        else if (vote == "2")
        {
            ++tabVotes[1];
        }
        else if (vote == "3")
        {
            ++tabVotes[2];
        }
        else if (vote == "4")
        {
            ++tabVotes[3];
        }
        if (cin.eof()) break;
        ++nbVotants;
    }
    cout << "Résultat du scrutin :" << endl;
    cout << "Nb Votants : " << nbVotants << endl;
    size_t indiceVoteMax (voteGagnant(tabVotes));
    cout << "Gagnant : " << tabJeux[indiceVoteMax] << tabVotes[indiceVoteMax] << endl;
    return 0;
}
