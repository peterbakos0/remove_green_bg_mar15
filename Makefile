CXX=g++
CP=cp -r
MKDIR=mkdir -p
RM=rm -rf

CJSON_CXXFLAGS=`pkg-config --cflags libcjson`
CJSON_LDLIBS=`pkg-config --libs libcjson`

OPENCV_CXXFLAGS=`pkg-config --cflags opencv4`
OPENCV_LDLIBS=`pkg-config --libs opencv4`

CXXFLAGS=-O3 -Wall $(CJSON_CXXFLAGS) $(OPENCV_CXXFLAGS)
LDLIBS=$(CJSON_LDLIBS) $(OPENCV_LDLIBS)

SRC_DIR=src
BUILD_DIR=build
OBJ_DIR=obj
BIN_DIR=bin
EXEC_FILE=remove_green_bg_mar15
CONF_FILE=config.json

SRC_EXT=.cpp
OBJ_EXT=.o

SRCS=$(shell find $(SRC_DIR) -name *$(SRC_EXT))
OBJS=$(patsubst $(SRC_DIR)/%$(SRC_EXT), $(BUILD_DIR)/$(OBJ_DIR)/%$(OBJ_EXT), $(SRCS))

all: $(BUILD_DIR)/$(BIN_DIR)/$(EXEC_FILE) $(BUILD_DIR)/$(BIN_DIR)/$(CONF_FILE)

clean:
	$(RM) $(BUILD_DIR)

$(BUILD_DIR)/$(BIN_DIR)/$(EXEC_FILE): $(OBJS)
	$(MKDIR) $(BUILD_DIR)/$(BIN_DIR)
	$(CXX) $(OBJS) $(CXXFLAGS) $(LDLIBS) -o $(BUILD_DIR)/$(BIN_DIR)/$(EXEC_FILE)

$(BUILD_DIR)/$(BIN_DIR)/$(CONF_FILE): $(CONF_FILE)
	$(MKDIR) $(BUILD_DIR)/$(BIN_DIR)
	$(CP) $(CONF_FILE) $(BUILD_DIR)/$(BIN_DIR)/$(CONF_FILE)

$(BUILD_DIR)/$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	$(MKDIR) $(dir $@)
	$(CXX) $< $(CXXFLAGS) -o $@ -c
