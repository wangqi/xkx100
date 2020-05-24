// /kaifeng/jiaomen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "角门");
	set("long", @LONG
在墙角边开的一个小门，供寺中的僧人就近出外。门是用松木作的，
原先的红漆已经剥落得差不多了。一边的围墙蹋了半边，寻常人都能爬
进来，南边是片菜地，出了角门是条大街。
LONG
	);
	set("objects", ([
		__DIR__"npc/zhangsan" : 1,
	]));

	set("exits", ([
		"south" : __DIR__"caidi5",
		"north" : __DIR__"eroad0",
	]));
	set("outdoors", "xiangguosi");

	setup();
	replace_program(ROOM);
}
