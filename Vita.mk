PHONY := all package clean mkdr
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

CC := arm-vita-eabi-gcc
CXX := arm-vita-eabi-g++
STRIP := arm-vita-eabi-strip

PROJECT_TITLE := SDL2 Test
PROJECT_TITLEID := VSDK00007

PROJECT := SDL2Stuff
BUILDDIR = build
CFLAGS += -Wl,-q
CXXFLAGS += -Wl,-q -std=c++11

INCDIR = -I./deps/include -Ideps/Vita/common

CXXFLAGS += $(INCDIR) -D__VITA__
CFLAGS += $(INCDIR) -D__VITA__

SRC_C :=$(call rwildcard, src/, *.c)
SRC_CPP :=$(call rwildcard, src/, *.cpp)

OBJS := $(SRC_C:%.c=%.o) $(SRC_CPP:%.cpp=%.o)

LIBS += -lSDL2 -lphysfs -lSceDisplay_stub -lSceCtrl_stub -lSceAudio_stub -lSceSysmodule_stub -lSceGxm_stub -lSceCommonDialog_stub -lSceAppMgr_stub -lSceTouch_stub -lSceHid_stub -lSceMotion_stub -lm

all: mkdr package

mkdr:
	mkdir $(BUILDDIR)

package: build/$(PROJECT).vpk

$(BUILDDIR)/$(PROJECT).vpk: $(BUILDDIR)/eboot.bin $(BUILDDIR)/param.sfo
	vita-pack-vpk -s $(BUILDDIR)/param.sfo -b $(BUILDDIR)/eboot.bin \
		--add deps/Vita/sce_sys/icon0.png=sce_sys/icon0.png \
		--add deps/Vita/sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png \
		--add deps/Vita/sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png \
		--add deps/Vita/sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml \
	$(BUILDDIR)/$(PROJECT).vpk

$(BUILDDIR)/eboot.bin: $(BUILDDIR)/$(PROJECT).velf
	vita-make-fself $(BUILDDIR)/$(PROJECT).velf build/eboot.bin

$(BUILDDIR)/param.sfo:
	vita-mksfoex -s TITLE_ID="$(PROJECT_TITLEID)" "$(PROJECT_TITLE)" $(BUILDDIR)/param.sfo

$(BUILDDIR)/$(PROJECT).velf: $(BUILDDIR)/$(PROJECT).elf
	$(STRIP) -g $<
	vita-elf-create $< $@

$(BUILDDIR)/$(PROJECT).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f $(BUILDDIR) $(OBJS)
