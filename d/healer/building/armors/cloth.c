#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Doctor cloth","ҽʦ����");
        add("id",({"cloth"}) );
        set_short("ҽʦ����");
	set_long("������ҽ����ϲ�������·�, �����ܹ���ů֮��, ��\n"
	         "Ҳ����ҽ����ݵ����硣\n");
	set( "unit", "��" );
	set( "weight", 80 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 17 );
	set( "defense_bonus", 5 );
	set( "value", ({ 1800, "silver" }) );
	set("no_sale",1);
}
