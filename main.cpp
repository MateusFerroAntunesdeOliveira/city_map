#include <iostream>
#include "mapa.cpp"
#include "mapa.h"

using namespace std;

int main() {
    Mapa mapa;

    mapa.addCidade("Londrina");
    mapa.addCidade("Itarare");
    mapa.addCidade("Sao Paulo");
    mapa.addCidade("Registro");
    mapa.addCidade("Curitiba");
    mapa.addCidade("Ponta Grossa");
    mapa.addCidade("Porto Uniao");
    mapa.addCidade("Mafra");
    mapa.addCidade("Joinville");
    mapa.addCidade("Blumenau");
    mapa.addCidade("Itajai");
    mapa.addCidade("Florianopolis");
    mapa.addCidade("Lages");

    mapa.une("Londrina", "Itarare", 310);
    mapa.une("Londrina", "Ponta Grossa", 271);
    mapa.une("Itarare", "Sao Paulo", 342);
    mapa.une("Itarare", "Curitiba", 208);
    mapa.une("Itarare", "Ponta Grossa", 174);
    mapa.une("Curitiba", "Ponta Grossa", 114);
    mapa.une("Curitiba", "Mafra", 115);
    mapa.une("Curitiba", "Joinville", 132);
    mapa.une("Registro", "Curitiba", 221.2);
    mapa.une("Registro", "Sao Paulo", 185.9);
    mapa.une("Mafra", "Joinville", 136);
    mapa.une("Mafra", "Blumenau", 165);
    mapa.une("Mafra", "Ponta Grossa", 155);
    mapa.une("Porto Uniao", "Mafra", 143);
    mapa.une("Porto Uniao", "Ponta Grossa", 209);
    mapa.une("Porto Uniao", "Lages", 271);
    mapa.une("Lages", "Mafra", 349);
    mapa.une("Lages", "Blumenau", 223);
    mapa.une("Lages", "Florianopolis", 231);
    mapa.une("Itajai", "Florianopolis", 102);
    mapa.une("Itajai", "Blumenau", 52.3);
    mapa.une("Itajai", "Joinville", 86.2);

    return 0;
}
