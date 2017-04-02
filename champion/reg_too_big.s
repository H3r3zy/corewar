.name "zork"
.comment "basic live program"

l2:
sti r17,23,%:live
ld 27,r3
and r1,%0,r1
live: live %1
zjmp %:live
