CURRENT_DIR := $(shell pwd)
SEED := 1

cake-sharing: CakeSharing.cpp
	g++ -o cake-sharing -std=c++0x -W -Wall -Wno-sign-compare -O2 -s -pipe -mmmx -msse -msse2 -msse3 CakeSharing.cpp

test: cake-sharing
	java -jar resources/tester.jar -exec "$(CURRENT_DIR)/cake-sharing" -seed $(SEED) -debug

test-manual: cake-sharing
	java -jar resources/tester.jar -exec "$(CURRENT_DIR)/cake-sharing" -seed $(SEED) -debug -manual

clean: 
	rm cake-sharing
