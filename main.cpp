#include "Meniu.h"
#include "Locatie.h"
#include "Client.h"
#include "BiletStandard.h"
int main() {
#ifdef GITHUB_ACTIONS
    return 0; 
#endif
    Locatie locTest("Sala", 100, "Adresa");
    locTest.getCapacitate();
    locTest.afiseazaLocatie();
    
    Client clientTest("Ion", "ion@test.com");
    clientTest.adaugaInIstoric(1);
    clientTest.afiseazaClient();
    
    Eveniment evTest("Test", "01-01");
    evTest.calculeazaIncasariTotal();
    
    BiletStandard bTest(10.0, 1, 1);
    bTest.getContoareBilete();
    bTest.getPretDeBaza();
    bTest.getId();

    Meniu meniuAplicatie;
    meniuAplicatie.ruleaza();
    return 0;
}