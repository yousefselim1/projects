#ifndef TIME_H
#define TIME_H
#include<iostream>
#include <iomanip>
using namespace std;


class Time {


private:
	int hours;
	int minutes;
	int seconds;


public:
	Time() {
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(int hours, int minutes, int seconds) {
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	int getHours() const {
		return hours;
	}

	int getMinutes() const {
		return minutes;
	}

	int getSeconds() const {
		return seconds;
	}

	void setSeconds(int seconds)
	{
		this->seconds = seconds;
	}

	void simulateTime() {
		seconds += 1;
		while (seconds > 59) {
			minutes += 1;
			seconds -= 60;
		}

		while (minutes > 59) {
			hours += 1;
			minutes -= 60;
		}
	}

	int toSeconds() {
		return (hours * 3600) + (minutes * 60) + seconds;
	}

	int toMinutes() {
		return (hours * 60) + minutes + (seconds / 60);
	}

	int toHours() {
		return hours + (minutes / 60) + (seconds / 3600);
	}

	void fromSeconds(int totalSeconds) {
		hours = totalSeconds / 3600;
		minutes = (totalSeconds % 3600) / 60;
		seconds = totalSeconds % 60;
	}

	void fromMinutes(int totalMinutes) {
		hours = totalMinutes / 60;
		minutes = totalMinutes % 60;
		seconds = 0;
	}
	void fromHours(int totalHours) {
		hours = totalHours;
		minutes = (totalHours * 60) % 60;
		seconds = 0;
	}

	void displayTime() {
		cout << setw(2) << setfill('O') << hours << ":";
		cout << setw(2) << setfill('O') << minutes << ":";
		cout << setw(2) << setfill('O') << seconds << endl;
	}
	void addSeconds(int seconds) {
		int totalSeconds = toSeconds() + seconds;
		fromSeconds(totalSeconds);
	}

	void addMinutes(int minutes) {
		int totalMinutes = toMinutes() + minutes;
		fromMinutes(totalMinutes);
	}

	void addHours(int hours) {
		int totalHours = toHours() + hours;
		fromHours(totalHours);
	}

	void removeSeconds(int seconds) {
		int totalSeconds = toSeconds() - seconds;
		fromSeconds(totalSeconds);
	}

	void removeMinutes(int minutes) {
		int totalMinutes = toMinutes() - minutes;
		fromMinutes(totalMinutes);
	}

	void removeHours(int hours) {
		int totalHours = toHours() - hours;
		fromHours(totalHours);
	}
};
#endif
