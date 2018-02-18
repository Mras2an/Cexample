#define MRAS2AN_DEBUG(msg) printf("[%s][msg line %d in file %s] => %s\n", __DATE__, __LINE__, __FILE__, msg)

#define MIN(a, b)                               ((a) < (b) ? (a) : (b))
#define MAX(a, b)                               ((a) < (b) ? (b) : (a))
#define EGA(a, b)   ((a) == (b) ? 1 : 0)
#define DIFF(a, b)  ((a) != (b) ? 1 : 0)
#define XOR(a, b)   DIFF(a, b)
#define NXOR(a, b)  EGA(a, b)
#define OR(a, b)    ((a) || (b) ? 1 : 0)
#define AND(a, b)   ((a) && (b) ? 1 : 0)
#define NOR(a, b)   (((~a & 0x00000001) && (~b & 0x00000001)) ? 1 : 0)
#define NAND(a, b)  (((~a & 0x00000001) || (~b & 0x00000001)) ? 1 : 0)
