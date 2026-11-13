#include "uincampus/regles.hpp"
namespace uin {
bool estNoteValide(double n) { return n >= noteMin && n <= noteMax; }
Mention mentionPour(double m) {
  if (m < 10.0) return Mention::Ajourne;
  if (m < 12.0) return Mention::Passable;
  if (m < 14.0) return Mention::AssezBien;
  if (m < 16.0) return Mention::Bien;
  return Mention::TresBien;
}
std::string libelle(Mention m) {
  switch (m) {
    case Mention::Ajourne: return "Ajourne";
    case Mention::Passable: return "Passable";
    case Mention::AssezBien: return "Assez Bien";
    case Mention::Bien: return "Bien";
    case Mention::TresBien: return "Tres Bien";
  }
  return "";
}
}
