#ifndef ANO_H
#define ANO_H

class Ano{
    vector<Escalao *> escaloes;
    unsigned int ano;

public:
    Ano();
    Ano(uint ano);
    vector<Escalao *> getEscalao() const;

};


#endif