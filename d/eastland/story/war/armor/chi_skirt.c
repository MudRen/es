#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's skirt","��Ȱ���");
        add("id",({"skirt"}) );
        set_short("��Ȱ���");
	set_long(@C_LONG
һ���ò��Ϸ��ƶ��ɵĻ��ߣ�����մ�������Ѫ�գ������������������һ��ķ�
�ţ����������������ÿɱ����˵ı��
C_LONG	         );
	set( "unit", "��" );
	set( "weight",60 );
	set( "type", "legs" );
        set("material","cloth");
	set( "defense_bonus", 1 );
	set( "value", ({ 1000, "silver" }) );
}
