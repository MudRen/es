#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("orb ring", "�ؾ�ˮ����ָ");
        add( "id", ({ "ring" }) );
        set_short( "�ؾ�ˮ����ָ");
        set_long(
                "һֻˮ����ָ���Ӻܾ�ǰ�������ǵؾ�����Ժ��ϯ�����\n"
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set("material","element");
        set( "armor_class", 0 );
        set( "defense_bonus", 10 );
        set( "weight", 15 );
        set("no_sale",1) ;
        set( "value", ({ 1600, "gold" }) );
}



