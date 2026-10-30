# UIN-Campus - TP2

## Partie A - Versions (Lenovo ThinkPad T460)
- g++ 13.3.0
- clang++ 18.1.3
- cmake 3.28.3
- ninja 1.11.1
- gdb 15.1
- git 2.43.0
- VS Code + extension C/C++

## Partie B - Editeur et formatage
- VS Code installe (voir capture VS Code)
- .clang-format cree: BasedOnStyle LLVM IndentWidth 4
- Commande: cat .clang-format

## Partie C - Presets et indexation
- CMakePresets.json avec preset debug
- compile_commands.json -> build/debug/compile_commands.json (symlink)
- Commande: ls -l compile_commands.json

## Partie D - Construction
- cmake --preset debug
- cmake --build --preset debug
- ./build/debug/uin-campus
Resultat: UIN-Campus - Systeme de gestion academique Version 0.1.0

