#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("doctor cloth","ҽ��֮��");
        add("id",({"cloth"}) );
        set_short("ҽ��֮��");
	set_long(@C_LONG
���ǡ�һ����ҽ Сѩ�ӡ�������·�����Ȼ�������˼�����, ���ҷ�첹����
������,����һ�����ͻᱻ˺��ϡ����, �������Сѩ����ȥ��ʦ������, ������
���쳣���
C_LONG	         );
	set( "unit", "��" );
	set( "weight",110 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 35 );
	set( "defense_bonus", 8 );
	set("special_defense",
	     (["fire":-10,"poison":15,"acid":10]) );
	set( "value", ({ 4000, "silver" }) );
}
