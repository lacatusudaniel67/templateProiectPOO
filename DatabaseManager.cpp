#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const std::string& numeFisier) : db(nullptr), dbName(numeFisier) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Eroare la deschiderea bazei de date: " << sqlite3_errmsg(db) << "\n";
    } else {
        creeazaTabele();
    }
}

DatabaseManager::~DatabaseManager() {
    if (db) {
        sqlite3_close(db);
    }
}

void DatabaseManager::creeazaTabele() {
    const char* sqlEvenimente = 
        "CREATE TABLE IF NOT EXISTS evenimente ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "nume TEXT NOT NULL,"
        "data TEXT NOT NULL);";

    const char* sqlBilete = 
        "CREATE TABLE IF NOT EXISTS bilete ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "eveniment_id INTEGER NOT NULL,"
        "tip TEXT NOT NULL,"
        "pret REAL NOT NULL,"
        "FOREIGN KEY (eveniment_id) REFERENCES evenimente(id) ON DELETE CASCADE);";

    char* mesajEroare = nullptr;
    
    if (sqlite3_exec(db, sqlEvenimente, nullptr, nullptr, &mesajEroare) != SQLITE_OK) {
        std::cerr << "Eroare creare tabel evenimente: " << mesajEroare << "\n";
        sqlite3_free(mesajEroare);
    }

    if (sqlite3_exec(db, sqlBilete, nullptr, nullptr, &mesajEroare) != SQLITE_OK) {
        std::cerr << "Eroare creare tabel bilete: " << mesajEroare << "\n";
        sqlite3_free(mesajEroare);
    }
}

bool DatabaseManager::adaugaEveniment(const std::string& nume, const std::string& data) {
    std::string sql = "INSERT INTO evenimente (nume, data) VALUES ('" + nume + "', '" + data + "');";
    char* mesajEroare = nullptr;
    
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mesajEroare) != SQLITE_OK) {
        std::cerr << "Eroare adaugare eveniment: " << mesajEroare << "\n";
        sqlite3_free(mesajEroare);
        return false;
    }
    return true;
}

std::vector<EvenimentData> DatabaseManager::extrageToateEvenimentele() {
    std::vector<EvenimentData> lista;
    const char* sql = "SELECT id, nume, data FROM evenimente;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            EvenimentData ev;
            ev.id = sqlite3_column_int(stmt, 0);
            ev.nume = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            ev.data = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            lista.push_back(ev);
        }
    }
    sqlite3_finalize(stmt);
    return lista;
}

bool DatabaseManager::adaugaBilet(int evenimentId, const std::string& tip, double pret) {
    std::string sql = "INSERT INTO bilete (eveniment_id, tip, pret) VALUES (" 
                      + std::to_string(evenimentId) + ", '" 
                      + tip + "', " 
                      + std::to_string(pret) + ");";
                      
    char* mesajEroare = nullptr;
    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &mesajEroare) != SQLITE_OK) {
        std::cerr << "Eroare adaugare bilet: " << mesajEroare << "\n";
        sqlite3_free(mesajEroare);
        return false;
    }
    return true;
}

std::vector<BiletData> DatabaseManager::extrageBiletePentruEveniment(int evenimentId) {
    std::vector<BiletData> listaBilete;
    std::string sql = "SELECT tip, pret FROM bilete WHERE eveniment_id = " + std::to_string(evenimentId) + ";";
    
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            BiletData b;
            b.tip = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            b.pret = sqlite3_column_double(stmt, 1);
            listaBilete.push_back(b);
        }
    }
    sqlite3_finalize(stmt);
    return listaBilete;
}

bool DatabaseManager::stergeUltimulEveniment() {
    const char* sql = "DELETE FROM evenimente WHERE id = (SELECT MAX(id) FROM evenimente);";
    char* mesajEroare = nullptr;
    
    if (sqlite3_exec(db, sql, nullptr, nullptr, &mesajEroare) != SQLITE_OK) {
        sqlite3_free(mesajEroare);
        return false;
    }
    return true;
}

template <>
int DatabaseManager::extrageOValoare<int>(const std::string& query) {
    int rezultat = 0;
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            rezultat = sqlite3_column_int(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);
    return rezultat;
}