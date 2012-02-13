
CXX	= /usr/local/angstrom/arm/bin/arm-angstrom-linux-gnueabi-g++
RM	= rm -f

SDK_ROOT = ../..
TARGET 	 = $(SDK_ROOT)/bin/TrackingViewer3D


SRCS= 	Tracking.cpp \
		main.cpp \
		GLContext.cpp \
		RenderContext.cpp
			
OBJS=	$(subst .cpp,.o,$(SRCS))
DEPS=	$(subst .cpp,.d,$(SRCS))
						
CPPFLAGS=	-I$(SDK_ROOT)/include -I./OGLES \
			-O3 -mcpu=cortex-a8 -mfpu=neon -ftree-vectorize -mfloat-abi=softfp -ffast-math
			
LDFLAGS=	-L$(SDK_ROOT)/bin \
			-Wl,-rpath,./:$(PWD)/$(SDK_ROOT)/bin
			
LDLIBS= -lpthread -lcv -lcxcore \
		-lEGL -lGLES_CM \
		-lShadow

.PHONY: all clean

# Build target.
all: $(TARGET)

# Generate dependencies and compile.
%.o: %.cpp
	$(CXX) -MMD -MP -MT"$(<:.cpp=.d)" -MT"$@" -c $(CPPFLAGS) -o $@ $<	
	
# Include the dependencies.
-include $(DEPS)	

# Link.
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS) 

clean:
	$(RM) $(OBJS)
	$(RM) $(DEPS)
	$(RM) $(TARGET)
	





