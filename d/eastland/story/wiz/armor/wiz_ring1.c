#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("The Archmaster's ring","����ʦ����");
        add( "id", ({ "ring" }) );
        set_short( "����ʦ����");
        set_long(@C_LONG
һֻ��Ө��͸��ʱ��ҫ��������ƵĽ�ָ��
C_LONG
        );
        set( "unit","ֻ");
        set( "type", "finger" );
        set( "material","element");
        set( "defense_bonus", 5 );
        set( "weight", 1 );
        set( "value", ({ 1500, "silver" }) );
        set("special_defense",
             (["magic":30,"divine":-60]) );
}



