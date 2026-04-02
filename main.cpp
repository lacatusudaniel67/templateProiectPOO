#include "Meniu.h"

int main() {
#ifdef GITHUB_ACTIONS
    return 0; 
#endif
    Meniu meniuAplicatie;
    meniuAplicatie.ruleaza();
    return 0;
}