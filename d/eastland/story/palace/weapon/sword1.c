#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("green sword","̫����˪��");
	add ("id",({ "sword"}) );
        set_short("̫����˪��");
	set_long(@C_LONG
��˵��˪���Ǽ�ǧ��ǰ�Ƶ۴�ս���ʱ������ɽ�����õ���ͭʯ������ɵġ�ͭʯ
����ԭ�����һ���Ķ�����������죬�ִ������ߵ��¶ȡ����ǣ�����������֮��
��ȴ�����ɫ���������䣬����ˮ�����͸������������������࣬����������
�����Ƶ۵ľ����������������ȣ�������û��
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("shortblade", 25,15,22);
	set( "weight", 50 );
	set( "value", ({ 1000, "silver" }) );
}

