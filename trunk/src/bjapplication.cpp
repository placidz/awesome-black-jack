#include "bjapplication.h"
#include <iostream>
#include "QTextStream"
#include <QKeyEvent>
#include <QWidget>
BJackApplication::BJackApplication(int argc, char *argv[]) : QApplication(argc, argv) {
	QTextStream stream(stdout);
	stream << QString::fromLatin1("Welcome to the Awesome black Jack") << endl;
	m_widget = new QWidget();
	m_widget->show();
	installEventFilter(m_widget);
}

BJackApplication::~BJackApplication() {
}

bool BJackApplication::event ( QEvent * e ) {
	switch(e->type())
	{
	case QEvent::KeyRelease: {
		QTextStream stream(stdout);
		QKeyEvent* keyE = dynamic_cast<QKeyEvent*>(e);
		if(keyE)
			stream << QString::fromLatin1("you pressed ") << keyE->text() << endl;
							 }
	default:
		break;
	}
	return QCoreApplication::event(e);
}