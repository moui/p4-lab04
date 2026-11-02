# p4-lab04

Final lab ("Laboratorio Implementación", 2021) for **Programación 4**, Facultad de Ingeniería, Universidad de la República (Uruguay).

This is team coursework from June 2021, kept for reference and no longer maintained. The commit history shows several contributors (`moui`, `jprubiocolucci`, `Maxuos4`, `nodescanses`, `NahuelPereyraF`).

## What it implements

A console application in C++ that models a video game platform, following the object-oriented design taught in the course.

- **Users.** Create a user (`Alta usuario`) as a *Desarrollador* (developer, with a company) or a *Jugador* (player, with a nickname and description), and log in (`Iniciar sesión`).
- **Developer menu.** Add categories (genre, platform, other), publish a video game with its subscription prices, delete a video game, choose and view statistics (total hours played, total subscribed players), view a game's information, and change the system date.
- **Player menu.** Subscribe to a video game (with period and payment method), rate a game, start a single-player or multiplayer *partida*, leave a multiplayer *partida*, finish a *partida*, view a game's information, and change the system date.
- **Test data.** Option 3 in the main menu (`Cargar datos de prueba`) loads sample developers, players, categories, games, subscriptions, ratings and *partidas*.

The menus and messages are in Spanish.

### Design

- `Fabrica` is a singleton factory that returns the system interfaces `IUsuario`, `IVideojuego` and `IPartida`.
- Controllers (`CtrlUsuario`, `CtrlVideojuego`, `CtrlPartida`) implement those interfaces.
- Handlers (`ManejadorUsuario`, `ManejadorVideojuego`, `ManejadorPartida`) hold the object collections.
- Data types (`Dt*`) and enumerations (`Tipo*`) carry data across the interface boundary.
- Statistics follow a strategy-style interface (`IEstadistica`) with `TotalHorasJuego` and `TotalJugadoresSuscritos`.
- `FechaSistema` holds the configurable system date.

Headers are in `lib/` and implementations in `src/`, in matching subfolders. `main.cpp` contains the menus.

## Build and run

Requirements: `g++` and `make`.

```bash
make        # builds ./main; object files go to obj/
./main
make clean
```

The Makefile compiles with `-Wall -Werror -g`. The committed `main` binary is a Linux x86-64 build. With Apple clang on macOS, `-Werror` stops the build on a `-Wsometimes-uninitialized` warning in `main.cpp`. To build there anyway, drop `-Werror`:

```bash
make OPTIONS="-Wall -g"
```

Once it starts, choose `3` to load the test data, then `2` to log in. The test accounts are in the `CARGAR DATOS DE PRUEBA` block of `main.cpp` (for example, `ironhide@mail.com` as a developer or `gamer@mail.com` as a player, both with password `123`).
