#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "sword", "����" );
	set_short( "������֮��" );
	set_long(@CLONG
����Ү�������ҼҴ��ı�����Ҳ����������ǰҮ���������������ŵ��
��½ʱ��ʹ�õ��彣������Կ��������Ͽ�������Ү�������ҵ�ʨ����
ͼ�ƣ������ϵĺ���ʹ�㼸����ʼ������
CLONG
       	        );
	set( "unit", "��" );
	set( "weapon_class", 44 );
	set( "type", "longblade" );
	set( "min_damage", 27 );
	set( "max_damage", 50 );
	set( "nosecond", 1 );
	set( "weight", 180 );
	set( "value", ({ 7000, "gold" }) );
	set( "no_sale", 1 );
}
