#ifnded SENIORES_H
#define SENIORES_H

class Seniores{
    vector<Jogador> jogadores;
    vector<Torneio> torneios;
    string treinador;
    const unsigned int idade_min = 19 , idade_max = 35;
};

#endif