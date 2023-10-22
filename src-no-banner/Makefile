CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic
APPNAME = cutefetch-cpp

SRCDIR = src
OBJDIR = obj
BINDIR = bin

PREFIX=/usr
INSTALLDIR = $(PREFIX)/bin

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(addprefix $(OBJDIR)/,$(notdir $(SRCFILES:.cpp=.o)))
TARGET = $(BINDIR)/${APPNAME}

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJFILES) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

install: $(TARGET)
	mkdir -pv $(INSTALLDIR)
	install -Dm755 $< $(INSTALLDIR)/$(APPNAME)

uninstall:
	rm -fv $(INSTALLDIR)/$(APPNAME)

