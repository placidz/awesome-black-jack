#pragma once

#include "QCoreApplication"

class BJackApplication : public QCoreApplication {
public:
	BJackApplication(int argc, char *argv[]);
	virtual ~BJackApplication();
};
