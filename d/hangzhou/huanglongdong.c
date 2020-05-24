// huanglongdong.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "黄龙洞");
        set("long", @LONG
一进山门，松篁交翠，别有洞天。石壁陡削，苔痕常绿；回廊临
之间有一小峰，上题：“有龙则灵”。
LONG);
        set("exits", ([
            "south"     : __DIR__"shanlu8",
        ]));
        set("objects", ([
            __DIR__"npc/dushe" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", 4090);
	set("coor/y", -1420);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}