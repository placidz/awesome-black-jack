#pragma once

#include "QApplication"

class BJackApplication : public QApplication {
public:
	BJackApplication(int argc, char *argv[]);
	virtual ~BJackApplication();
protected:
	virtual bool	event ( QEvent * e );
private:
	QWidget* m_widget;
};
