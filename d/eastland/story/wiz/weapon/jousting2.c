#include <mudlib.h>
inherit WEAPON;

void create()
{
	set_name("golden jousting","�ƽ�ǹ");
	add ("id",({ "jousting"}) );
        set_short("�ƽ�ǹ");
	set_long(@C_LONG
����һ��ȫ����ɫ�ĳ�ǹ���ƽ�ǹ�ǡ����̹�����׼��������Ҳֻ�С����̹���
�Ż��ûƽ�������������
C_LONG
	);
	set( "unit", "��" );
        setup_weapon("jousting", 30,15,33);
	set( "weight", 150 );
	set( "value", ({ 2000, "silver" }) );
}

