#include "../island.h"

inherit ARMOR;

void create()
{
    set_name("Hai-nen pallium","��������");
    add("id",({"cloth","pallium"}) );
    set_short("@@color");
	set_long(@C_LONG
�����洫���������ģ���Ȼ�����Զ��������Ȼ���Գ¾ɵ����ӣ���춾���
�����̳и�ɮ�ļӳ֣�ʹ��������ľ�����ʥ�ķ������� ( Odin,Inc )	
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "body" );
	set( "armor_class", 36 );
        set("material","cloth");
        set("special_defense",(["evil" : 10,
                                "fire" : 30,
                               "mental": 30,
                                "acid" : -10
                                           ]));
	set( "defense_bonus", 10 );
	set( "value", ({ 1200, "silver" }) );
	set( "no_sale", 1 );
	
}
string color()
  { return set_color("��������","HIC"); } 