SRCBASE=$(wildcard src/*.cpp)


SRC=$(SRCBASE) main.cpp

EXE=prog.exe

DOSSIER_SRC=src/

DOSSIER_BUILD=build
DOSSIER_INCLUDE=./include
DOSSIER_LIB=./lib/

WARNING+=-Wall -Wextra
OPTIMISATION=
CXXFLAGS+= -MMD -g $(OPTIMISATION) -fdiagnostics-color=auto -I $(DOSSIER_INCLUDE)

# -L $(DOSSIER_LIB)

LDSFML=-lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS=  $(LDSFML) 


OBJ=$(addprefix $(DOSSIER_BUILD)/, $(SRC:%.cpp=%.o) )
DEP=$(addprefix $(DOSSIER_BUILD)/, $(SRC:%.cpp=%.d) )


all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

# Generation des fichier objet .o et .d
$(DOSSIER_BUILD)/%.o: %.cpp
	@mkdir -p $(DOSSIER_BUILD)/src/
	$(CXX) $(CXXFLAGS) -o $@ -c $<


clean:
	rm -rf build/*
	test -f filename && rm filename || true

-include $(DEP) 
-include $(DEPTEST)