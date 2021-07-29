RM=rm
MD=mkdir
CP=cp
SIPS=sips

CC = g++

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

CXXFLAGS = -Wall

LDFLAGS = -lsdl2 -lsdl2main

ifeq ($(shell uname -s), Darwin) #  Platform detection test
    #libgl = -framework OpenGL -framework GLUT
else
    #libgl = -lGL -lglut
endif


MACDIR=./deps/MacOS
APPNAME=game

APPBUNDLE=$(APPNAME).app
APPBUNDLECONTENTS=$(APPBUNDLE)/Contents
APPBUNDLEMACOS=$(APPBUNDLECONTENTS)/MacOS
APPBUNDLERESOURCES=$(APPBUNDLECONTENTS)/Resources

$(APPNAME): $(obj)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

appbundle: $(MACDIR)/$(APPNAME).icns
	$(RM) -rf $(APPBUNDLE)
	$(MD) $(APPBUNDLE)
	$(MD) $(APPBUNDLECONTENTS)
	$(MD) $(APPBUNDLEMACOS)
	$(MD) $(APPBUNDLERESOURCES)
	$(CP) $(MACDIR)/Info.plist $(APPBUNDLECONTENTS)/Info.plist
	$(CP) $(MACDIR)/PkgInfo $(APPBUNDLECONTENTS)/
	$(CP) $(MACDIR)/$(APPNAME).icns $(APPBUNDLERESOURCES)/
	$(RM) -r $(MACDIR)/$(APPNAME).icns
	$(CP) $(APPNAME) $(APPBUNDLEMACOS)/
	$(RM) -f $(APPNAME)

$(MACDIR)/$(APPNAME).icns: $(MACDIR)/$(APPNAME).png
	$(RM) -rf $(APPNAME).iconset
	$(MD) $(APPNAME).iconset
	$(SIPS) -z 16 16   $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_16x16.png
	$(SIPS) -z 32 32   $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_16x16@2x.png
	$(SIPS) -z 32 32   v$(APPNAME).png --out $(APPNAME).iconset/icon_32x32.png
	$(SIPS) -z 64 64   $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_32x32@2x.png
	$(SIPS) -z 128 128 $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_128x128.png
	$(SIPS) -z 256 256 $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_128x128@2x.png
	$(SIPS) -z 256 256 $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_256x256.png
	$(SIPS) -z 512 512 $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_256x256@2x.png
	$(SIPS) -z 512 512 $(MACDIR)/$(APPNAME).png --out $(APPNAME).iconset/icon_512x512.png
	$(CP) $(MACDIR)/$(APPNAME).png $(APPNAME).iconset/icon_512x512@2x.png
	iconutil -c icns -o $(MACDIR)/$(APPNAME).icns $(APPNAME).iconset
	$(RM) -r $(APPNAME).iconset

.PHONY: clean
clean:
	rm -f -R $(obj) $(APPNAME) $(APPNAME).app