#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Raingod's robe","��ʦ֮��");
        add("id",({"robe"}) );
        set_short("��ʦ֮��");
	set_long(@C_LONG
һ��͸�����������·�����ȴ�����ޱȣ������޷�����˺������
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "defense_bonus", 5 );
	set( "special_defense",(["cold":-20,"magic":30]));
	set( "value", ({ 1200, "silver" }) );
}
