#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("God Longsword","���ɽ�");
	add ("id",({ "longsword","sword","god" }) );
        set_short("���ɽ�");
	set_long(@C_LONG
���ɽ���Ϊͨ���������������������Ŀڱ���֮һ���˽���������, ���ס���,
����һ��,�δ������������,Ҳ���ӵô��ѡ� ��������,�޴˱���:����ͭ������
�Ǹ�,��������ɽ�²ء� ���������ߵ���,����ˮ����â? ������,¾����,����
��������;���ɱ仯������,��������ѪȾ�ѡ���
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("longblade", 35,28,42);
	set( "weight", 150 );
	set( "no_sale", 1);
        set( "second", 1);
	set( "value", ({ 3410, "silver" }) );
        set("hit_func","my_damage");
}
