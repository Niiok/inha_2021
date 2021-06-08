#ifndef WORKERMI_H_
#define WORKERMI_H_

#include<string>

class Worker {
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fillname("no name"), id(0L) {}
	Worker(const std::string & s, long n) : fullname(s), id(n) {}
	virtual ~Worker() = 0;
	virtual void Sec() = 0;
	virtual void Show() const = 0;
};



class Waiter : virtual public Worker
{
private:
	int panache;
protected:
	void Data() const;
	void Get();
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}
	Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public 



#endif