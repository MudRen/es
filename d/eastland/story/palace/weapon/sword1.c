#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("green sword","太乙青霜剑");
	add ("id",({ "sword"}) );
        set_short("太乙青霜剑");
	set_long(@C_LONG
传说青霜剑是几千年前黄帝大战蚩尤时在昆吾山中所得到的铜石打造而成的。铜石
本身原是像火一样的东西，不但赤红，又带著极高的温度。可是，当宝剑铸成之後
，却变成青色，寒光四射，有如水晶般的透明，剑身更是削铁如泥，威力极大！後
来，黄帝的军队因它而打败了蚩尤，功不可没。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("shortblade", 25,15,22);
	set( "weight", 50 );
	set( "value", ({ 1000, "silver" }) );
}

