#define MRAS2AN_DEBUG(msg) printf("[%s][msg line %d in file %s] => %s\n", __DATE__, __LINE__, __FILE__, msg)

#define MIN(a, b)                               ((a) < (b) ? (a) : (b))
#define MAX(a, b)                               ((a) < (b) ? (b) : (a))

#define GET_LSBYTE(word)                        (unsigned char)((word) & 0x00FF)  /* Return Low Significant Byte of a word */
#define ASCII_TO_HEXA(ascii)                    (if (ascii > 0x40 && ascii < 0x47) ascii - 0x37 else ascii - 0x30)
#define GET_MSBYTE(word)                        (unsigned char)(((word) & 0xFF00)>> 8) /* Return Most Significant Byte of a word */
#define GET_BIT(word, index)                    (unsigned char)(((word) &(1<<(index)))>>(index)) /* Return indexed bit */
#define SET_BIT(word, index)                    ((word)|= (1<<(index)))  /* Set indexed bit */
#define CLEAR_BIT(word, index)                  ((word) &= ~(1<<(index))) /* Clear indexed bit */
#define TOGGLE_BIT(word, index)                 ((word) ^= (1<<(index)))  /* Toggle indexed bit */
#define TEST_BIT(word, index, value)            ( (((word) & (1<<(index)))==(value)) ? TRUE : FALSE ) /* Return TRUE if indexed bit is equal to value */
#define GET_BIT_BY_ADDRESS(address, index)      ( (unsigned char) (((*(address) & (1<<(index))) >> (index))) )  /* Get indexed bit from the pointed var */
#define SET_BIT_BY_ADDRESS(address, index)      ( *(address) |= ((1)<<(index)) )  /* Set indexed bit from the pointed var */
#define CLEAR_BIT_BY_ADDRESS(address, index)    ( *(address) &= ~((1)<<(index)) ) /* Clear indexed bit from the pointed var */
#define TOGGLE_BIT_BY_ADDRESS(address, index)   ( *(address) ^= ((1)<<(index)) )  /* Toggle indexed bit from the pointed var */
#define TEST_BIT_BY_ADDRESS(word, index, value) ( *(address) & (1<<(index)))==(value)) ? TRUE : FALSE ) /* Return TRUE if indexed bit of the pointed var is equal to value */

#define MERGE_NIBBLES_TO_BYTE(nib_H, nib_L)     ( (((unsigned char)(nib_H)) << 4)  |  ((unsigned char)(nib_L)) )

#define MERGE_BYTES_TO_WORD(byte_H, byte_L)     ( (((unsigned short)(byte_H)) << 8)  |  ((unsigned short)(byte_L)) )

#define MERGE_BYTES_TO_LONG(byte_H, byte_M, byte_L)     ( (((unsigned short)(byte_H)) << 16) | (((unsigned short)(byte_M)) << 8)  | ((unsigned short)(byte_L)) )

#define GET_LOW_BYTE_FROM_WORD(word)            ( (unsigned char)( ((word)>> 0) & 0x00FF )  )       /* Return Low Significant Byte of a word */
#define GET_HIGH_BYTE_FROM_WORD(word)           ( (unsigned char)( ((word)>> 8) & 0x00FF )  )       /* Return High Significant Byte of a word */

#define GET_LOW_WORD_FROM_LONG(Long)            ( (unsigned short)( ((Long)>> 0) & 0x0000FFFFL ) )   /* Return Low Significant word of a long */
#define GET_HIGH_WORD_FROM_LONG(Long)           ( (unsigned short)( ((Long)>>16) & 0x0000FFFFL ) )   /* Return High Significant word of a long */

#define GET_LOW_BYTE_FROM_LOW_LONG(Long)        ( GET_LOW_BYTE_FROM_WORD(  GET_LOW_WORD_FROM_LONG(Long)  ) )
#define GET_HIGH_BYTE_FROM_LOW_LONG(Long)       ( GET_HIGH_BYTE_FROM_WORD( GET_LOW_WORD_FROM_LONG(Long)  ) )
#define GET_LOW_BYTE_FROM_HIGH_LONG(Long)       ( GET_LOW_BYTE_FROM_WORD(  GET_HIGH_WORD_FROM_LONG(Long) ) )
#define GET_HIGH_BYTE_FROM_HIGH_LONG(Long)      ( GET_HIGH_BYTE_FROM_WORD( GET_HIGH_WORD_FROM_LONG(Long) ) )

