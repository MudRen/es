#include <mudlib.h>;

inherit WEAPON;

void create()
{
    set_name("Jade ru_i","������");
    add("id", ({ "mace","ru_i","jade ru_i" }) );
    set_short("������");
    set_long(@LONG
һ��ͨ���ɺ�����֬�����Ƴɵ����⡣���ⳤһ������磬͸ɢ��ֻ���ϵ���ʯ��
��Բ����͵Ĺ�â�������ν�����һֻ��˵�ͼ������ɫ����������ɣ������
�֣��˵����ɶ��칤��Ψ��ΨФ��
LONG);
    set( "unit", "��" );
    set( "weight", 70 );
    setup_weapon("blunt", 35,10,10);
    set( "value", ({ 300, "gold" }) );
}
