OPTIONS = -Wall -Werror -g
CC = g++

CLASSES = Partida PartidaIndividual PartidaMultijugador Videojuego Jugador Sistema
DATATYPES = DtPartida DtPartidaIndividual DtPartidaMultijugador DtJugador DtVideojuego DtFechaHora TipoJuego

CLASSES_OBJ = $(CLASSES:%=obj/%.o)
DATATYPES_OBJ = $(DATATYPES:%=obj/datatypes/%.o)

.PHONY: clean lab

# MAIN
main: obj/main.o $(CLASSES_OBJ) $(DATATYPES_OBJ)
	$(CC) $(OPTIONS) $^ -o $@

obj/main.o: main.cpp
	$(CC) $(OPTIONS) -c $< -o $@

# CLASSES
obj/Partida.o: lib/Partida.h src/Partida.cpp obj/Jugador.o obj/Videojuego.o
	$(CC) $(OPTIONS) -c src/Partida.cpp -o obj/Partida.o

obj/PartidaIndividual.o: lib/PartidaIndividual.h src/PartidaIndividual.cpp obj/Partida.o
	$(CC) $(OPTIONS) -c src/PartidaIndividual.cpp -o obj/PartidaIndividual.o

obj/PartidaMultijugador.o: lib/PartidaMultijugador.h src/PartidaMultijugador.cpp obj/Partida.o
	$(CC) $(OPTIONS) -c src/PartidaMultijugador.cpp -o obj/PartidaMultijugador.o

obj/Videojuego.o: lib/Videojuego.h src/Videojuego.cpp
	$(CC) $(OPTIONS) -c src/Videojuego.cpp -o obj/Videojuego.o

obj/Jugador.o: lib/Jugador.h src/Jugador.cpp
	$(CC) $(OPTIONS) -c src/Jugador.cpp -o obj/Jugador.o

obj/Sistema.o: lib/Sistema.h src/Sistema.cpp
	$(CC) $(OPTIONS) -c src/Sistema.cpp -o obj/Sistema.o

# DATATYPES
obj/datatypes/DtPartida.o: lib/datatypes/DtPartida.h src/datatypes/DtPartida.cpp
	$(CC) $(OPTIONS) -c src/datatypes/DtPartida.cpp -o obj/datatypes/DtPartida.o

obj/datatypes/DtPartidaIndividual.o: lib/datatypes/DtPartidaIndividual.h src/datatypes/DtPartidaIndividual.cpp obj/datatypes/DtPartida.o
	$(CC) $(OPTIONS) -c src/datatypes/DtPartidaIndividual.cpp -o obj/datatypes/DtPartidaIndividual.o

obj/datatypes/DtPartidaMultijugador.o: lib/datatypes/DtPartidaMultijugador.h src/datatypes/DtPartidaMultijugador.cpp obj/datatypes/DtPartida.o
	$(CC) $(OPTIONS) -c src/datatypes/DtPartidaMultijugador.cpp -o obj/datatypes/DtPartidaMultijugador.o

obj/datatypes/DtVideojuego.o: lib/datatypes/DtVideojuego.h src/datatypes/DtVideojuego.cpp
	$(CC) $(OPTIONS) -c src/datatypes/DtVideojuego.cpp -o obj/datatypes/DtVideojuego.o

obj/datatypes/DtJugador.o: lib/datatypes/DtJugador.h src/datatypes/DtJugador.cpp
	$(CC) $(OPTIONS) -c src/datatypes/DtJugador.cpp -o obj/datatypes/DtJugador.o

obj/datatypes/DtFechaHora.o: lib/datatypes/DtFechaHora.h src/datatypes/DtFechaHora.cpp
	$(CC) $(OPTIONS) -c src/datatypes/DtFechaHora.cpp -o obj/datatypes/DtFechaHora.o

obj/datatypes/TipoJuego.o: lib/datatypes/TipoJuego.h src/datatypes/TipoJuego.cpp
	$(CC) $(OPTIONS) -c src/datatypes/TipoJuego.cpp -o obj/datatypes/TipoJuego.o

# PHONY TARGETS
clean:
	@rm -f main obj/main.o $(CLASSES_OBJ) $(DATATYPES_OBJ)

lab:
