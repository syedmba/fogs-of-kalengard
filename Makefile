# Makefile
# Created on 3 Mar 2022 by S M Bin Asif


# FLAGS = -pedantic-errors -std=c++11

# gcd.o: gcd.cpp gcd.h
# 	g++ $(FLAGS) -c $<

# lcm.o: lcm.cpp lcm.h gcd.h
# 	g++ $(FLAGS) -c $<
	
# calc.o: calc.cpp lcm.h gcd.h
# 	g++ $(FLAGS) -c $<
	
# calc: calc.o lcm.o gcd.o
# 	g++ $(FLAGS) $^ -o $@

nextarea.o: nextarea.cpp nextarea.h
	g++ -c $<

inventory.o: inventory.cpp inventory.h
	g++ -c $<

skeletonart.o: skeletonart.cpp skeletonart.h
	g++ -c $<

npcdialogueone.o: npcdialogueone.cpp npcdialogueone.h
	g++ -c $<

battle.o: battle.cpp battle.h skeletonart.h
	g++ -c $<

walk.o: walk.cpp walk.h printterrain.h battle.h skeletonart.h npcdialogueone.h inventory.h nextarea.o
	g++ -c $<

printterrain.o: printterrain.cpp printterrain.h
	g++ -c $<

game.o: game.cpp walk.h printterrain.h battle.h skeletonart.h npcdialogueone.h inventory.h nextarea.h
	g++ -c $<

game: game.o walk.o printterrain.o battle.o skeletonart.o npcdialogueone.o inventory.o nextarea.o
	g++ $^ -o $@

clean:
	rm -f game game.o walk.o battle.o skeletonart.o printterrain.o npcdialogueone.o inventory.o nextarea.o game.tgz

.PHONY: clean

