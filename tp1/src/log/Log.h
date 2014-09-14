#ifndef LOG_H_
#define LOG_H_
#include "../excepciones/LogExcepcion.h"

/**
 * Singleton, getInstance() siempre devuelve el mismo objeto Log.
 */
class Log {
protected:
	const char* archivo;
public:
	enum LOG_TIPO {LOG_ERR, LOG_WAR, LOG_DEB};

	virtual void loguear(const char* mensaje, LOG_TIPO tipo) throw (LogExcepcion) = 0;
	virtual ~Log() {};
};

#endif /* LOG_H_ */
