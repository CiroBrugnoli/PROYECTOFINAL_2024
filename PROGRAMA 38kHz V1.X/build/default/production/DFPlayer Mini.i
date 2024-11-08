# 1 "DFPlayer Mini.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "DFPlayer Mini.c" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\__null.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3






# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdarg.h" 1 3






typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);
# 11 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3
# 43 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
struct __prbuf
{
 char * ptr;
 void (* func)(char);
};
# 85 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\conio.h" 1 3







# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\errno.h" 1 3
# 29 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\errno.h" 3
extern int errno;
# 8 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\conio.h" 2 3




extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);



extern char * cgets(char *);
extern void cputs(const char *);
# 85 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3



extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);
# 180 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);
# 1 "DFPlayer Mini.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdlib.h" 1 3






typedef unsigned short wchar_t;







typedef struct {
 int rem;
 int quot;
} div_t;
typedef struct {
 unsigned rem;
 unsigned quot;
} udiv_t;
typedef struct {
 long quot;
 long rem;
} ldiv_t;
typedef struct {
 unsigned long quot;
 unsigned long rem;
} uldiv_t;
# 65 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdlib.h" 3
extern double atof(const char *);
extern double strtod(const char *, const char **);
extern int atoi(const char *);
extern unsigned xtoi(const char *);
extern long atol(const char *);



extern long strtol(const char *, char **, int);

extern int rand(void);
extern void srand(unsigned int);
extern void * calloc(size_t, size_t);
extern div_t div(int numer, int denom);
extern udiv_t udiv(unsigned numer, unsigned denom);
extern ldiv_t ldiv(long numer, long denom);
extern uldiv_t uldiv(unsigned long numer,unsigned long denom);



extern unsigned long _lrotl(unsigned long value, unsigned int shift);
extern unsigned long _lrotr(unsigned long value, unsigned int shift);
extern unsigned int _rotl(unsigned int value, unsigned int shift);
extern unsigned int _rotr(unsigned int value, unsigned int shift);




extern void * malloc(size_t);
extern void free(void *);
extern void * realloc(void *, size_t);




# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 3
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 99 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdlib.h" 2 3





extern int atexit(void (*)(void));
extern char * getenv(const char *);
extern char ** environ;
extern int system(char *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void * bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int abs(int);
extern long labs(long);

extern char * itoa(char * buf, int val, int base);
extern char * utoa(char * buf, unsigned val, int base);




extern char * ltoa(char * buf, long val, int base);
extern char * ultoa(char * buf, unsigned long val, int base);

extern char * ftoa(float f, int * status);
# 2 "DFPlayer Mini.c" 2
# 16 "DFPlayer Mini.c"
typedef unsigned char UINT8U ;
typedef unsigned char INT8U;
typedef unsigned long INT32U;
typedef unsigned int INT16U;

static INT8U Send_buf[10];
void Delay_Ms(INT32U z)
{
    INT32U x=0 , y=0;
    for(x=110 ; x>0 ;x--)
        for(y=z; y>0;y-- );
}






void Serial_init(void)
{
# 46 "DFPlayer Mini.c"
}

void Uart_PutByte(INT8U ch)
{
    printf("%2x",ch);




}
# 69 "DFPlayer Mini.c"
void SendCmd(INT8U len)
{
    INT8U i = 0 ;
    Uart_PutByte(0x7E);
    for(i=0; i<len; i++)
    {
        Uart_PutByte(Send_buf[i]) ;
    }
    Uart_PutByte(0xEF) ;
}
# 91 "DFPlayer Mini.c"
void DoSum( INT8U *Str, INT8U len)
{
    INT16U xorsum = 0;
    INT8U i;
    for(i=0; i<len; i++)
    {
        xorsum = xorsum + Str[i];
    }
    xorsum = 0 -xorsum;
    *(Str+i) = (INT8U)(xorsum >>8);
    *(Str+i+1) = (INT8U)(xorsum & 0x00ff);
}

void Uart_SendCMD(INT8U CMD ,INT8U feedback , INT16U dat)
{
    Send_buf[0] = 0xff;
    Send_buf[1] = 0x06;
    Send_buf[2] = CMD;
    Send_buf[3] = feedback;
    Send_buf[4] = (INT8U)(dat >> 8);
    Send_buf[5] = (INT8U)(dat);
    DoSum(&Send_buf[0],6);
    SendCmd(8);
}
