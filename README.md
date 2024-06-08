## Opis
    Ten program został napisany w języku C++ i kompilowany przy użyciu kompilatora g++.

## Wymagania systemowe
 - Kompilator g++
 - Makefile

 Kompilacja
 Aby skompilować program, wykonaj poniższe kroki:

`make` - buduje projekt. W folderze target znajdują się wszystkie pliki .o i tworzy się plik wykonywalny .exe

 Następnie uruchom program, wpisując:

`output.exe [flaga]`

 W miejsce flagi należy podać odpowiednią flagę

    Help            -h - Display help
    Version         -v - Display version
    File            -f - [filename] [Sv] clock - [ss mm hh]
                    example: -f brdc0940.23n 1 30 20 22

## Dodatkowe komendy
- `make clean` - Czyszczenie outputu