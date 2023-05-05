CPPFLAGS=`root-config --cflags` 
LDFLAGS=-g -L$(ROOTSYS)/lib
LDLIBS=-lRooFit -lHtml -lMinuit -lRooFitCore `root-config --glibs` 
CC=g++

TARGET2= app2

all: $(TARGET2)

$(TARGET2): $(TARGET2).cc
	$(CC) $(LDFLAGS) -o $(TARGET2) $(TARGET2).cc bnlFit.cc $(CPPFLAGS) $(LDLIBS)
clean:
	$(RM) $(TARGET) $(TARGET2)
