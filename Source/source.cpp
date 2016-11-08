#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> string_split(const string &line, const string &spliter)
{ //splits the strings into substring divided by the given splitter
	unsigned int pos_spliter = 0, cont_spliter = 0, sz = line.size(), splt_sz = spliter.size(), inicio = 0;
	vector<string> split_string;

	for (unsigned int i = 0; i < sz; i++)
	{
		if (i == sz - 1)
		{
			pos_spliter = i + 1;
			split_string.push_back(line.substr(inicio, pos_spliter - inicio));
			break;
		}

		if (line.at(i) == spliter.at(cont_spliter))
		{
			if (cont_spliter != splt_sz)
				cont_spliter++;
			if (cont_spliter == splt_sz)
			{
				pos_spliter = i - (splt_sz - 1);
				split_string.push_back(line.substr(inicio, pos_spliter - inicio));
				inicio = pos_spliter + 1;
				inicio = i + 1;
				cont_spliter = 0;
			}
		}
	}
	return split_string;
}


int main(){
	string m = "S";
	cout << "HELLO" << endl;
	cout << m;
}
