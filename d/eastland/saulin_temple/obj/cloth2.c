#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("gold pallium","紫罗架裟");
    add("id",({ "cloth", "pallium" }) );
    set_short("紫罗架裟");
	set_long(@C_LONG
这是一件用紫蚕丝所织成并滚上金边的架裟，是当年东方帝国开国皇帝赐给
一十三位有功於帝国开国大业，又不愿入朝为官的寺僧之礼。
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 90 );
	set( "type", "body" );
        set("material","monk");
	set( "armor_class", 35 );
	set( "defense_bonus", 5 );
	set( "value", ({ 190, "gold" }) );
}
