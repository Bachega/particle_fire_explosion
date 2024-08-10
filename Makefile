all:
	g++ -Isrc/include -Lsrc/lib -o main main.cpp Screen.h Screen.cpp Particle.h Particle.cpp Swarm.h Swarm.cpp -lmingw32 -lSDL2main -lSDL2