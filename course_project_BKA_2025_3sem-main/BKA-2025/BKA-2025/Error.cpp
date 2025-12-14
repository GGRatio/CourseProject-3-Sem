//TODO: Все ошибки до синтаксических (600) выводятся дважды 
// решено
//TODO: Не корректное отображение строки ошибки
//решено


#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "Системная ошибка: неопознанный тип ошибки"),
		ERROR_ENTRY(1, "Системная ошибка: системный сбой"),
		ERROR_ENTRY_NODEF(2), ERROR_ENTRY_NODEF(3), ERROR_ENTRY_NODEF(4), ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6), ERROR_ENTRY_NODEF(7), ERROR_ENTRY_NODEF(8), ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10), ERROR_ENTRY_NODEF10(20), ERROR_ENTRY_NODEF10(30), ERROR_ENTRY_NODEF10(40),
		ERROR_ENTRY_NODEF10(50), ERROR_ENTRY_NODEF10(60), ERROR_ENTRY_NODEF10(70), ERROR_ENTRY_NODEF10(80), ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "Системная ошибка: параметр -in должен быть задан"), //+
		ERROR_ENTRY(101, "Системная ошибка: превышена длина входного параметра"), 
		ERROR_ENTRY(102, "Системная ошибка: ошибка при открытии файла с исходным кодом(-in)"),
		ERROR_ENTRY(103, "Системная ошибка: ошибка при открытии файла протокола(-log)"),
		ERROR_ENTRY_NODEF(104), ERROR_ENTRY_NODEF(105), ERROR_ENTRY_NODEF(106), ERROR_ENTRY_NODEF(107), ERROR_ENTRY_NODEF(108), ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY_NODEF10(110), ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140),
		ERROR_ENTRY_NODEF10(150), ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY(200, "Лексическая ошибка: недопустимый символ в исходном коде(-in)"), //+
		ERROR_ENTRY(201, "Лексическая ошибка: неизвестная последовательность символов"), //+
		ERROR_ENTRY(202, "Лексическая ошибка: неверный размер строки"),
		ERROR_ENTRY(203, "Лексическая ошибка: неверный размер идентификатора"),
		ERROR_ENTRY(204, "Лексическая ошибка: превышена длина значения идентификатора"),
		ERROR_ENTRY_NODEF(205), ERROR_ENTRY_NODEF(206), ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240),
		ERROR_ENTRY_NODEF10(250), ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),
		ERROR_ENTRY(300, "Семантическая ошибка: неопределенный тип идентификатора"),//+
		ERROR_ENTRY(301, "Семантическая ошибка: отсутствует точка входа main"), //+
		ERROR_ENTRY(302, "Семантическая ошибка: повторное объявление точки входа main"), //+
		ERROR_ENTRY(303, "Семантическая ошибка: ошибка в ключевом слове function"), //+ 
		ERROR_ENTRY(304, "Семантическая ошибка: переменная объявлена без ключевого слова var"), //+
		ERROR_ENTRY(305, "Семантическая ошибка: повторное объявление идентификатора"), //+
		ERROR_ENTRY(306, "Семантическая ошибка: превышено количество параметров функции"), //+
		ERROR_ENTRY_NODEF(307), //-
		ERROR_ENTRY(308, "Семантическая ошибка: количество параметров функции не совпадает"), //+
		ERROR_ENTRY(309, "Семантическая ошибка: несоответствие типов параметров функции"), //+
		ERROR_ENTRY(310, "Семантическая ошибка: неправильный размер строкового литерала"), //+
		ERROR_ENTRY(311, "Семантическая ошибка: незакрытый строковый литерал - ожидается символ '\"'"), //+
		ERROR_ENTRY(312, "Семантическая ошибка: слишком длинный строковый литерал (превышен лимит 256 символов)"),//+
		ERROR_ENTRY(313, "Семантическая ошибка: переполнение при арифметической операции"),//+
		ERROR_ENTRY(314, "Семантическая ошибка: несоответствие типов в присваивании"), //+
		ERROR_ENTRY(315, "Семантическая ошибка: несоответствие типа функции и возвращаемого значения"),//+
		ERROR_ENTRY(316, "Семантическая ошибка: недопустимое использование арифметических операторов"), //+
		ERROR_ENTRY(317, "Семантическая ошибка: операнды сравнения должны быть типа byte"), //+
		ERROR_ENTRY(318, "Семантическая ошибка: деление на ноль (0)"), //+
		ERROR_ENTRY(319, "Семантическая ошибка: превышена длина символьного значения"), //+
		ERROR_ENTRY_NODEF(320),ERROR_ENTRY_NODEF(321),ERROR_ENTRY_NODEF(322),ERROR_ENTRY_NODEF(323),
		ERROR_ENTRY_NODEF(324),ERROR_ENTRY_NODEF(325),ERROR_ENTRY_NODEF(326),ERROR_ENTRY_NODEF(327),ERROR_ENTRY_NODEF(328),ERROR_ENTRY_NODEF(329),
		ERROR_ENTRY_NODEF10(330),ERROR_ENTRY_NODEF10(340),ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360),ERROR_ENTRY_NODEF10(370),ERROR_ENTRY_NODEF10(380),ERROR_ENTRY_NODEF10(390),
		ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY(600, "Синтаксическая ошибка: ошибка в объявлении функции или main"),
		ERROR_ENTRY(601, "Синтаксическая ошибка: ошибка в скобках параметров функции"),
		ERROR_ENTRY(602, "Синтаксическая ошибка: ошибка в теле функции с return"),
		ERROR_ENTRY(603, "Синтаксическая ошибка: ошибка в теле функции void"),
		ERROR_ENTRY(604, "Синтаксическая ошибка: ошибка в списке параметров функции (ожидается запятая)"),
		ERROR_ENTRY(605, "Синтаксическая ошибка: ошибка в вызове функции (скобки)"),
		ERROR_ENTRY(606, "Синтаксическая ошибка: ошибка в параметрах вызова функции (ожидается запятая)"),
		ERROR_ENTRY(607, "Синтаксическая ошибка: ошибка в операторе return"),
		ERROR_ENTRY(608, "Синтаксическая ошибка: ошибка в блоке if/else (скобки)"),
		ERROR_ENTRY(609, "Синтаксическая ошибка: ошибка в условии сравнения"),
		ERROR_ENTRY(610, "Синтаксическая ошибка: В сравнение должна участвовать переменная"),
		ERROR_ENTRY(611, "Синтаксическая ошибка: ошибка в арифметическом операторе (ожидается +, -, *, /, %)"),
		ERROR_ENTRY(612, "Синтаксическая ошибка: ошибка в значении (ожидается литерал, идентификатор или строка)"), //+
		ERROR_ENTRY(613, "Синтаксическая ошибка: ошибка в выражении"),
		ERROR_ENTRY(614, "Синтаксическая ошибка: ошибка в операторе (ожидается точка с запятой)"),
		ERROR_ENTRY(615, "Синтаксическая ошибка: ошибка в операторе в блоке if/else (ожидается точка с запятой)"),
		ERROR_ENTRY_NODEF(616), ERROR_ENTRY_NODEF(617),ERROR_ENTRY_NODEF(618), ERROR_ENTRY_NODEF(619),
		ERROR_ENTRY_NODEF10(620), ERROR_ENTRY_NODEF10(630), ERROR_ENTRY_NODEF10(640), ERROR_ENTRY_NODEF10(650),
		ERROR_ENTRY_NODEF10(660), ERROR_ENTRY_NODEF10(670), ERROR_ENTRY_NODEF10(680), ERROR_ENTRY_NODEF10(690),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int col)
	{
		ERROR err = GetError(id);
		err.position.col = col;
		err.position.line = line;
		return err;
	}
}
