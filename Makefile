OPTIONS = -Wall -Werror -g
CC = g++

CLASSES = Fabrica Partida PartidaIndividual PartidaMultijugador Videojuego Usuario Jugador Desarrollador InfoPartidaMulti Suscripcion DescripcionSuscripcion Categoria
CONST = Constantes
DATATYPES = DtPartida DtPartidaIndividual DtPartidaMultijugador DtJugador DtVideojuego DtFechaHora DtSuscripcion TipoCat TipoPeriodo
INTERFACES = IPartida IUsuario IVideojuego
CONTROLLERS = CtrlUsuario CtrlPartida CtrlVidejuego
HELPERS = FechaSistema

CLASSES_OBJ = $(CLASSES:%=obj/%.o)
CONST_OBJ = $(CONST:%=obj/const/%.o)
DATATYPES_OBJ = $(DATATYPES:%=obj/datatypes/%.o)
INTERFACES_OBJ = $(INTERFACES:%=obj/interfaces/%.o)
CONTROLLERS_OBJ = $(CONTROLLERS:%=obj/controllers/%.o)
HELPERS_OBJ = $(HELPERS:%=obj/helpers/%.o)

.PHONY: clean lab

# MAIN
main: obj/main.o $(CLASSES_OBJ) $(CONST_OBJ) $(DATATYPES_OBJ) $(INTERFACES_OBJ) $(CONTROLLERS_OBJ) $(HELPERS_OBJ)
	$(CC) $(OPTIONS) $^ -o $@

obj/main.o: main.cpp
	$(CC) $(OPTIONS) -c $< -o $@

# CLASSES

obj/Fabrica.o: lib/Fabrica.h src/Fabrica.cpp
	$(CC) $(OPTIONS) -c src/Fabrica.cpp -o obj/Fabrica.o

obj/Partida.o: lib/Partida.h src/Partida.cpp obj/Jugador.o obj/Videojuego.o
	$(CC) $(OPTIONS) -c src/Partida.cpp -o obj/Partida.o

obj/PartidaIndividual.o: lib/PartidaIndividual.h src/PartidaIndividual.cpp obj/Partida.o
	$(CC) $(OPTIONS) -c src/PartidaIndividual.cpp -o obj/PartidaIndividual.o

obj/PartidaMultijugador.o: lib/PartidaMultijugador.h src/PartidaMultijugador.cpp obj/Partida.o
	$(CC) $(OPTIONS) -c src/PartidaMultijugador.cpp -o obj/PartidaMultijugador.o

obj/Videojuego.o: lib/Videojuego.h src/Videojuego.cpp
	$(CC) $(OPTIONS) -c src/Videojuego.cpp -o obj/Videojuego.o

obj/Usuario.o: lib/Usuario.h src/Usuario.cpp
	$(CC) $(OPTIONS) -c src/Usuario.cpp -o obj/Usuario.o

obj/Desarrollador.o: lib/Desarrollador.h src/Desarrollador.cpp
	$(CC) $(OPTIONS) -c src/Desarrollador.cpp -o obj/Desarrollador.o

obj/Jugador.o: lib/Jugador.h src/Jugador.cpp
	$(CC) $(OPTIONS) -c src/Jugador.cpp -o obj/Jugador.o

obj/InfoPartidaMulti.o: lib/InfoPartidaMulti.h src/InfoPartidaMulti.cpp
	$(CC) $(OPTIONS) -c src/InfoPartidaMulti.cpp -o obj/InfoPartidaMulti.o

obj/Suscripcion.o: lib/Suscripcion.h src/Suscripcion.cpp
	$(CC) $(OPTIONS) -c src/Suscripcion.cpp -o obj/Suscripcion.o

obj/DescripcionSuscripcion.o: lib/DescripcionSuscripcion.h src/DescripcionSuscripcion.cpp
	$(CC) $(OPTIONS) -c src/DescripcionSuscripcion.cpp -o obj/DescripcionSuscripcion.o

obj/Categoria.o: lib/Categoria.h src/Categoria.cpp
	$(CC) $(OPTIONS) -c src/Categoria.cpp -o obj/Categoria.o


# CONST
obj/const/Constantes.o: lib/const/Constantes.h src/const/Constantes.cpp
	$(CC) $(OPTIONS) -c src/const/Constantes.cpp -o obj/const/Constantes.o

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

obj/datatypes/TipoCat.o: lib/datatypes/TipoCat.h src/datatypes/TipoCat.cpp
	$(CC) $(OPTIONS) -c src/datatypes/TipoCat.cpp -o obj/datatypes/TipoCat.o

# INTERFACES
obj/interfaces/IUsuario.o: lib/interfaces/IUsuario.h src/interfaces/IUsuario.cpp
	$(CC) $(OPTIONS) -c src/interfaces/IUsuario.cpp -o obj/interfaces/IUsuario.o

obj/interfaces/IPartida.o: lib/interfaces/IPartida.h src/interfaces/IPartida.cpp
	$(CC) $(OPTIONS) -c src/interfaces/IPartida.cpp -o obj/interfaces/IPartida.o

obj/interfaces/IVideojuego.o: lib/interfaces/IVideojuego.h src/interfaces/IVideojuego.cpp
	$(CC) $(OPTIONS) -c src/interfaces/IVideojuego.cpp -o obj/interfaces/IVideojuego.o

# CONTROLLERS
obj/controllers/CtrlUsuario.o: lib/controllers/CtrlUsuario.h src/controllers/CtrlUsuario.cpp
	$(CC) $(OPTIONS) -c src/controllers/CtrlUsuario.cpp -o obj/controllers/CtrlUsuario.o

obj/controllers/CtrlPartida.o: lib/controllers/CtrlPartida.h src/controllers/CtrlPartida.cpp
	$(CC) $(OPTIONS) -c src/controllers/CtrlPartida.cpp -o obj/controllers/CtrlPartida.o

obj/controllers/CtrlVidejuego.o: lib/controllers/CtrlVidejuego.h src/controllers/CtrlVidejuego.cpp
	$(CC) $(OPTIONS) -c src/controllers/CtrlVidejuego.cpp -o obj/controllers/CtrlVidejuego.o

# HELPERS
obj/helpers/FechaSistema.o: lib/helpers/FechaSistema.h src/helpers/FechaSistema.cpp
	$(CC) $(OPTIONS) -c src/helpers/FechaSistema.cpp -o obj/helpers/FechaSistema.o

# PHONY TARGETS
clean:
	@rm -f main obj/main.o $(CLASSES_OBJ) $(DATATYPES_OBJ) $(CONST_OBJ) $(INTERFACES_OBJ) $(CONTROLLERS_OBJ) $(HELPERS_OBJ)

lab:
