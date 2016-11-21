main:	gui_main.o shop.o arm.o battery.o head.o locomotor.o torso.o model.o customer.o sa.o order.o
	g++ `fltk-config --cxxflags` gui_main.o shop.o arm.o battery.o head.o locomotor.o torso.o model.o customer.o sa.o order.o `fltk-config --ldflags` -o gui

gui_main.o:	gui_main.cpp
	g++ `fltk-config --cxxflags` gui_main.cpp `fltk-config --ldflags` -c
shop.o: shop.cpp arm.h battery.h head.h locomotor.h torso.h model.h customer.h sa.h order.h
arm.o: arm.cpp part.h
	g++ `fltk-config --cxxflags` arm.cpp `fltk-config --ldflags` -c
battery.o: battery.cpp part.h
	g++ `fltk-config --cxxflags` battery.cpp `fltk-config --ldflags` -c
head.o: head.cpp part.h
	g++ `fltk-config --cxxflags` head.cpp `fltk-config --ldflags` -c
locomotor.o: locomotor.cpp part.h
	g++ `fltk-config --cxxflags` locomotor.cpp `fltk-config --ldflags` -c
torso.o: torso.cpp part.h
	g++ `fltk-config --cxxflags` torso.cpp `fltk-config --ldflags` -c
model.o: model.cpp head.h arm.h torso.h locomotor.h battery.h
	g++ `fltk-config --cxxflags` model.cpp `fltk-config --ldflags` -c
customer.o: customer.cpp
	g++ `fltk-config --cxxflags` customer.cpp `fltk-config --ldflags` -c
sa.o: sa.cpp
	g++ `fltk-config --cxxflags` sa.cpp `fltk-config --ldflags` -c
order.o: order.cpp model.h customer.h sa.h
	g++ `fltk-config --cxxflags` order.cpp `fltk-config --ldflags` -c
