#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding lace", "��ɫ����ͷɴ");
        add( "id", ({ "lace" }) );
        set_short( "a wedding lace", "��ɫ����ͷɴ");
        set_long(
                "A white wedding lace .\n",
		 "�����ô��׵���˿���ɵ�����ͷɴ�����滹׺�������ɫ��õ�塣\n"
        );
        set("unit","��");
        set("material","cloth");
        set( "type", "head" );
        set( "armor_class", 8 );
        set( "defense_bonus", 0 );
        set( "weight", 10 );
	set( "no_sale",1);
        set( "value", ({ 1800, "silver" }) );
}



