#ifndef TH//这里的#ifndef的作用是头文件只包含一次
#define TH 
int ADD(int x, int y);
#endif
//#gragma once//这个也可以头文件只包含一次但vs2017不认识所以用上一种办法
//int ADD(int x, int y);