cs:c s
s:ryan_cs.h ryan_s.c s.c
	gcc s.c -o s -include ryan_cs.h ryan_s.c
c:ryan_cs.h ryan_c.c c.c
	gcc c.c -o c -include ryan_cs.h ryan_c.c
