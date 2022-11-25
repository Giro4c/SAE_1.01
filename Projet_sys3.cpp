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
            // if (vote == "-") break;
            if (vote == "1")
                ++tabCpt[i][0];
            if (vote == "2")
                ++tabCpt[i][1];
            if (vote == "3")
                ++tabCpt[i][2];
            if (vote == "4")
                ++tabCpt[i][3];
    }
}