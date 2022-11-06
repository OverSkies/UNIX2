.SILENT:

UNIX_Exercice2:	main.o mywindow.o moc_mywindow.o FichierClient.o
	echo "Creation de UNIX_Exercice2 !"
	g++  -o UNIX_Exercice2 main.o mywindow.o moc_mywindow.o FichierClient.o /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so -lpthread -Wall

FichierClient.o:	FichierClient.cpp FichierClient.h
	echo "Creation de FichierClient.o !"
	g++ -c FichierClient.cpp

moc_mywindow.o:	moc_mywindow.cpp mywindow.h
	echo "Creation de moc_window.o !"
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I../UNIX_Exercice1 -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o moc_mywindow.o moc_mywindow.cpp

mywindow.o:	mywindow.cpp mywindow.h
	echo "Creation de mywindow.o !"
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I../UNIX_Exercice1 -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o mywindow.o mywindow.cpp

main.o:	main.cpp
	echo "Creation de main.o !"
	g++ -c -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I../UNIX_Exercice1 -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ -o main.o main.cpp

clean:
	echo "Suppression de l'executable et des .o"
	rm *.o UNIX_Exercice2