// 将从一个文件(read)中内容的内容通过ifstream对象进行读取,
// 然后通过getline逐行读入到字符串str中
// 再将str写入到文件(write)中

#include <fstream>
#include <string>

int main()
{
    std::ifstream in("read");
    std::ofstream out("write");
    std::string str;
    for(; getline(in, str);)                      //从read文件中流向str
    {
        out << str << std::endl;                  //str和换行符 流向write文件中
    }
    return 0;
}
