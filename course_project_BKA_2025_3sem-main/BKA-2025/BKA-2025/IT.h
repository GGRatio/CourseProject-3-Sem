#pragma once
#include <iostream>

#define MAXSIZE_ID	16
#define SCOPED_ID_MAXSIZE   MAXSIZE_ID*2
#define MAXSIZE_TI		4096
#define INT_DEFAULT	0x00000000
#define STR_DEFAULT	0x00
#define NULLIDX_TI		0xffffffff
#define STR_MAXSIZE	255
#define CHAR_MAXSIZE 1
#define INT_MAXSIZE   127
#define INT_MINSIZE   -128
#define MAX_PARAMS_COUNT 2
#define POW_PARAMS_CNT 2
#define ABS_PARAMS_CNT 1
#define POW_TYPE IT::IDDATATYPE::INT
#define ABS_TYPE IT::IDDATATYPE::INT

namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, PROC = 3, CHAR = 4, UNDEF };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };
	enum STDFNC { F_POW, F_ABS, F_NOT_STD };
	static const IDDATATYPE POW_PARAMS[] = { IT::IDDATATYPE::INT, IT::IDDATATYPE::INT };
	static const IDDATATYPE ABS_PARAMS[] = { IT::IDDATATYPE::INT };
	struct Entry
	{
		union
		{
			int	vint;
			struct
			{
				int len;
				char str[STR_MAXSIZE - 1];
			} vstr;
			struct
			{
				int count;
				IDDATATYPE* types;
			} params;
		} value;
		int			idxfirstLE;
		char		id[SCOPED_ID_MAXSIZE];
		IDDATATYPE	iddatatype;
		IDTYPE		idtype;

		Entry()
		{
			this->value.vint = INT_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.params.count = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype)
		{
			strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};
	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(int size = NULL);
	void Add(IdTable& idtable, Entry entry);
	int isId(IdTable& idtable, char id[SCOPED_ID_MAXSIZE]);
	bool SetValue(IT::Entry* entry, char* value);
	bool SetValue(IT::IdTable& idtable, int index, char* value);
	void writeIdTable(std::ostream* stream, IT::IdTable& idtable);
};
