CPPFLAGS=`root-config --cflags` 
LDFLAGS=-g -L$(ROOTSYS)/lib
LDLIBS=-lRooFit -lHtml -lMinuit -lRooFitCore `root-config --glibs` 
CC=g++

TARGET = app3
TARGET2= app2

all: $(TARGET2)
#all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).cc
	$(CC) $(LDFLAGS) -o $(TARGET) $(TARGET).cc dirFit.cc wbEvent.cc wbPDF.cc $(CPPFLAGS) $(LDLIBS)
$(TARGET2): $(TARGET2).cc
	$(CC) $(LDFLAGS) -o $(TARGET2) $(TARGET2).cc dirFit.cc wbEvent.cc wbPDF.cc $(CPPFLAGS) $(LDLIBS)
clean:
	$(RM) $(TARGET) $(TARGET2)
