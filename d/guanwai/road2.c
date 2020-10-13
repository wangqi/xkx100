// /guanwai/road2.c
inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这里是通往关外的官道，几米宽的大道，全部由黄土铺成，可并行
三四辆马车而不显拥挤。这里是进出关口的必经之路，路上三俩成群的
行人都是往来贩运皮货，药材的生意人。偶尔有身着官兵骑马飞驰而过。
LONG );
	set("exits", ([
		"northeast" : __DIR__"road3",
		"southwest" : __DIR__"road1",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6010);
	set("coor/y", 5110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}