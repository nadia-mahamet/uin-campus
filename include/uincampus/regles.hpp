#pragma once
#include <string>
namespace uin {
inline constexpr double seuilValidation = 10.0;
inline constexpr double noteMin = 0.0;
inline constexpr double noteMax = 20.0;
enum class Mention { Ajourne, Passable, AssezBien, Bien, TresBien };
bool estNoteValide(double note);
Mention mentionPour(double moyenne);
std::string libelle(Mention m);
}
