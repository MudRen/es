#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind cloth","������");
        add("id",({"cloth"}) );
        set_short("������");
	set_long(@C_LONG
һ�������ƶ�Ĵ���ɫ�·��������ò�˿��֯���ɵģ���������Щ͸����
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 15 );
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}
