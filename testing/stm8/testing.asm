.stm8

main:
  break
  halt
  sim

  clrw x
  clrw y

  or A, #$55
  or A, $55
  or A, $1000
  or A, asdf
  xor A, (X)
  or A, (Y)

  and A, ($10, X)
  and A, ($1000, X)
  and A, ($10, Y)
  and A, ($1000, Y)
  and A, ($10, SP)
  and A, [$10]
  and A, [$1000]
  and A, ([$10],X)
  and A, ([$1000],X)
  and A, ([$10],Y)

asdf:
  bset $1000, #1
  bres $1000, #2
  bcpl $1000, #3
  bccm $1000, #4
  btjt $1000, #5, asdf
  btjf $1000, #6, asdf
  jrc asdf

  mul x,a
  mul y,a
  div x,a
  div y,a

  divw x,y
  exgw x,y

  swap a
  swap (x)
  swap $10
  swap $1000
  swap ($10,x)
  swap ($1000,x)
  swap ($10,y)
  swap ($1000,y)
  swap ($10,sp)
  swap [$10]
  swap [$1000]
  swap ([$10], X)
  swap ([$1000], X)
  swap ([$10], Y)


