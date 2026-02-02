## ProjektC++_2023_MW
Projekt C++ 2023/2024 Mateusz Wójcicki

Podjąłem decyzję, że nie podołam na tym etapie prowadzenia projektu w Unreal Engine 5. 
W związku z czym zajmę się tworzeniem mojej adaptacji kiedyś popularnej gry sieciowej "Age of war" (przykładowy link: https://onlygames.io/gry/tower-defense/age-of-war.html)

Nazwa mojej gry: "Battle of Strongholds"


## Technologie:
* C++ pisany w VS Code
* SFML
* GIMP

## Źródła:
Tekstury:
* https://opengameart.org/art-search?keys=grass
* https://www.kindpng.com/downpng/TiRwRmo_pixel-art-paper-scroll-transparent-hd-png-download/
* https://deepai.org/machine-learning-model/pixel-art-generator
* https://www.freepik.com/
* https://www.deviantart.com/

Pomoc techniczna:
* https://www.youtube.com/watch?v=C_ZStbJx5uU
* https://www.youtube.com/watch?v=m4cZ1QJzwt4&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=28
* https://www.youtube.com/watch?v=9ByrrZqvyPA&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=37
* https://www.youtube.com/watch?v=1ND_VRJChO4
* https://www.youtube.com/watch?v=zbi6WsscXuI&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=11&t=352s
* https://www.youtube.com/watch?v=sr8w9z8BCdk&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=12&t=278s
* https://www.youtube.com/watch?v=yWLkyN_Satk&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=12&t=388s&
* https://www.youtube.com/watch?v=4Vg9d1pjL20&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=17&t=13s&pp=gAQBiAQB
* https://www.youtube.com/watch?v=kxb0GvBNOGU&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=23
* https://www.youtube.com/watch?v=7QBUqLdCV1g&list=PLNFVCuP2zrLJbEwGjeqJmjY1woQBlouX1&index=24&t=485s&pp=gAQBiAQB

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

example c_cpp_properties.json:
{
    "configurations": [
        {
            "name": "windows-clang-x64",
            "includePath": [
                "${workspaceFolder}/**",
                "D:\\sth\\SFML-2.6.1\\include"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.22000.0",
            "compilerPath": "C:/mingw64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-clang-x64"
        }
    ],
    "version": 4
}

* To compile project you need to change directory to Source_files (ex. in powershell) 'cd .\Source_files\'
* Then you can build project using command 'make' (or on windows 'mingw32-make')
* Game is ready to start! Just open Game.exe in Source_files folder and start playing :)
