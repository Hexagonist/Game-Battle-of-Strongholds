## ProjektC++_2023_MW
Projekt C++ 2023/2024 Mateusz Wójcicki

Podjąłem decyzję, że nie podołam na tym etapie prowadzenia projektu w Unreal Engine 5. 
W związku z czym zajmę się tworzeniem mojej adaptacji kiedyś popularnej gry sieciowej "Age of war" (przykładowy link: https://onlygames.io/gry/tower-defense/age-of-war.html)


## Technologie:
* C++ pisany w VS Code
* SFML
* potencjalne pomocnicze programy graficzne np. GIMP

## Harmonogram:

[ ] 31.11.2023
* Utworzenie repozytorium, ustawienie środowiska, kontroli wersji oraz narzędzi do pracy.


[ ] 14.11.2023
* Ustawienie SFML
* Odświeżenie wiadomości na temat SFML
* Menu główne
* Utworzenie mapy 
* Utworzenie zamków oraz ich wież obronnych.
* Podstawowe UI


[ ] 28.11.2023
* Podstawowe jednostki 
* Poruszanie się jednostek
* Dodanie pasków zdrowia zamkom oraz jednostkom 
* Reakcja wież na zbliżającego się wroga
* Udoskonalenie UI
* Dodanie liczników czasu, pieniędzy
* Ekran przegranej i wygranej gry
* Pauza gry

[ ] 12.12.2023
* Ekonomia gry (ile monet za likwidacje jednostek wroga, koszty jednostek itd.)
* Utworzenie różnych klas jednostek (np. zwarcie, dystansowa, pancerna)
* Animacje pocisków wystrzelonych przez jednostki, wieże
* Kolejka produkcji jednostek


[ ] 9.01.2023 (Po Świętach)
* Muzyka
* Ulepszenie wieży
* Może ulepszenie jednostek
* Opcjonalne dodatkowe elementy


[ ] 22.01.2023
* Zakończenie projektu
* ostatnie szlify
* debugging.

## Important
W trakcie tworzenia projektu mogą zdarzyć się opóźnienia realizacji niektórych punktów, dlatego w ten sposób rozmieściłem sobie zadania w czasie. 

Please be aware that before Game compilation you must change SFML directories in files: c_cpp_properties.json and Makefile 
to the paths where your SFML is installed.

* To compile project you need to change directory to Project_files (ex. in powershell) 'cd .\Project_files\'
* Then you can build project using command 'make'
* Game is ready to start! Just open Game.exe in Project_files folder and start playing :)