// nuomi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("糯米烧卖", ({"nuomi shaomai", "shaomai" }) );
	set_weight(50);//一两
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 20);
		set("food_remaining", 1);
		set("food_supply", 40);
	}
	setup();
}
