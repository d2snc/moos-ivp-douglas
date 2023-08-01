# Atualizações

- 01/AGO/2023: Adicionado controle de Leme utilizando dois valores de potência para o atuador do Leme, 100% e 50%. Adicionado também envio de comandos para o atuador de máquina.



# Introdução

 Foram criados até o momento dois aplicativos para rodar em conjunto com o MOOS, de forma a alcançar o objetivo controlar a lancha VSNT-LAB do CASNAV, além de implantar futuramente um CollisionAvoidance na mesma.
 A princípio foram desenvolvidos os aplicativos iDivisorNMEA e iSerial, no qual eles teriam as funções de :

- `iDivisorNMEA` -> Receber as sentenças NMEA2000, que é o protocolo de comunição, na rede, decodificá-las e jogar as informações no MOOS

- `iSerial` -> Enviar para a placa de controle da lancha, que contém um microcontrolador PIC, os comandos de leme e máquinas calculados no MOOS.

Essas foram as funções iniciais dos aplicativos, entretanto com os testes que realizamos a bordo da lancha algumas coisas foram mudando, segue alguns testes e coisas que tivemos que mudar e adaptar:

___

# Informações do MOOS-IvP sobre compilar o código:


## Introduction

The moos-ivp-extend repository contains examples for extending the MOOS-IvP
Autonomy system. This includes a MOOS application and an IvP behavior.


## Directory Structure

The directory structure for the moos-ivp-extend is decribed below:

bin              - Directory for generated executable files
build            - Directory for build object files
build.sh         - Script for building moos-ivp-extend
CMakeLists.txt   - CMake configuration file for the project
data             - Directory for storing data
lib              - Directory for generated library files
missions         - Directory for mission files
README           - Contains helpful information - (this file).
scripts          - Directory for script files
src              - Directory for source code


## Build Instructions

### Linux and Mac Users

To build on Linux and Apple platforms, execute the build script within this
directory:

   `$ ./build.sh` 

To build without using the supplied script, execute the following commands
within this directory:

   ```
   $ mkdir -p build
   $ cd build
   $ cmake ../
   $ make
   $ cd ..
 ```
## Environment variables

The moos-ivp-extend binaries files should be added to your path to allow them
to be launched from pAntler. 

In order for generated IvP Behaviors to be recognized by the IvP Helm, you
should add the library directory to the "IVP_BEHAVIOR_DIRS" environment 
variable.


