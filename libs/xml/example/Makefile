# comment out one of the folling sets of flags,
# depending on what string type and backend you want to use:

### std::string and libxml2
CPPFLAGS := -I../../../ -I/usr/include/libxml2 -DUSE_STD_STRING
LIBS := -lxml2
### Qt string and libxml2
#CPPFLAGS := -I../../../ -I/usr/include/libxml2 -DUSE_QSTRING
#LIBS := -lxml2 -lQtCore
### glibmm string and libxml2
CPPFLAGS := -I../../../ -I/usr/include/libxml2
CPPFLAGS += $(shell pkg-config --cflags glibmm-2.4)  -DUSE_GSTRING
LIBS := -lxml2 -lglibmm-2.4



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

