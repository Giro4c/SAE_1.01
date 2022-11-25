// Déclaration de la matrice des options et compteurs

typedef vector<string> OptLine;
typedef vector<OptLine> OptMatrix;
typedef vector<unsigned> CptLine;
typedef vector<CptLine> CptMatrix;

int main()
{
    //Déclarations des matrices options et compteurs
    OptLine lineOptions {"Conterstrike", "Street Fighter II", "Civilization VI", "Mario Kart"};
    OptMatrix matOptions (lineOptions.size(), lineOptions);
    CptMatrix matCompteurs (matOptions.size(), CptLine (lineOptions.size()))
    
    while (true)
    {
        for (size_t i (0); i < lineOptions.size(); ++i)
            getline(cin, vote);
            if (vote == "1")
                ++matCompteurs[i][0];
            if (vote == "2")
                ++matCompteurs[i][1];
            if (vote == "3")
                ++matCompteurs[i][2];
            if (vote == "4")
                ++matCompteurs[i][3];
    }

    for (size_t i (0); i < matCompteur.size(); ++i)
    {
        for (size_t j (0); j < lineOptions.size(); ++j){
            cout << matCompteurs[i][j] << " ";
        }
        cout << endl;
    }
}
