#include <mudlib.h>
inherit WEAPON;

void create()
{
      set_name( "jin-gu staff", "金箍棒");
        add ("id",({ "staff"}) );
     set_short( "jin-gu staff", "金箍棒");
        set("unit", "把");
        set_long(
            "",@C_LONG
这是一把浑身上下都闪着金光的兵器，只要你看它一眼，就觉得浑身哆嗦，
据说它本来是东海的一根定海神针，后来被齐天大圣当做武器了
棒上用红笔写着：如意金箍棒，重一百八十万公斤
C_LONG
        );
        set( "weapon_class", 45);
        set( "type", "bo");
        set( "min_damage", 25);
        set( "max_damage", 47);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 3800, "silver" }) );
}
