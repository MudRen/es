#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("beast plate","������������");
    add("id",({"plate","mail"}) );
    set_short( "beast plate","������������");
	set_long(
		"This is a plate called best_plate....\n",
		"������һ�ֽС�⥵�����Ƥ�Ƴɵ�ս�ף���������ƤӲ��ʯ������\n"
		"���ͣ�ֻ���Ȱ���צ����ȥѪ����ܵ�Ƥ�������׿����޼�֮����\n"
	);
    set( "no_sale",1);
	set( "unit", "��" );
	set( "weight", 350 );
	set( "type", "body" );
	set( "armor_class", 38 );
        set("material","leather");
	set( "defense_bonus", 6 );
	set( "value", ({ 275, "gold" }) );
}
