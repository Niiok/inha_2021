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


int Manager_ManagerInit()
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


FILE* Manager_FileLoad(const char* file_name)
{
	FILE* new_file;
	FileStorage* temp_storage;

	new_file = fopen(file_name, "r");	//file open (main purpose of this function)
	temp_storage = (FileStorage*)malloc(sizeof(FileStorage));
	if (temp_storage == NULL)
		exit(999);  //return NULL;
	temp_storage->address = new_file;
	temp_storage->next = file_list;
	file_list = temp_storage;

	return new_file;
}


const char* Manager_MemmoryAllocate(int size)
{
	char* new_memmory;
	MemmoryStorage* temp_storage;

	new_memmory = (char*)malloc(size);	//memmory allocate (main purpose of this function)
	temp_storage = (MemmoryStorage*)malloc(sizeof(MemmoryStorage));
	if (temp_storage == NULL)
		exit(999); // return NULL;
	temp_storage->address = new_memmory;
	temp_storage->next = memmory_list;
	temp_storage->size = size;
	memmory_list = temp_storage;

	return new_memmory;
}


int Manager_FileUnload(FILE* file_address)
{
	FileStorage* temp_storage = file_list;
	FileStorage* storage_to_free = temp_storage->next;

	while(storage_to_free != NULL)
	{
		if (storage_to_free->address == file_address)
			break;
		else
		{
			temp_storage = storage_to_free;
			storage_to_free = temp_storage->next;
		}
	}
	if (storage_to_free == NULL)
		return -1;

	fclose(storage_to_free->address);		// main objective
	temp_storage->next = storage_to_free->next;
	free(storage_to_free);

	return 0;
}

int Manager_MemmoryFree(const char* memmory_address)
{
	MemmoryStorage* temp_storage = memmory_list;
	MemmoryStorage* storage_to_free = temp_storage->next;

	while (storage_to_free != NULL)
	{
		if (storage_to_free->address == memmory_address)
			break;
		else
		{
			temp_storage = storage_to_free;
			storage_to_free = temp_storage->next;
		}
	}
	if (storage_to_free == NULL)
		return -1;

	free(storage_to_free->address);			// main objective
	temp_storage->next = storage_to_free->next;
	free(storage_to_free);

	return 0;
}


int Manager_ManagerQuit()
{

	while (file_list != NULL)
	{
		FileStorage* temp = file_list->next;
		if (file_list->address != NULL)
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
