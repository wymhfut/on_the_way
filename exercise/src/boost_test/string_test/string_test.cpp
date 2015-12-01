#include <boost/algorithm/string/case_conv.hpp>
#include <string>
#include <vector>

int main()
{
	std::string str("Hello");
	std::vector<char> vstr(str.begin(), str.end());
	char *cstr=new char(str.size());

	std::copy(str.begin(), str.end(), cstr);

	boost::to_upper(str); //string
	boost::to_upper(vstr); //vector<char>
	boost::to_upper(cstr); //char*
}