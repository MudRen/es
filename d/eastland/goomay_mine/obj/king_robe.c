#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "king robe", "��ȸ����" );
	add( "id", ({ "robe", }) );
	set_short( "��ȸ����");
	set_long(@C_LONG
�������ǿ�ȸ�����Ĵ���֮����������������������ۣ��ڵǻ����ʱ
��������ķ�����������������ǵ�ף���������ڿ�ȸ���������ᣬ��
�Բ�֪���۵�ȥ��		
C_LONG
	);
	set( "unit", "��" );
	set( "weight", 120 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 35 );
	set( "defense_bonus", 5 );
	set( "value", ({ 2000, "silver" }) );
}