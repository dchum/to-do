CXX:= g++

CFLAGS = -Wall -g -Wno-unused-variable
CXXFLAGS = -Wall -g -Wno-unused-variable -std=c++17 -Wall -Wextra
INCS_cdk = -I../cdk
INCS_lib = -I../../../../lib
INCS_ui = -I../../../ -I../../windows/ -I../../command/
INCS_cui = -I../..
INCS = -I.. -I. ${INCS_cdk} ${INCS_lib} ${INCS_ui} ${INCS_cui}
LIBS = -lncurses

SOURCES_CPP = test.cpp cui_container.cpp lib.cpp cui_lib.cpp\
	cui_screen.cpp cui_entry.cpp cui_dialog.cpp cui_label.cpp\
	cui_widget.cpp cui_slider.cpp cui_scroll_list.cpp cui_window_start.cpp\
	cui_surface.cpp cui_window_main.cpp cui_border.cpp cui_window_setting.cpp\
	cui_application.cpp add_new_task.cpp cui_radio.cpp

HEADERS_CPP = cui_container.h cui_widget.h lib.h cui_lib.h\
	cui_screen.h cui_entry.h cui_dialog.h cui_label.h cui_slider.h\
	cui_scroll_list.h cui_window_start.h cui_surface.h cui_window_main.h\
	cui_border.h cui_window.h cui_window_setting.h cui_application.h\
	add_new_task.h cui_radio.h

SOURCES_C = cdk_objs.c cdk.c cdkscreen.c draw.c traverse.c binding.c\
	entry.c cdk_display.c dialog.c label.c slider.c radio.c scroller.c scroll.c

HEADERS_C = cdk_objs.h cdk.h cdkscreen.h draw.h traverse.h binding.h\
	entry.h cdk.h dialog.h label.h slider.h radio.h scroller.h scroll.h

HEADERS = ${HEADERS_CPP} ${HEADERS_C}

OBJECTS = $(SOURCES_CPP:.cpp=.o) $(SOURCES_C:.c=.o)

TARGET = test

VPATH := .. . ../cdk ../../../ ../../../../lib ../.. ../../windows/ ../../command/

default: all

all: $(TARGET)

clean:
	rm -f *.o $(TARGET)

test.o: test.cpp $(HEADERS_CPP)
	$(CXX) $(CXXFLAGS) $(INCS) -c test.cpp -o test.o

$(TARGET): $(OBJECTS) 
	$(CXX) ${OBJECTS} -o $@ ${LIBS}

.c.o:
	$(CXX) ${CFLAGS} ${INCS} -c $< -o $@

.cpp.o:
	$(CXX) ${CXXFLAGS} ${INCS} -c $< -o $@
