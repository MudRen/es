#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name("heavy iron sword","�����ؽ�");
	add ("id",({ "sword"}) );
        set_short("�����ؽ�");
	set_long(@C_LONG
����һ��ͨ���ֺڵ����ͱ����������ؽ��Ľ����������������Ҳ�����ᾫϸ
��������Ĳ�����˳�֣������������ǿ��ɫ��ʯ�����꣬���͡�����ѩ��ƾ��
��һ�������ؽ���齭���޵��֣����ֵ��¹���ֱ�ǽ��˷�����˼��
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("longblade", 35,20,30);
	set( "weight", 100 );
	set( "value", ({ 5000, "silver" }) );
}

