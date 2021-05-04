class Object {
public:
	Object()
	{

	}
	~Object()
	{


	}

private:

	int x_ = -1;
	int y_ = -1;
	int bIsTick_;
	int bIsMovable_;
	int bIsGettable_;
	int bIsSettable_;
	int bIsTrashable_;

public:

	virtual int Tick_()	//special move per frame
	{

	}

	virtual int Move_()	//moved by player
	{

	}

	virtual int Use_()	//use object inside inventory
	{

	}

	virtual int Trash_()	//trash object inside inventory
	{

	}

	virtual int Get_()	//try to get object on map
	{

	}

	virtual int Set_()	//try to place object on map
	{

	}

	virtual int Teleport_()	//move into absolute place
	{

	}

};