# comment out one of the following sets of flags,
# depending on what string type and backend you want to use:

LIBXML2_CPPFLAGS := -I/usr/include/libxml2 -DUSE_LIBXML2
LIBXML2_LIBS := -lxml2

XERCES_CPPFLAGS := -DUSE_XERCES
XERCES_LIBS := -lxerces-c

backend ?= libxml2
unicode ?= std

ifeq ($(backend), xerces)
CPPFLAGS := -I../../../ $(XERCES_CPPFLAGS)
LIBS := $(XERCES_LIBS)
else
CPPFLAGS := -I../../../ $(LIBXML2_CPPFLAGS)
LIBS := $(LIBXML2_LIBS)
endif

ifeq ($(unicode), std)
### std::string
CPPFLAGS += -DUSE_STD_STRING
LIBS +=
else ifeq ($(unicode), qt)
### Qt string
CPPFLAGS += -DUSE_QSTRING
LIBS += -lQtCore
else ifeq ($(unicode), glib)
### glibmm string
CPPFLAGS += $(shell pkg-config --cflags glibmm-2.4)  -DUSE_GSTRING
LIBS += -lglibmm-2.4
endif

targets := reader dom traverse xinclude validate_dtd config

all: $(targets)

clean:
	rm -rf $(targets) *.o

%: %.o
	$(CXX) -o $@ $(LDFLAGS) $< $(LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) $<

# cancel default (built-in) rule
%: %.cpp

