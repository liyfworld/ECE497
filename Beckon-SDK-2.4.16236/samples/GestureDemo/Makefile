 
CXX	= /usr/local/angstrom/arm/bin/arm-angstrom-linux-gnueabi-g++
RM	= rm -f

SDK_ROOT = ../..
TARGET 	 = $(SDK_ROOT)/bin/GestureDemo

CPPFLAGS=	-I$(SDK_ROOT)/include \
			-O3 -mcpu=cortex-a8 -mfpu=neon -ftree-vectorize -mfloat-abi=softfp -ffast-math
			
LDFLAGS=	-L$(SDK_ROOT)/bin \
			-Wl,-rpath,./
			
LDLIBS= -lpthread -lcv -lcxcore \
		-lShadow
		
.PHONY: all clean

# Build target.
all: $(TARGET)
	
# Link.
$(TARGET): GestureDemo.cpp
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS) 

clean:
	$(RM) GestureDemo.o
	$(RM) $(TARGET)
	





 
 
 
