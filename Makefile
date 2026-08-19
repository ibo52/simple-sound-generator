.PHONY=all remove info makedirs build compile valgrind
TARGET=info

all:info remove makedirs build compile

CC:=g++
CLIBS=

BUILD_DIR:=build
SRC_DIR:=source
TEST_DIR:=test
BIN_DIR=bin

SRCS:=$(shell find $(SRC_DIR)/ -name "*.cpp" -type f)
SRCS:=$(SRCS:source/%=%)

OBJS:=$(SRCS:%.cpp=%.opp)
DEPS := $(OBJS:.opp=.dpp)

INC_DIRS:= $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Added -g for debugger/Valgrind source information.
# Added -O0 to make debugging easier.
CFLAGS= -Wall -g -O0 $(INC_FLAGS)

#****************************************
make_std_color=\033[3$1m

RESET_COLOR=\033[0m
ERROR_COLOR = $(strip $(call make_std_color,1))
INFO_COLOR = $(strip $(call make_std_color,3))
CYAN_COLOR=  $(strip $(call make_std_color,6))
#****************************************

info:
	@echo "----------------------"
	@echo "Halil Ibrahim MUT"
	@echo "----------------------"
	@echo "Simple Sound Generator"
	@echo "produce simple sound"
	@echo "----------------------"

compile: build
	@echo "$(INFO_COLOR)Compiling.."
	@echo "======================$(RESET_COLOR)"
	$(CC) $(CFLAGS) $(SOURCE_FILES) $(addprefix $(BUILD_DIR)/, $(OBJS)) -o "$(BIN_DIR)/simple-sound-generator" $(CLIBS)
	@echo "\n"
	
	@echo "Done"

# Build step for C++ source
$(BUILD_DIR)/%.opp: $(SRC_DIR)/%.cpp
	
	@echo "$(INFO_COLOR)Compile linker object: $@"
	@echo "====================================$(RESET_COLOR)"
	mkdir -p $(dir $@)

	$(CC) $(CFLAGS) -c $< -o $@
	@echo


build: $(addprefix $(BUILD_DIR)/, $(OBJS))

# Run program with Valgrind
valgrind: compile
	@echo "$(INFO_COLOR)Running Valgrind.."
	@echo "======================$(RESET_COLOR)"
	valgrind --tool=memcheck \
	         --leak-check=full \
	         --track-origins=yes \
	         --show-leak-kinds=all \
	         --num-callers=20 \
	         ./$(BIN_DIR)/simple-sound-generator

remove:
	@echo "$(INFO_COLOR)Removing main Directory and linker objects.."
	@echo "======================$(RESET_COLOR)"
	rm -rf $(BIN_DIR) $(BUILD_DIR)
	@echo "\n"
	@echo "Program directory removed."

makedirs:
	@echo "$(INFO_COLOR)making directories.."
	@echo "======================$(RESET_COLOR)"
	@echo "$(BIN_DIR) is MAIN DIRECTORY FOR SETUP"
	mkdir -p $(BIN_DIR)/sounds
	@echo "\n"

-include $(DEPS)