l2:
sti r2,23,%:live
ld 27,r3
and r1,%0,r1
live: live %1
zjmp %:live
