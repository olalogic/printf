#ifndef main_h
#define main_h
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fm_t: The function associated
 */
typedef struct fmt fmt_t;

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
int printer(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int char_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int string_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int percent_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int int_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int binary_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int unsigned_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int octal_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hex_lower_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int hex_upper_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int hex_plus(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int ex_string_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int pointer_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flag_handler(const char *format, int *i);
int width_handler(const char *format, int *i, va_list list);
int precision_handler(const char *format, int *i, va_list list);
int size_handler(const char *format, int *i);

/*Function to print string in reverse*/
int rev_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int rot13_handler(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif 
