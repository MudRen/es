#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("wind cloth","���ư���");
        add("id",({"cloth"}) );
        set_short("���ư���");
	set_long(@C_LONG
���ư���������˷��Ƿ���ȥ����������Ȼ��˿��֯���ɵ�,����������һ��Ƭ���ƶ�
�����ġ���Ϊ��˿��Ʒ,���Զ�춷��������������һ��ȱ�ݡ�
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 32 );
	set( "defense_bonus",3 );
	set("special_defense",
	     (["fire":-20,"cold":10]) );
	set( "value", ({ 4800, "silver" }) );
	set("no_sale",1);
}
