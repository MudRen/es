#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("lucky ring", "���˽�ָ");
   add( "id", ({ "ring" }) );
        set_short( "���˽�ָ" );
        set_long(
@C_LONG
����һֻ�ɰ������µĽ�ָ������һ��СС����䣬���ҵ�̵���
С���ӵı�־��
C_LONG
        );
        set( "unit", "ֻ");
        set( "type", "finger" );
        set( "material","thief" );
        set( "extra_stats",([ "pie" : -1 ]) );
   set( "extra_skills", ([ "steal" : 10 ]) );
        set( "defense_bonus", 2 );
        set( "special_defense",
          ([ "cold": 40, "fire" : -50 ]) );
        set( "weight", 7 );
        set( "value", ({ 410, "gold" }) );
        set( "no_sale", 1);
}
