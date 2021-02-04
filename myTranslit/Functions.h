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

/*�������� ��������� ���� �� ����������� ������� � ����� � ��������� �������������� ��������
	\param [in] lat - ��������� ����� ��������
*/
bool abcLatinValidator(std::vector<std::string>& lat);

/*�������� ��������� ������������ ������ ������������� � �������
	\param [in] lat - ��������� ����� ��������
*/
bool abcSizesValidator(std::vector<std::string>& lat);

/*�������� ��������� ���������� ������������� � �������
	\param [in] lat - ������������� ����� ��������
	\param [in] tus - ��������� ����� ��������
*/
bool abcOverlapValidator(std::vector<std::string>& lat,std::vector<std::string>& rus);

/*�������� ��������� ���-�� ������������� � ��������� ������������� ��������
	\param [in] rus - ������������� ����� ��������
	\param [in] lat - ��������� ����� ��������
*/
bool abcCountFileValidator(std::string& rus, std::string& lat);

/*�������� ���������, ����� �� ��������������� ������� ������������������ ��������, �� ������ �������������� � �����
	\param [in] src - �������������� �����
	\param [in] abc - ������� ������ ��������������
	\param [in] translitPos - ������� ��������������
*/
int canTranslit(const std::string& src, const std::map<std::string,std::string>& abc, int translitPos);

/*������� ��������������
	\param [in] src - ��������������� �����
	\param [in] abc - �������, ��� ����� ��� ������� ������� �� ���������, � ���������� - ������� ������� �� ��������. 
*/
std::string Translit(const std::string& src, const std::map<std::string,std::string> abc);