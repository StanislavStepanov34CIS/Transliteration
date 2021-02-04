#include "StdAfx.h"
#include <cfixcc.h>
#include "Functions.h"
class functionsTest : public cfixcc::TestFixture
{
private:

public:
	void abcLatinValidatorTests()
	{
		std::string lat1[] = {"a","b","c","d"};
		std::string lat2[] = {"a","b`","c","d"};
		std::string lat3[] = {"a","b","c","d2"};

		std::vector<std::string> latin1(lat1, lat1+4);
		std::vector<std::string> latin2(lat2, lat2+4);
		std::vector<std::string> latin3(lat3, lat3+4);

		CFIX_ASSERT_MESSAGE(true==abcLatinValidator(latin1), L"� �������� ������ ��� ����������� ��������, �� ������� �����");
		CFIX_ASSERT_MESSAGE(false==abcLatinValidator(latin2), L"� �������� ������ ���� ����������� ��������, �� ������� �� �����");
		CFIX_ASSERT_MESSAGE(false==abcLatinValidator(latin3), L"� �������� ������ ���� ����������� ��������, �� ������� �� �����");
	}

	void abcSizesValidatorTests()
	{
		std::string lat1[] = {"a","b","c","d"};
		std::string lat2[] = {"a","b","c","dd"};
		std::string lat3[] = {"a","b","ccc","d"};
		std::string lat4[] = {"a","bbbb","c","d"};

		std::vector<std::string> latin1(lat1, lat1+4);
		std::vector<std::string> latin2(lat2, lat2+4);
		std::vector<std::string> latin3(lat3, lat3+4);
		std::vector<std::string> latin4(lat4, lat4+4);

		CFIX_ASSERT_MESSAGE(true==abcSizesValidator(latin1), L"������������ ������ ������������� � ������� �������� ����� 1");
		CFIX_ASSERT_MESSAGE(true==abcSizesValidator(latin2), L"������������ ������ ������������� � ������� �������� ����� 2");
		CFIX_ASSERT_MESSAGE(true==abcSizesValidator(latin3), L"������������ ������ ������������� � ������� �������� ����� 3");
		CFIX_ASSERT_MESSAGE(false==abcSizesValidator(latin4), L"������������ ������ ������������� � ������� �������� ����� 4");
	}

	void abcOverlapValidatorTests()
	{
		std::string lat1[] = {"a","b","c","d"};
		std::string cyr1[] = {"�","�","�","�"};

		std::string lat2[] = {"a","b","c","a"};
		std::string cyr2[] = {"�","�","�","�"};

		std::string lat3[] = {"a","b","c","d"};
		std::string cyr3[] = {"�","�","�","�"};

		std::vector<std::string> latin1(lat1, lat1+4);
		std::vector<std::string> latin2(lat2, lat2+4);
		std::vector<std::string> latin3(lat3, lat3+4);

		std::vector<std::string> cyril1(cyr1, cyr1+4);
		std::vector<std::string> cyril2(cyr2, cyr2+4);
		std::vector<std::string> cyril3(cyr3, cyr3+4);

		CFIX_ASSERT_MESSAGE(true==abcOverlapValidator(latin1, cyril1), L"� �������� ������� ��� ���������� ������������� ��������, �� ������� �����");
		CFIX_ASSERT_MESSAGE(false==abcOverlapValidator(latin2, cyril2), L"� �������� ������� ���� ���������� ������������� �������� � ��������� �����, �� ������� �� �����");
		CFIX_ASSERT_MESSAGE(false==abcOverlapValidator(latin3, cyril3), L"� �������� ������� ���� ���������� ������������� �������� � ������������� �����, �� ������� �� �����");
	}

	void abcCountFileValidatorTests()
	{
		std::string cyril1 = "�;�;�;�";
		std::string cyril2 = "�;�;�";
		std::string cyril3 = "�;�;�;�";

		std::string latin1 = "a;b;c;d";
		std::string latin2 = "a;b;c;d";
		std::string latin3 = "a;b;c";

		CFIX_ASSERT_MESSAGE(true==abcCountFileValidator(latin1, cyril1), L"� �������� ������� ���-�� ��������� � ������������� ������������� ���������, ������� ��������� �����������");
		CFIX_ASSERT_MESSAGE(false==abcCountFileValidator(latin2, cyril2), L"� �������� ������� ���-�� ��������� � ������������� ������������� �� ���������, ������� ��������� �����������");
		CFIX_ASSERT_MESSAGE(false==abcCountFileValidator(latin3, cyril3), L"� �������� ������� ���-�� ��������� � ������������� ������������� �� ���������, ������� ��������� �����������");
	}

	void canTranslitTests()
	{
		std::string cyr[] = {"�","�","�"};
		std::string lat[] = {"a","ab","bb"};
		std::vector<std::string> latin(lat, lat+3);
		std::vector<std::string> cyril(cyr, cyr+3);
		std::map<std::string,std::string> abc;
		for(size_t i=0; i<latin.size(); i++)
		{
			abc[latin[i]]=cyril[i];
		}
		std::string src1 = "abbb";
		std::string src2 = "abb";
		std::string src3 = "b";

		CFIX_ASSERT_MESSAGE(true==(bool)canTranslit(src1,abc,0), L"������ \"abbb\" ����� ��������������� ��� \"��\", ����� �������������� ������� � ����� (�������� �������: a=�, �=ab, �=bb)");
		CFIX_ASSERT_MESSAGE(true==(bool)canTranslit(src2,abc,0), L"������ \"abb\" ����� ��������������� ��� \"��\", ����� �������������� ������� � ����� (�������� �������: a=�, �=ab, �=bb)");
		CFIX_ASSERT_MESSAGE(false==(bool)canTranslit(src3,abc,0), L"������ \"b\" ������ ��������������� �.�. ��� ��� ���������� ������������� ������ � �������� ������� (�������� �������: a=�, �=ab, �=bb)");
	}
	
	void TranslitTests()
	{
		std::string cyr[] = {"�","�","�"};
		std::string lat[] = {"a","ab","bb"};
		std::vector<std::string> latin(lat, lat+3);
		std::vector<std::string> cyril(cyr, cyr+3);
		std::map<std::string,std::string> abc;
		for(size_t i=0; i<latin.size(); i++)
		{
			abc[latin[i]]=cyril[i];
		}
		std::string src1 = "abbb";
		std::string src2 = "abb";
		std::string src3 = "b";
	
		CFIX_ASSERT_MESSAGE("��"==Translit(src1,abc), L"������ \"abbb\" ����� ��������������� ��� \"��\", ����� �������������� ������� � ����� (�������� �������: a=�, �=ab, �=bb)");
		CFIX_ASSERT_MESSAGE("��"==Translit(src2,abc), L"������ \"abb\" ����� ��������������� ��� \"��\", ����� �������������� ������� � ����� (�������� �������: a=�, �=ab, �=bb)");
		CFIX_ASSERT_MESSAGE("~"==Translit(src3,abc), L"������ \"b\" ������ ��������������� �.�. ��� ��� ���������� ������������� ������ � �������� ������� (�������� �������: a=�, �=ab, �=bb)");
	}
};

/*CFIXCC_BEGIN_CLASS(functionsTest)
	CFIXCC_METHOD(abcLatinValidatorTests)
	CFIXCC_METHOD(abcSizesValidatorTests)
	CFIXCC_METHOD(abcOverlapValidatorTests)
	CFIXCC_METHOD(abcCountFileValidatorTests)
	CFIXCC_METHOD(canTranslitTests)
	CFIXCC_METHOD(TranslitTests)
CFIXCC_END_CLASS()*/

