#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("rainbow cloth","�߲�����");
        add("id",({"cloth"}) );
        set_short("�߲�����");
	set_long(@C_LONG
�����ò������·�,����������ɫ������ӳ,ɷ�Ǻÿ���
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus", 6 );
	set( "value", ({ 1500, "silver" }) );
}
