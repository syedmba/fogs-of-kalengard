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

battle.o: battle.cpp battle.h
	g++ -c $<

walk.o: walk.cpp walk.h battle.h
	g++ -c $<

game.o: game.cpp walk.h battle.h
	g++ -c $<

game: game.o walk.o battle.o
	g++ $^ -o $@

clean:
	rm -f game game.o walk.o battle.o game.tgz

.PHONY: clean

