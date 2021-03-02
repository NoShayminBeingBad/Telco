a2:	main.o Array.o Call.o Compare.o Control.o Date.o Subscriber.o Telco.o Time.o View.o
	g++ -o a2 main.o Array.o Call.o Compare.o Control.o Date.o Subscriber.o Telco.o Time.o View.o
	
main.o: main.cc Array.h Call.h Compare.h Control.h Date.h Subscriber.h Telco.h Time.h View.h
	g++ -c main.cc

Array.o: Array.cc Array.h
	g++ -c Array.cc
	
Call.o: Call.cc Call.h
	g++ -c Call.cc
	
Compare.o: Compare.cc Compare.h
	g++ -c Compare.cc
	
Control.o: Control.cc Control.h
	g++ -c Control.cc
	
Date.o:	Date.cc Date.h
	g++ -c Date.cc
	
Subscriber.o: Subscriber.cc Subscriber.h
	g++ -c Subscriber.cc
	
Telco.o: Telco.cc Telco.h
	g++ -c Telco.cc
	
Time.o: Time.cc Time.h
	g++ -c Time.cc
	
View.o: View.cc View.h
	g++ -c View.cc
	
clean:
	rm -f *.o *.h.gch a1
