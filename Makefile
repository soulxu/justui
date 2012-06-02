CXXFLAGS += -g -fPIC
LDFLAGS += 
SKIA_PATH = ./skia/
SKIA_INC = -I$(SKIA_PATH)/include/core/ -I$(SKIA_PATH)/include/config/ -I$(SKIA_PATH)/include/images
SKIA_LIB = $(SKIA_PATH)/out/libskia.a
COMPILE_OUT = out

include src/core/core.mk
SRC_LIST := $(addprefix core/, $(SOURCES))
core_target := $(addprefix $(COMPILE_OUT)/core/, $(TARGETS))
core_OBJS := $(SRC_LIST:.cpp=.o)
core_OBJS := $(addprefix $(COMPILE_OUT)/, $(core_OBJS))
vpath %.cpp src/core/

include test/test.mk
SRC_LIST := $(addprefix test/, $(SOURCES))
test_target := $(addprefix $(COMPILE_OUT)/test/, $(TARGETS))
test_OBJS := $(SRC_LIST:.cpp=.o)
test_OBJS := $(addprefix $(COMPILE_OUT)/, $(test_OBJS))
vpath %.cpp test/

#include src/view/view.mk
#SRC_LIST := $(addprefix view/, $(SOURCES))
#view_target := $(addprefix $(COMPILE_OUT)/view/, $(TARGETS))
#view_OBJS := $(SRC_LIST:.cpp=.o)
#view_OBJS := $(addprefix $(COMPILE_OUT)/, $(view_OBJS))
#vpath %.cpp src/view/

all: $(core_target) $(test_target) 
# $(view_target)

vpath %.o $(COMPLIE_OUT)

INC_PATH := -Isrc/core

$(COMPILE_OUT)/core/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(HIDE)$(CXX) $(CXXFLAGS) $(INC_PATH) -c $< -o $@
	@echo "compiling $@"

INC_PATH += -Isrc/view

$(COMPILE_OUT)/test/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(HIDE)$(CXX) $(CXXFLAGS) $(INC_PATH) -c $< -o $@ 
	@echo "compiling $@"

INC_PATH += $(SKIA_INC)

#$(COMPILE_OUT)/view/%.o : %.cpp
#	@mkdir -p $(dir $@)
#	$(HIDE)$(CXX) $(CXXFLAGS) $(INC_PATH) -c $< -o $@ 
#	@echo "compiling $@"

$(core_target): $(core_OBJS)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -shared -o $@ $(core_OBJS)

$(COMPILE_OUT)/test/%.out: $(COMPILE_OUT)/test/%.o $(core_target) $(view_target)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -lJuCore -Lout/core -lpng -lfreetype -lGL -lpthread -lz $< -o $@
#	$(CXX) $(LDFLAGS) $(CXXFLAGS) -lJuCore -Lout/core -lJuView -Lout/view -lpng -lfreetype -lGL -lpthread -lz $< -o $@

#$(view_target): $(view_OBJS) $(core_target)
#	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(view_OBJS) -static $(SKIA_LIB) -shared -lJuCore -Lout/core -o $@

.PHONY: clean

clean:
	rm $(COMPILE_OUT) -r
