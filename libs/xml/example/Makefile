CPPFLAGS := -I../../../ -I/usr/include/libxml2
LIBS := -lxml2

targets := reader dom traverse

all: $(targets)

clean:
	rm -rf $(targets) *.o

%: %.o
	$(CXX) -o $@ $(LDFLAGS) $< $(LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) $<

# cancel default (built-in) rule
%: %.cpp

