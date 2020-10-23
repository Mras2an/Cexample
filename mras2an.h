#define MRAS2AN_DEBUG(msg) printf("[%s][msg line %d in file %s] => %s\n", __DATE__, __LINE__, __FILE__, msg)

/***********************************************************************/

#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) < (b) ? (b) : (a))
#define EGA(a, b)   ((a) == (b) ? 1 : 0)
#define DIFF(a, b)  ((a) != (b) ? 1 : 0)
#define XOR(a, b)   DIFF(a, b)
#define NXOR(a, b)  EGA(a, b)
#define OR(a, b)    ((a) || (b) ? 1 : 0)
#define AND(a, b)   ((a) && (b) ? 1 : 0)
#define NOR(a, b)   (((~a & 0x00000001) && (~b & 0x00000001)) ? 1 : 0)
#define NAND(a, b)  (((~a & 0x00000001) || (~b & 0x00000001)) ? 1 : 0)

/**************************** EX 1 ***************************************/

#define GPIO_BP_1_PORT  "A"
#define GPIO_BP_1_PIN   "2"
#define GPIO_BP_1_MODE  "INPUT"

#define print_gpio(val)\
{\
  printf("%s\n%s\n%s\n", val##_PORT, val##_PIN, val##_MODE);\
}

/**************************** EX 2 ***************************************/

struct registre {
unsigned int  header : 3;
int           cmd : 6;
unsigned int  : 6;  /* useless */
unsigned int  type : 1;
};

/*
*  | 15 |14|13|12|11|10|9|8|7|6|5|4|3|2|1|0 |
*  |type|   useless    |     cmd     |header|
*/
