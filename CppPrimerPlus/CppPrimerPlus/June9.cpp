//	tv.h
#ifndef TV_H_
#define TV_H_

class Remote;

class Tv
{
public:
	friend class Remote;
	enum { Off, On};
	enum { MinVal, MaxVal = 20};
	enum { Antenna, Cable};
	enum { TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode = (mode == Antenna) ? Cable : Antenna); }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
	void remote_mode_toggle(Remote & r);

private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

};

class Remote {
public:
	friend class Tv;
	enum { Normal, Convo };

private:
	int mode;
	int remote_mode;

public:
	Remote(int m = Tv::TV) : mode(m), remote_mode(Normal) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { return t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
	void set_remote_mode() { remote_mode = (remote_mode = (remote_mode == Normal) ? Convo : Normal); }
	void get_remote_mode() const;
};

#endif // !TV_H_
#include<iostream>

int use_tv();


// tv.cpp
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else 
		channel = 1;
}
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;
	if (state == On)
	{
		cout << "Volume = " << volume << endl;
		cout << "Channel = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "Antenna" : "Cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "DVD") << endl;
	}
}
void Remote::get_remote_mode() const
{
	using std::cout;
	using std::endl;
	cout << "Remote Mode : " << (remote_mode == Normal ? "Normal" : "Convo") << endl; 
}
void Tv::remote_mode_toggle(Remote & r)
{
	if (state == On)
	{
		r.set_remote_mode();
	}
}

int main()
{
	use_tv();
}

int use_tv()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV의 초기 설정값:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV의 변경된 설정값:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n리모콘 사용 후 42\" TV의 설정값:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV의 설정값:\n";
	s58.settings();
	
	cout << "\ngrey\" 리모콘의 설정값:\n";
	grey.get_remote_mode();
	s58.remote_mode_toggle(grey);

	cout << "\nTv 사용 후 grey\" 리모콘의 설정값:\n";
	grey.get_remote_mode();

	cout << "\nTv 종료 후 grey\" 리모콘 설정 시도:\n";
	s58.onoff();
	s58.settings();
	s58.remote_mode_toggle(grey);
	grey.get_remote_mode();


	return 0;
}