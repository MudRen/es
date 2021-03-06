#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "black camisole","黑色紧身衣" );
        add( "id", ({ "black camisole","camisole" }) );
        set_short( "黑色紧身衣" );
        set_long(
 "一套黑色的紧身衣，看来给身裁曼妙的女贼穿是最适合不过的了。\n"
        );
        set( "unit", "领" );
        set("material","thief");
        set( "type", "body" );
	set( "armor_class", 33 );
	set( "defense_bonus", 5 );
        set( "weight", 90 );
        set( "value", ({ 1500, "silver" }) );
	set( "extra_skills", ([ "backstab" :10 , "sneak" :-15 ]) );
        set( "special_defense",(["evil":10,   "fire":-15,]));

}

int stop_equip()
{	
        if ((string)this_player()->query("gender") != "female")
        {
                tell_object(this_player(),@LONG
你拼命想要穿上这件剪裁精美的紧身衣，却发现自己该凸的地方不凸，
该凹的地方不凹，穿起来有够难看，一气之下就把衣服给撕烂了。
LONG
                );
        call_out( "tear_cloth", 2 );
        return 1;
        }
      return 0;
}

void tear_cloth()
{
   this_object()->remove();
}
