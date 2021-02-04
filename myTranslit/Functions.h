#include "stdafx.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <locale.h>

/*Функиция проверяет есть ли нелатинские символы в части с латинским представлением алфавита
	\param [in] lat - латинская часть алфавита
*/
bool abcLatinValidator(std::vector<std::string>& lat);

/*Функиция проверяет максимальный размер представления в словаре
	\param [in] lat - латинская часть алфавита
*/
bool abcSizesValidator(std::vector<std::string>& lat);

/*Функиция проверяет повторения представлений в словаре
	\param [in] lat - кириллическая часть алфавита
	\param [in] tus - латинская часть алфавита
*/
bool abcOverlapValidator(std::vector<std::string>& lat,std::vector<std::string>& rus);

/*Функиция проверяет кол-во кириллических и латинских представлений символов
	\param [in] rus - кириллическая часть алфавита
	\param [in] lat - латинская часть алфавита
*/
bool abcCountFileValidator(std::string& rus, std::string& lat);

/*Функиция проверяет, можно ли транслитировать текущую последовательность символов, не заводя транслитерацию в тупик
	\param [in] src - транлитируемый текст
	\param [in] abc - словарь правил транслитерации
	\param [in] translitPos - позиция транслитерации
*/
int canTranslit(const std::string& src, const std::map<std::string,std::string>& abc, int translitPos);

/*Функция транслитерации
	\param [in] src - транслитируемый текст
	\param [in] abc - словарь, где ключи это русский алфавит на кириллице, а содержимое - русский алфавит на латинице. 
*/
std::string Translit(const std::string& src, const std::map<std::string,std::string> abc);