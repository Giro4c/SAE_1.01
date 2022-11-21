// Fonction trigger de test

bool test (const string & nomFichSys, const string & nomFichOracle)
{
    ifstream ifsTest;
    ifstream ifsOracle;
    ifsTest.open(nomFichSys);
    ifsOracle.open(nomFichOracle);
    string lineTest;
    string lineOracle;
    while (true){
        getline(ifsTest, lineTest);
        getline(ifsOracle, lineOracle);
        if (ifsOracle.fail() == true) break;
        if (lineTest != lineOracle)
            return false;
    }
    return true;
}