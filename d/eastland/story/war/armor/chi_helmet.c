#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's helmet","���ս��");
        add("id",({"helmet"}) );
        set_short("���ս��");
	set_long(@C_LONG
һ���ò��Ϸ��ƶ��ɵĻ�ͷ��������˼�����ë���е���ӡ�ذ���ͷ�ϴ��Ķ�����
C_LONG	         );
	set( "unit", "��" );
	set( "weight",60 );
	set( "type", "head" );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "value", ({ 1000, "silver" }) );
}
