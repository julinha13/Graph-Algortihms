CC=g++
C=gcc
CFLAGS=-std=c++11 -Wall

BUILD_DIR = ./o
SRC_DIR = ./cpp
INCLUDE_DIR = ./hpp
PROG_DIR = .
 
all: main 


leitura.o: ${INCLUDE_DIR}/leitura.hpp ${SRC_DIR}/leitura.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/leitura.cpp -o ${BUILD_DIR}/leitura.o

grafo.o: ${INCLUDE_DIR}/grafo.hpp ${SRC_DIR}/grafo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/grafo.cpp -o ${BUILD_DIR}/grafo.o

comandos.o: ${INCLUDE_DIR}/comandos.hpp ${SRC_DIR}/comandos.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/comandos.cpp -o ${BUILD_DIR}/comandos.o

funcoesAuxiliares.o: ${INCLUDE_DIR}/funcoesAuxiliares.hpp ${SRC_DIR}/funcoesAuxiliares.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/funcoesAuxiliares.cpp -o ${BUILD_DIR}/funcoesAuxiliares.o

buscaGrafo.o: ${INCLUDE_DIR}/buscaGrafo.hpp ${SRC_DIR}/buscaGrafo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/buscaGrafo.cpp -o ${BUILD_DIR}/buscaGrafo.o

main.o: ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

main: leitura.o grafo.o comandos.o funcoesAuxiliares.o buscaGrafo.o main.o 
	${CC} ${CFLAGS} -o ${PROG_DIR}/tp1 ${BUILD_DIR}/*.o

clean: 
	rm -rf ${BUILD_DIR}/*.o    

clean_windows:
	del /S "o\*.o"