#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("phenix longsword","��˳���");
	add ("id",({ "sword","longsword" }) );
        set_short("��˳���");
	set_long(@C_LONG
һ��ͨ�弫���������������������ϼ����о�������������������һ�����ָ���
���Կ�˵�Ǳ�������õ�ѡ�񡣷�˳����򽣱��Ͽ���һֻ��˶��������񹤾���
����˵��ʵսʱ������ԼԼ����һֻ�׶�Ļ����������ϣ����Ը����˲���Ķ�
�����á�
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("longblade", 25,20,35);
	set( "weight", 70 );
	set( "no_sale", 1);
	set( "value", ({ 1730, "silver" }) );
}

