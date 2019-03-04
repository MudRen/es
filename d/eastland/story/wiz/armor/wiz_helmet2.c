#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("medicine hat","药师护头");
        add( "id", ({ "hat" }) );
        set_short("药师护头");
        set_long(@C_LONG
一件用白麻做的类似山的形状的头带。这头带上涂有防毒防酸的药材，唯一的缺点
是不防火。
C_LONG
        );
        set( "unit","顶");
        set( "type", "head" );
        set( "material","healer");
        set( "armor_class",7 );
        set( "defense_bonus",4);
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set("special_defense",
             (["evil":20,"poison":20,"fire":-20,"cold":-20]) );
}



