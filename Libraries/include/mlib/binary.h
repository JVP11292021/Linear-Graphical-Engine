#ifndef _BINARY_H_
#define _BINARY_H_

#define AND		 						&
#define OR		  						|
#define XOR								^

// INTERNAL
#define __HEX__(n) 0x##n##LU
#define __B8__(x) ((x&0x0000000FLU)?1:0) \
  +((x&0x000000F0LU)?2:0) \
  +((x&0x00000F00LU)?4:0) \
  +((x&0x0000F000LU)?8:0) \
  +((x&0x000F0000LU)?16:0) \
  +((x&0x00F00000LU)?32:0) \
  +((x&0x0F000000LU)?64:0) \
  +((x&0xF0000000LU)?128:0)

// EXTERNAL
#define B8(d) ((unsigned char)__B8__(__HEX__(d)))
#define B16(dmsb,dlsb) (((unsigned short)B8(dmsb)<<8) + B8(dlsb))
#define B32(dmsb,db2,db3,dlsb) \
  (((unsigned long)B8(dmsb)<<24) \
  + ((unsigned long)B8(db2)<<16) \
  + ((unsigned long)B8(db3)<<8) \
  + B8(dlsb))

enum {
    ________,_______O,______O_,______OO,_____O__,_____O_O,_____OO_,_____OOO,
    ____O___,____O__O,____O_O_,____O_OO,____OO__,____OO_O,____OOO_,____OOOO,
    ___O____,___O___O,___O__O_,___O__OO,___O_O__,___O_O_O,___O_OO_,___O_OOO,
    ___OO___,___OO__O,___OO_O_,___OO_OO,___OOO__,___OOO_O,___OOOO_,___OOOOO,
    __O_____,__O____O,__O___O_,__O___OO,__O__O__,__O__O_O,__O__OO_,__O__OOO,
    __O_O___,__O_O__O,__O_O_O_,__O_O_OO,__O_OO__,__O_OO_O,__O_OOO_,__O_OOOO,
    __OO____,__OO___O,__OO__O_,__OO__OO,__OO_O__,__OO_O_O,__OO_OO_,__OO_OOO,
    __OOO___,__OOO__O,__OOO_O_,__OOO_OO,__OOOO__,__OOOO_O,__OOOOO_,__OOOOOO,
    _O______,_O_____O,_O____O_,_O____OO,_O___O__,_O___O_O,_O___OO_,_O___OOO,
    _O__O___,_O__O__O,_O__O_O_,_O__O_OO,_O__OO__,_O__OO_O,_O__OOO_,_O__OOOO,
    _O_O____,_O_O___O,_O_O__O_,_O_O__OO,_O_O_O__,_O_O_O_O,_O_O_OO_,_O_O_OOO,
    _O_OO___,_O_OO__O,_O_OO_O_,_O_OO_OO,_O_OOO__,_O_OOO_O,_O_OOOO_,_O_OOOOO,
    _OO_____,_OO____O,_OO___O_,_OO___OO,_OO__O__,_OO__O_O,_OO__OO_,_OO__OOO,
    _OO_O___,_OO_O__O,_OO_O_O_,_OO_O_OO,_OO_OO__,_OO_OO_O,_OO_OOO_,_OO_OOOO,
    _OOO____,_OOO___O,_OOO__O_,_OOO__OO,_OOO_O__,_OOO_O_O,_OOO_OO_,_OOO_OOO,
    _OOOO___,_OOOO__O,_OOOO_O_,_OOOO_OO,_OOOOO__,_OOOOO_O,_OOOOOO_,_OOOOOOO,
    O_______,O______O,O_____O_,O_____OO,O____O__,O____O_O,O____OO_,O____OOO,
    O___O___,O___O__O,O___O_O_,O___O_OO,O___OO__,O___OO_O,O___OOO_,O___OOOO,
    O__O____,O__O___O,O__O__O_,O__O__OO,O__O_O__,O__O_O_O,O__O_OO_,O__O_OOO,
    O__OO___,O__OO__O,O__OO_O_,O__OO_OO,O__OOO__,O__OOO_O,O__OOOO_,O__OOOOO,
    O_O_____,O_O____O,O_O___O_,O_O___OO,O_O__O__,O_O__O_O,O_O__OO_,O_O__OOO,
    O_O_O___,O_O_O__O,O_O_O_O_,O_O_O_OO,O_O_OO__,O_O_OO_O,O_O_OOO_,O_O_OOOO,
    O_OO____,O_OO___O,O_OO__O_,O_OO__OO,O_OO_O__,O_OO_O_O,O_OO_OO_,O_OO_OOO,
    O_OOO___,O_OOO__O,O_OOO_O_,O_OOO_OO,O_OOOO__,O_OOOO_O,O_OOOOO_,O_OOOOOO,
    OO______,OO_____O,OO____O_,OO____OO,OO___O__,OO___O_O,OO___OO_,OO___OOO,
    OO__O___,OO__O__O,OO__O_O_,OO__O_OO,OO__OO__,OO__OO_O,OO__OOO_,OO__OOOO,
    OO_O____,OO_O___O,OO_O__O_,OO_O__OO,OO_O_O__,OO_O_O_O,OO_O_OO_,OO_O_OOO,
    OO_OO___,OO_OO__O,OO_OO_O_,OO_OO_OO,OO_OOO__,OO_OOO_O,OO_OOOO_,OO_OOOOO,
    OOO_____,OOO____O,OOO___O_,OOO___OO,OOO__O__,OOO__O_O,OOO__OO_,OOO__OOO,
    OOO_O___,OOO_O__O,OOO_O_O_,OOO_O_OO,OOO_OO__,OOO_OO_O,OOO_OOO_,OOO_OOOO,
    OOOO____,OOOO___O,OOOO__O_,OOOO__OO,OOOO_O__,OOOO_O_O,OOOO_OO_,OOOO_OOO,
    OOOOO___,OOOOO__O,OOOOO_O_,OOOOO_OO,OOOOOO__,OOOOOO_O,OOOOOOO_,OOOOOOOO,
};

//!< Build a byte image
#define G8(n0) ((uint8_t) (n0))

//!< Build a halfword image
#define G16(n1, n0) ((uint16_t) (((n1) << 8) | (n0)))

//!< Build a word image
#define G32(n3, n2, n1, n0) ((uint32_t) ((G16 ((n3), (n2)) << 16) | G16 ((n1), (n0))))

//!< Build a long image
#define G64(n7, n6, n5, n4, n3, n2, n1, n0) ((uint64_t) ((G32 ((n7), (n6), (n5), (n4)) * 0x100000000lu) | G32 ((n3), (n2), (n1), (n0))))

#endif