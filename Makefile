.PHONY=compile remove info makedirs

TARGET=info
all:info makedirs compile
DIR=sound_generator

info:
	@echo "----------------------"
	@echo "Halil Ibrahim MUT"
	@echo "----------------------"
	@echo "Simple Sound Generator"
	@echo "produce simple sound"
	@echo "----------------------"

compile:
	@echo "compiling.."
	g++ simple_sound_generator.cpp example_music.cpp wave_settings.cpp -o "$(DIR)/bin/generator"
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

