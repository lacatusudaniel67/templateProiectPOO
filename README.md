PROIECT POO- SISTEM DE GESTIUNIE:AGENTIE DE TICKETING
  Descrierea proiectului:
  Aceasta aplicatie dezvoltata in C++ simuleaza sistemul unei agentii de ticketing.
  Aplicația permite crearea de evenimente, vânzarea mai multor tipuri de bilete (Standard, VIP, Redus, Abonamente) și gestionarea acestora printr-un meniu interactiv.

  Funcționalități Principale (CRUD)
  Aplicația are un meniu interactiv cu următoarele opțiuni:
     create:Adaugarea de evenimente noi în portofoliul agentiei si emiterea de bilete pentru acestea.
     read:Vizualizarea bazei de date cu toate evenimentele și detaliile biletelor vândute.
     update:Modificarea detaliilor unui eveniment existent (de ex: schimbarea numelui).
     delete:Anularea și eliminarea logică a evenimentelor din sistem.
  Concepte din POO implementate:
     1.incapsularea datelor: 
       toate atributele claselor sunt ascunse
     2.mostenirea si diamantul: 
       Clasa de bază: `Bilet`
       Clase derivate simple: `BiletStandard`, `BiletRedus`
       Moștenire Multipla (Diamant): Clasele `BiletVIP` si `BiletAbonament`mostenesc clasa `Bilet` folosind cuvântul cheie `virtual`. Clasa finală `AbonamentVIP` mostenește ambele ramuri, rezolvand ambiguitatea.
     3.polimorfismul:
       Clasa `Bilet` este o clasa abstracta, având metoda virtuala pura `calculeazaPretFinal() = 0`. In clasa `Eveniment`, biletele sunt stocate ca pointeri catre clasa de bază într-un `std::vector<Bilet*>`.
     4.gestiunea memoriei 
       Deoarece clasa `Eveniment` aloca dinamic memorie pentru bilete, a fost implementată strict "Regula celor 3" pentru a preveni memory leaks :
            Destructor-Elibereaza memoria (folosind `delete` pentru fiecare pointer din vector).
            Constructor de Copiere-Gestionează corect copierea obiectelor.
            Operator de Atribuire (`=`)-Previne suprascrierile accidentale de memorie.
     5.tratarea exceptiilor
            A fost creată clasa `ExceptieTicketing`, derivata din `std::exception`. Validarea input-ului de la utilizator (de ex: introducerea unui preț negativ pentru bilet)
            arunca această exceptie, care este prinsă de blocurile `try-catch` din meniu.
   
