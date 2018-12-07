/*
	Library name: <readkey.h>
	Author: Rub!ck


	Description:
	Just use function readKey(catching_time_in_milliseconds) and it returns you true, if user was pressed any key!
	If you need to get last pressed key, just use global variable lastKey


	Example:
	int main(void) {
		while (true) {
			if (readKey(100))
				cout << "Catched: " << lastKey << endl;
			cout << "Main thread is working..." << endl;
		}
		return 0;
	}
*/



#ifndef READ_KEY
#define READ_KEY



#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
using namespace std;


char lastKey;



void delay(int millisec) {
        this_thread::sleep_for(chrono::milliseconds(millisec));
}



void nonblock(const bool state) {
    static struct termios ttystate;

    tcgetattr(STDIN_FILENO, &ttystate);

    if (state) {
        ttystate.c_lflag &= ~ICANON;
        ttystate.c_cc[VMIN] = 1;
    } else {
        ttystate.c_lflag |= ICANON;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}



bool keypress(void) {
    static struct timeval tv;
    static fd_set fds;
    tv.tv_sec =  0;
    tv.tv_usec = 0;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

    if (FD_ISSET(STDIN_FILENO, &fds))
	read(0, &lastKey, 1);
    else
	lastKey = 0;

    return FD_ISSET(STDIN_FILENO, &fds);
}



void SleepForNumberOfSeconds(const int &millisec, bool &timesUp) {
    delay(millisec);

    timesUp = true;
}



bool readKey(int const &numberofSeconds) {
    bool timesUp = false;

    std::thread thr(SleepForNumberOfSeconds, ref(numberofSeconds), ref(timesUp));
    nonblock(1);

    bool keyPressed = keypress();
    while (!keyPressed && !timesUp)
	keyPressed = keypress();

    if (thr.joinable())
        thr.detach();

    nonblock(0);

    return keyPressed;
}



#endif //READ_KEY
