#ifndef _JU_LOOP_H_
#define _JU_LOOP_H_

#include <vector>

class JuLoopPriv;
class JuEventSource;

class JuLoop {
public:
	JuLoop();
	virtual ~JuLoop();
	void addSource(JuEventSource *source);
	void removeSource(JuEventSource *source);

	virtual int exec();
	virtual void exit(int exitCode = 0);

protected:
	int computeTimeout();

private:
	JuLoopPriv *m_priv;
};

#define getCurrentMainLoop() (gMainLoop)
#define setCurrentMainLoop(loop) (gMainLoop = loop)

extern JuLoop *gMainLoop;

#endif
