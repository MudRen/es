#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("ice-ghost ring","ѩ����ָ");
        add( "id", ({ "ring" }) );
        set_short("ѩ����ָ");
        set_long(@C_LONG
һֻǧ�꺮���ᾧ�ɵĽ�ָ���ζ�������ղ���ʹ֮�ۻ���
C_LONG
        );
        set( "unit","ֻ");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 10 );
        set( "value", ({ 1000, "silver" }) );
        set("extra_stats",(["dex":-1]));
        set("extra_skills",(["meditate":10]));
}



