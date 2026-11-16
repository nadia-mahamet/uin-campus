#include "uincampus/calculs.hpp"
#include "uincampus/regles.hpp"
#include "uincampus/saisie.hpp"
#include "uincampus/version.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
namespace {
void afficherLigne(std::string_view libelle, const std::string &valeur) {
    std::cout << std::left << std::setw(24) << libelle << std::right
              << std::setw(20) << valeur << "\n";
}
std::string fmt(double v) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << v;
    return oss.str();
}
} // namespace
int main(int argc, char *argv[]) {
    if (argc > 1 && std::string_view{argv[1]} == "--version") {
        std::cout << "uin-campus " << uin::version() << "\n";
        return EXIT_SUCCESS;
    }
    std::cout << "UIN-Campus " << uin::version()
              << " - Releve d'un etudiant\n\n";
    const std::string nom = uin::lireTexte("Nom de l'etudiant : ");
    const int nbUE = uin::lireEntier("Nombre d'UE (1 a 30) : ", 1, 30);
    std::vector<double> notes;
    std::vector<double> coefficients;
    for (int i{1}; i <= nbUE; ++i) {
        notes.push_back(
            uin::lireNote("Note de l'UE " + std::to_string(i) + " : "));
        coefficients.push_back(static_cast<double>(uin::lireEntier(
            "Coefficient de l'UE " + std::to_string(i) + " : ", 1, 10)));
    }
    const double moyenneGenerale =
        uin::arrondir(uin::moyenne(notes, coefficients));
    const auto [mini, maxi, moyenneSimple, ecartType] =
        uin::calculerStatistiques(notes);
    const int validees = uin::compterValidees(notes);
    std::cout << "\n--------------------------------------------\n";
    afficherLigne("Etudiant", nom);
    afficherLigne("Moyenne ponderee", fmt(moyenneGenerale));
    afficherLigne("Moyenne simple", fmt(moyenneSimple));
    afficherLigne("Note min / max", fmt(mini) + " / " + fmt(maxi));
    afficherLigne("Ecart-type", fmt(ecartType));
    afficherLigne("UE validees",
                  std::to_string(validees) + " / " + std::to_string(nbUE));
    afficherLigne("Mention", uin::libelle(uin::mentionPour(moyenneGenerale)));
    std::cout << "--------------------------------------------\n";
    return EXIT_SUCCESS;
}
