#include "manager.h"

//static enum FileType {
//	File_head,
//	File_tail,
//	File_Rule,
//	File_Map,
//	File_ObjectInfo,
//	FileTypeNum
//};

typedef struct FileStorage {
	FILE* address;
	struct FileStorage* next;
} FileStorage;

typedef struct MemmoryStorage {
	void* address;
	struct MemmoryStorage* next;
	int size;
} MemmoryStorage;


static FileStorage* file_list;
static MemmoryStorage* memmory_list;


int ManagerInit()
{
	//creating quit end point

	file_list = (FileStorage*)malloc(sizeof(FileStorage));
	if (file_list == NULL)
		return -1;
	file_list->address = NULL;
	file_list->next = NULL;


	memmory_list = (MemmoryStorage*)malloc(sizeof(MemmoryStorage));
	if (memmory_list == NULL)
		return -2;
	memmory_list->address = NULL;
	memmory_list->next = NULL;
	memmory_list->size = 0;

	return 0;
}


FILE* FileLoad(const char* file_name)
{
	FILE* new_file;
	FileStorage* temp;

	new_file = fopen(file_name, "r");	//file open (main purpose of this function)
	temp = (FileStorage*)malloc(sizeof(FileStorage));
	if (temp == NULL)
		return NULL;
	temp->address = new_file;
	temp->next = file_list;
	file_list = temp;

	return new_file;
}


const char* MemmoryAllocate(int size)
{
	char* new_memmory;
	MemmoryStorage* temp;

	new_memmory = (char*)malloc(size);	//memmory allocate (main purpose of this function)
	temp = (MemmoryStorage*)malloc(sizeof(MemmoryStorage));
	if (temp == NULL)
		return NULL;
	temp->address = new_memmory;
	temp->next = memmory_list;
	temp->size = size;
	memmory_list = temp;

	return new_memmory;
}


int FileUnload()
{
	return 0;
}

int ManagerQuit()
{

	while (file_list != NULL)
	{
		FileStorage* temp = file_list->next;
		fclose(file_list->address);
		free(file_list);
		file_list = temp;
	}

	while (memmory_list != NULL)
	{
		MemmoryStorage* temp = memmory_list->next;
		free(memmory_list->address);
		free(memmory_list);
		memmory_list = temp;
	}

	return 0;
}
