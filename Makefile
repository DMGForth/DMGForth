PROJECT := forth

DEBUG_TARGET_NAME := $(PROJECT)_dbg
DEBUG_TARGET := $(DEBUG_TARGET_NAME).gb
SYMBOL_FILE := $(DEBUG_TARGET_NAME).sym
GENERATED_FILES += $(DEBUG_TARGET) $(SYMBOL_FILE)

RELEASE_TARGET_NAME := $(PROJECT)
RELEASE_TARGET := $(RELEASE_TARGET_NAME).gb
GENERATED_FILES += $(RELEASE_TARGET)

ASM := $(wildcard *.asm)
OBJ := $(patsubst %.asm,%.o,$(ASM))
DBG_OBJ := $(patsubst %.asm,%_dbg.o,$(ASM))
GENERATED_FILES += $(OBJ) $(DBG_OBJ)

all: release

debug: $(DEBUG_TARGET)

release: $(RELEASE_TARGET)

.PHONY: all clean debug release

%.o: %.asm
	rgbasm -o $@ $^

%_dbg.o: %.asm
	rgbasm -E -o $@ $^

$(DEBUG_TARGET): $(DBG_OBJ)
	rgblink -n $(SYMBOL_FILE) -o $@ $^
	rgbfix -v -p 0 $@

$(RELEASE_TARGET): $(OBJ)
	rgblink -o $@ $^
	rgbfix -v -p 0 $@

clean:
	rm -rf $(GENERATED_FILES)
