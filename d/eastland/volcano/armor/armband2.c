#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith armband", "����ۻ�");
        add( "id", ({ "armband" }) );
        set_short("����ۻ�");
        set_long(
                "����ۻ����Ǿ�����ʦ�������Ա�ѩ�������ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






