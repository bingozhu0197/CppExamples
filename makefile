target=$(MAKECMDGOALS)

target:target.cpp
	g++ -o $<   >  $@ -std=c++17