#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("broken cloth","���");
        add("id",({"cloth"}) );
        set_short("���");
	set_long(@C_LONG
����һ���������õ��·�, ������·�����Ľ᲻�¼�ǧ��,����һ�ɺ������˹�
��, ����һ����׼����ؤװ����
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set("special_defense",
	     (["fire":-10]) );
	set( "value", ({ 500, "silver" }) );
}
