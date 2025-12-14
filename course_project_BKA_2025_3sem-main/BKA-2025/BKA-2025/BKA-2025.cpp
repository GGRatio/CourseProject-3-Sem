#include <iostream>
#include "Header.h"

int wmain(int argc, wchar_t* argv[])
{
	// Установка кодировки консоли для корректного вывода русских символов
	system("chcp 1251 > nul");
	setlocale(LC_ALL, "Russian");

	char LEXERROR[] = "Лексический анализ завершен с ошибками";
	char SYNTERROR[] = "Синтаксический анализ завершен с ошибками";
	char SEMERROR[] = "Семантический анализ завершен с ошибками";
	char POLISHERROR[] = "Ошибка при построении польской записи";
	char LEXGOOD[] = "Лексический анализ завершен успешно";
	char SYNTGOOD[] = "Синтаксический анализ завершен успешно";
	char SEMGOOD[] = "Семантический анализ завершен успешно";
	char POLISHGOOD[] = "Польская запись построена успешно";
	char MESSAGE[] = "--------------------Лексема и идентификатор таблицы после польской записи-------------------";
	char STOP[] = "\nВыполнение программы остановлено";
	char ALLGOOD[] = "Все этапы компиляции завершены успешно!";
	Log::LOG log;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getstream(parm.log);
		Log::writeLog(log);
		Log::writeParm(log, parm);
		In::IN in = In::getin(parm.in, log.stream);
		Log::writeIn(log.stream, in);

		in.words = In::getWordsTable(log.stream, in.text, in.code, in.size);
		Lexer::LEX tables;
		bool lex_ok = Lexer::analyze(tables, in, log, parm);
		LT::writeLexTable(log.stream, tables.lextable);
		IT::writeIdTable(log.stream, tables.idtable);
		LT::writeLexemsOnLines(log.stream, tables.lextable);
		if (!lex_ok)
		{
			Log::writeLine(log.stream, LEXERROR, "");
			Log::writeLine(&std::cout, LEXERROR, STOP, "");
			return 0;
		}
		else
		{
			Log::writeLine(&std::cout, LEXGOOD, "");
		}
		MFST_TRACE_START(log.stream);
		MFST::Mfst mfst(tables, GRB::getGreibach());
		bool synt_ok = mfst.start(log);
		mfst.savededucation();
		mfst.printrules(log);
		if (!synt_ok)
		{
			Log::writeLine(log.stream, SYNTERROR, "");
			Log::writeLine(&std::cout, SYNTERROR, STOP, "");
			return 0;
		}
		else Log::writeLine(&std::cout, SYNTGOOD, "");
		bool sem_ok = Semantic::semanticsCheck(tables, log);
		if (!sem_ok)
		{
			Log::writeLine(log.stream, SEMERROR, "");
			Log::writeLine(&std::cout, SEMERROR, STOP, "");
			return 0;
		}
		else Log::writeLine(&std::cout, SEMGOOD, "");
		bool polish_ok = Polish::PolishNotation(tables, log);
		if (!polish_ok)
		{
			Log::writeLine(log.stream, POLISHERROR, "");
			Log::writeLine(&std::cout, POLISHERROR, STOP, "");
			return 0;
		}
		else Log::writeLine(&std::cout, POLISHGOOD, "");
		Log::writeLine(log.stream, MESSAGE, "");
		LT::writeLexTable(log.stream, tables.lextable);
		IT::writeIdTable(log.stream, tables.idtable);
		LT::writeLexemsOnLines(log.stream, tables.lextable);

		Gener::CodeGeneration(tables, parm, log);
	}
	catch (Error::ERROR e)
	{
		std::cout << "Ошибка, " << e.id << ": " << e.message << ", Строка " << e.position.line << ", Позиция " << e.position.col << std::endl;
		system("pause");
	}
	return 0;
}
