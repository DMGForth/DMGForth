PROJECT := GBForth
VERSION_FILE := version.txt
RELEASE_VERSION := $(shell cat $(VERSION_FILE))
DEBUG_VERSION := $(shell git log -1 --format=%cd --date=short)

INC_DIR := inc/
OBJ_DIR := obj/

DEBUG_TARGET_NAME := $(PROJECT)_dev-$(DEBUG_VERSION)_dbg
DEBUG_TARGET := $(DEBUG_TARGET_NAME).gb
SYMBOL_FILE := $(DEBUG_TARGET_NAME).sym
GENERATED_FILES += $(DEBUG_TARGET) $(SYMBOL_FILE)

RELEASE_TARGET_NAME := $(PROJECT)_$(RELEASE_VERSION)
RELEASE_TARGET := $(RELEASE_TARGET_NAME).gb
GENERATED_FILES += $(RELEASE_TARGET)

VERSION_INC_FILE := $(INC_DIR)version.inc
VERSION_PREFIX_FILE := $(VERSION_INC_FILE).prefix
VERSION_SUFFIX_FILE := $(VERSION_INC_FILE).suffix
GENERATED_FILES += $(VERSION_INC_FILE)

ASMFLAGS := -i$(INC_DIR)

ASM := $(wildcard *.asm)
INC := $(wildcard $(INC_DIR)*.inc) $(VERSION_INC_FILE)
OBJ := $(patsubst %.asm,$(OBJ_DIR)%.o,$(ASM))
DBG_OBJ := $(patsubst %.asm,$(OBJ_DIR)%_dbg.o,$(ASM))
GENERATED_FILES += $(OBJ) $(DBG_OBJ)

all: install

debug: $(DEBUG_TARGET) $(SYMBOL_FILE)

release: $(RELEASE_TARGET)

.PHONY: all clean debug install release

$(OBJ_DIR)%.o: %.asm $(INC)
	rgbasm $(ASMFLAGS) -o $@ $<

$(OBJ_DIR)%_dbg.o: %.asm $(INC)
	rgbasm $(ASMFLAGS) -DDEBUG=1 -E -o $@ $<

$(SYMBOL_FILE): $(DBG_OBJ)
	rgblink -n $@ $^

$(DEBUG_TARGET): $(DBG_OBJ)
	rgblink -o $@ $^
	rgbfix -v -p 0 $@

$(RELEASE_TARGET): $(OBJ)
	rgblink -o $@ $^
	rgbfix -v -p 0 $@

$(VERSION_INC_FILE): $(VERSION_PREFIX_FILE) $(VERSION_FILE) $(VERSION_SUFFIX_FILE)
	cat $^ | tr -d '\n' > $@

install: $(RELEASE_TARGET) $(DEBUG_TARGET) $(SYMBOL_FILE)
	./install $^

clean:
	rm -rf $(GENERATED_FILES)
