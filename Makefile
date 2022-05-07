# Makefile
# Created on 3 Mar 2022 by S M Bin Asif


FLAGS = -pedantic-errors -std=c++11

nextarea.o: nextarea.cpp nextarea.h
	g++ $(FLAGS) -c $<

inventory.o: inventory.cpp inventory.h
	g++ $(FLAGS) -c $<

skeletonart.o: skeletonart.cpp skeletonart.h
	g++ $(FLAGS) -c $<

npcdialogueone.o: npcdialogueone.cpp npcdialogueone.h
	g++ $(FLAGS) -c $<

battle.o: battle.cpp battle.h skeletonart.h
	g++ $(FLAGS) -c $<

walk.o: walk.cpp walk.h printterrain.h battle.h skeletonart.h npcdialogueone.h inventory.h nextarea.o
	g++ $(FLAGS) -c $<

printterrain.o: printterrain.cpp printterrain.h
	g++ $(FLAGS) -c $<

game.o: game.cpp walk.h printterrain.h battle.h skeletonart.h npcdialogueone.h inventory.h nextarea.h
	g++ $(FLAGS) -c $<

game: game.o walk.o printterrain.o battle.o skeletonart.o npcdialogueone.o inventory.o nextarea.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f game game.o walk.o battle.o skeletonart.o printterrain.o npcdialogueone.o inventory.o nextarea.o game.tgz

.PHONY: clean

