#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's cloth","���ս��");
        add("id",({"cloth"}) );
        set_short("���ս��");
	set_long(@C_LONG
һ���ò��Ϸ��ƶ��ɵĻ��ߣ�����մ�������Ѫ�գ�ǰ�滹����һ����ɫ�Ĵ�����
ͷ��
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set( "material","cloth");
	set( "armor_class",20);
	set( "defense_bonus", 4 );
	set( "value", ({ 1000, "silver" }) );
}
