#include <assert.h>
#include<iostream.h>
　 　　
char * strcpy(char * strDest ,const char *strSrc)
{ 　　
	assert((strDest!=NULL) && (strSrc !=NULL));
	char * strDestCopy=strDest;
	while ((*strDest++=*strSrc++)!='\0');
	return strDestCopy; 　　
} 　　

int main()
{
	char a[20],c[]="i am teacher!";
	strcpy(a,c);
	cout<<a<<endl;

	return 0;
}

/*
[1] 　　
	(A)不检查指针的有效性，说明答题者不注重代码的健壮性。
	(B)检查指针的有效性时使用((!strDest)||(!strSrc))或(! (strDest&&strSrc))，说明答题者对C语言中类型的隐式转换没有深刻认识。
	在本例中char *转换为bool即是类型隐式转换，这种功能虽然灵活，但更多的是导致出错概率增大和维护成本升高。
	所以C++专门增加了bool、true、false 三个关键字以提供更安全的条件表达式。
	(C)检查指针的有效性时使用((strDest==0)||(strSrc==0))，说明答题者不知道使用常量的好处。
	直接使用字面常量（如本例中的0）会减少程序的可维护性。0虽然简单，但程序中可能出现很多处对指针的检查，万一出现笔误，编译器不能发现，生成的程序内含逻辑错误，很难排除。
	而使用NULL代替0，如果出现拼写错误，编译器就会检查出来。
	 　　
[2] 
　　(A)return new string("Invalid argument(s)");，说明答题者根本不知道返回值的用途，并且他对内存泄漏也没有警惕心。
	从函数中返回函数体内分配的内存是十分危险的做法，他把释放内存的义务抛给不知情的调用者，绝大多数情况下，调用者不会释放内存，这导致内存泄漏。
	(B)return 0;，说明答题者没有掌握异常机制。调用者有可能忘记检查返回值，调用者还可能无法检查返回值（见后面的链式表达式）。
	妄想让返回值肩负返回正确值和异常值的双重功能，其结果往往是两种功能都失效。应该以抛出异常来代替返回值，这样可以减轻调用者的负担、使错误不会被忽略、增强程序的可维护性。

[3] 　
	(A)忘记保存原始的strDest值，说明答题者逻辑思维不严密。

[4] 　
	(A)循环写成while (*strDest++=*strSrc++);，同[1](B)。 
	(B)循环写成while (*strSrc!='\0') *strDest++=*strSrc++;，说明答题者对边界条件的检查不力。循环体结束后，strDest字符串的末尾没有正确地加上'\0'。 　　
	2.返回strDest的原始值使函数能够支持链式表达式，增加了函数的"附加值"。同样功能的函数，如果能合理地提高的可用性，自然就更加理想。
	链式表达式的形式如：int iLength=strlen(strcpy(strA,strB));
	又如：char * strA=strcpy(new char[10],strB); 返回strSrc的原始值是错误的。
	其一，源字符串肯定是已知的，返回它没有意义。
	其二，不能支持形如第二例的表达式。
	其三，为了保护源字符串，形参用const限定strSrc所指的内容，把const char *作为char *返回，类型不符，编译报错。
	在上面的语句中，循环语句while ((*strDest++=*strSrc++)!='\0');较难理解，可以把这句理解为一下操作。
	
	第一种： 　　while(1) 　　{ 　　char temp; 　　temp=*strDest=*strSrc; 　　strDest++; 　　strSrc++; 　　if('/0'==temp) 　　break; 　　} 
	第二种： 　　while(*strSrc!='/0') 　　{ 　　*strDest=*strSrc; 　　strDest++; 　　strSrc++; 　　} 　　*strDest=*strSrc; 
*/　