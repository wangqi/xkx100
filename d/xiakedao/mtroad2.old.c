// mtroad2.c  树林

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这里是茂密的森林。四周都是数不清的长草，一股阴森恐怖的
气氛。远处不时传来野兽的嚎叫，你实在不想在这里多留。
LONG );
        set("outdoors", "motianya");
        set("exits", ([
            "east"  : __DIR__"mtroad1",
            "west"  : __FILE__,
            "south" : __FILE__,
            "north" : __DIR__"mtroad3",
        ]));
        set("objects", ([
            __DIR__"npc/zhangsan" : 1,
            __DIR__"npc/lisi" : 1,
        ]));
	set("coor/x", -2000);
	set("coor/y", -1600);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}