#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include <iostream>
#include <ctime>
#include <fstream>

#pragma warning(disable : 4996)

#define W(x, y)  << std::setw(x) << (y) <<
#define STR(n, line, type, id)\
	"|" W(4,n) " |  " W(5,line) "    |" W(17,type) " |  " W(SCOPED_ID_MAXSIZE, id) " |"


namespace Log
{
	LOG getstream(wchar_t  logfile[])
	{
		LOG stream;
		stream.stream = new std::ofstream;
		stream.stream->open(logfile, std::ios::binary);
		if (!stream.stream->is_open())
			throw ERROR_THROW(103);

		unsigned char bom[] = { 0xEF, 0xBB, 0xBF };
		stream.stream->write(reinterpret_cast<char*>(bom), 3);
		wcscpy_s(stream.logfile, logfile);
		return stream;
	}

	void writeLog(LOG& log)
	{
		char buffer[80];
		time_t seconds = time(NULL);
		tm* timeinfo = localtime(&seconds);
		const char* format = "%d.%m.%Y %H:%M:%S";
		strftime(buffer, 80, format, timeinfo);
		*log.stream << "\n----------- Compiler BKA-2025 ------------ Date: " << buffer << " ------------ \n\n";
	}
 
	
	
	void writeLine(std::ostream* stream, char* c, ...)
	{
		char** ptr = &c;
		char* result;
		result = new char[15];
		int size = 0;

		while (strcmp(*ptr, "") != 0)
		{
			size_t slen = strlen(*ptr);
			result = (char*)realloc(result, size + slen);
			result[size] = '\0';
			size += slen;
			strcat_s(result, size + 1, *ptr);
			ptr++;
		}
		*stream << result << std::endl;
	}

	void writeParm(LOG& log, Parm::PARM& parm)
	{
		char inTxt[PARM_MAX_SIZE],
			outTxt[PARM_MAX_SIZE],
			logTxt[PARM_MAX_SIZE];
		wcstombs(inTxt, parm.in, wcslen(parm.in) + 1);
		wcstombs(outTxt, parm.out, wcslen(parm.out) + 1);
		wcstombs(logTxt, parm.log, wcslen(parm.log) + 1);
		*log.stream << "\n----- Settings --------";
		*log.stream << "\n-in: " << inTxt
			<< "\n-out: " << outTxt
			<< "\n-log: " << logTxt;
	}

	void writeIn(std::ostream* stream, In::IN& in)
	{
		*stream << "\n---- Initial data ------";
		*stream << "\nSymbol count: " << std::setw(3) << in.size
			<< "\nIgnored: " << std::setw(3) << in.ignor
			<< "\nLines count: " << std::setw(3) << in.lines << "\n\n";
	}

	void writeError(std::ostream* stream, Error::ERROR e)
	{
		//  -
		if (stream != NULL)
		{
			if (e.position.col == -1 || e.position.line == -1)
				*stream << std::endl << " N" << e.id << ": " << e.message;
			else if (e.position.col == 0)
				*stream << std::endl << " N" << e.id << ": " << e.message
				<< " : " << e.position.line;
			else
				*stream << std::endl << " N" << e.id << ": " << e.message
				<< " : " << e.position.line
				<< ": " << e.position.col;
			*stream << std::endl;
		}
		
		// 
		
		throw ERROR_THROW(e.id);
	}

	void writeWords(std::ostream* stream, In::InWord* words)
	{
		*stream << " ------------------ Word table: ------------------" << std::endl;
		for (int i = 0; i < words->size; i++)
			*stream << std::setw(2) << i << std::setw(3) << words[i].line << " |  " << words[i].word << std::endl;
		*stream << "\n-------------------------------------------------------------------------\n\n";
	}

	void Close(LOG& log)
	{
		(*log.stream).close();
	}
};
