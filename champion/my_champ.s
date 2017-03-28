.name		"bouh"
.comment	"allo"

	live %0
start: sti r1, %:live, %1
wall: st r8,-400
    fork %:live
    live %42
	fork %:loader
	live %42
	fork %:attak
live:	live %0
	ld %0, r10
	zjmp %:start
loader: live %42
    ld %:live,r2
    ld %-6,r3
    ld %:wall,r4
    ld %-9,r6
    ld %:zlive,r9
add: live %42
    add r2,r4,r5
    add r5,r2,r5
    add r5,r3,r5
    add r5,r2,r5
    add r5,r6,r5
    add r2,r9,r12
big: ld %0,r15
    st r5,10
    fork %0
    live %42
    sti r12,r12,%20
    ld %0,r15
    zjmp %:big
fork: fork %0
	live %0
	zjmp %-1
attak: lfork %1024
    live %42
    lfork %2048
    live %42
    lfork %3072
    live %42
    lfork %4096
    live %42
    zjmp %:attak
zlive: zjmp %:live
