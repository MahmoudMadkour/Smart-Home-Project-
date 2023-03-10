#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)     REG|=(1<<BIT)
#define GET_BIT(REG,BIT)     ((REG>>BIT)&1)
#define CLEAR_BIT(REG,BIT)   REG&=~(1<<BIT)
#define TOGGLE(REG,BIT)      REG^=(1<<BIT)

#endif /* BIT_MATH_H */
