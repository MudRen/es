#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("scholar hood", "�ڽ�");
        add( "id", ({ "hood" }) );
        set_short("�ڽ�");
        set_long(
                "����ѧ�ߴ���ͷ���ഫ���ʦ���������������μӳ��֮ս�� \n"
                "̸Ц�䣬ǿ²�ҷ������㲻����Ȼ����.......\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "scholar");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "magic":5,"mental":2 ]) );
        set( "weight", 50 );
        set( "value", ({ 566, "gold" }) );
}



