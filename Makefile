.PHONY=compile remove info makedirs

TARGET=info
all:info makedirs compile
DIR=sound_generator

SRC_FILES:=$(shell ls source/*.cpp)
HEADER_FILES:=$(shell ls header/*.h)

info:
	@echo "----------------------"
	@echo "Halil Ibrahim MUT"
	@echo "----------------------"
	@echo "Simple Sound Generator"
	@echo "produce simple sound"
	@echo "----------------------"

compile:
	@echo "compiling.."
	g++ $(SRC_FILES) -o "$(DIR)/bin/generator"
	@echo "---------------------------"
	@echo "Done"

remove:
	@echo "Removing main directory.."
	rm -rf $(DIR)/
	@echo "Program directory removed."

makedirs:
	@echo "making directories.."
	@echo "$(DIR) is MAIN DIRECTORY FOR SETUP"
	mkdir -p $(DIR)/sounds
	mkdir -p $(DIR)/bin

