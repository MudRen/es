#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "claw of sigh", "̾Ϣ֮צ" );
	add( "id", ({ "claw", "claws" }) );
	set_short( "̾Ϣ֮צ" );
	set_long(@C_LONG
����һ˫�ǳ�������צ�ӣ�צ�����ɲ�֪��������ɫ�����Ƴ�
�Ӳ�ͬ�ĽǶȷ����������ɫ�ʣ��ڻ��ֵĵط�������������
���̱�ʯ������������Ϣ���ѹ����������˽�������Ϊ̾Ϣ֮
צ��������Ϊ��������̾Ϣ�����˸�Ϊ���ļ�ֵ��̾Ϣ��	
C_LONG
	);
	set( "unit", "��" );
	set( "type", "unarmed" );
	set( "weapon_class", 30 );
	set( "min_damage", 20 );
	set( "max_damage", 43 );
	set( "second", 1 );
	set( "weight", 50 );
	set( "value", ({ 15420, "silver" }) );
	set( "bleeding", 17 );

	set_c_verbs( ({ "��%s��%sһץ","һ��ת������%s��%sһ��",
	        "%s����һ��Ư�������⣬ɨ��%s", 
		"��%s����һ������̾������������%s��ȥ" }) );
}
